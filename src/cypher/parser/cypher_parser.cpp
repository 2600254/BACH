#include "BACH/cypher/parser/cypher_parser.h"
#include "BACH/cypher/parser/ast_visitor.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <regex>

namespace BACH {
namespace cypher {

// ============================================================================
// Simple Cypher Parser Implementation
// ============================================================================

CypherParser::CypherParser() {
    // Initialize parser state
    pos = 0;
}

CypherParser::~CypherParser() = default;

std::unique_ptr<Query> CypherParser::Parse(const std::string& query_str) {
    query = query_str;
    pos = 0;
    last_error.clear();

    auto result = std::make_unique<Query>();
    SkipWhitespace();

    while (pos < query.size()) {
        if (Match("MATCH")) {
            auto clause = ParseMatchClause();
            if (clause) result->clauses.push_back(std::move(clause));
        } else if (Match("RETURN")) {
            auto clause = ParseReturnClause();
            if (clause) result->clauses.push_back(std::move(clause));
        } else if (Match("CREATE")) {
            auto clause = ParseCreateClause();
            if (clause) result->clauses.push_back(std::move(clause));
        } else if (Match("DELETE")) {
            auto clause = ParseDeleteClause();
            if (clause) result->clauses.push_back(std::move(clause));
        } else if (Match("SET")) {
            auto clause = ParseSetClause();
            if (clause) result->clauses.push_back(std::move(clause));
        } else {
            pos++; // Skip unknown character
        }

        SkipWhitespace();
    }

    if (result->clauses.empty()) {
        last_error = "Failed to parse query";
        return nullptr;
    }

    return result;
}

// ============================================================================
// Token handling
// ============================================================================

void CypherParser::SkipWhitespace() {
    while (pos < query.size() && std::isspace(static_cast<unsigned char>(query[pos]))) {
        pos++;
    }
}

char CypherParser::Peek() const {
    return pos < query.size() ? query[pos] : '\0';
}

char CypherParser::Get() {
    return pos < query.size() ? query[pos++] : '\0';
}

bool CypherParser::Match(const std::string& s) {
    SkipWhitespace();
    std::string lower = s;
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    size_t len = s.length();
    if (pos + len <= query.size()) {
        std::string substr = query.substr(pos, len);
        std::transform(substr.begin(), substr.end(), substr.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (substr == lower) {
            pos += len;
            SkipWhitespace();
            return true;
        }
    }
    return false;
}

std::string CypherParser::ReadIdentifier() {
    SkipWhitespace();
    std::string ident;
    while (pos < query.size() && (std::isalnum(static_cast<unsigned char>(query[pos])) ||
                                  query[pos] == '_')) {
        ident += query[pos++];
    }
    return ident;
}

std::string CypherParser::ReadString() {
    SkipWhitespace();
    if (Peek() != '\'' && Peek() != '"') return "";

    char quote = Get();
    std::string str;
    while (pos < query.size() && query[pos] != quote) {
        if (query[pos] == '\\' && pos + 1 < query.size()) {
            pos++; // Skip escape
        }
        str += query[pos++];
    }
    if (pos < query.size()) pos++; // Skip closing quote
    return str;
}

// ============================================================================
// Parsing methods
// ============================================================================

std::unique_ptr<MatchClause> CypherParser::ParseMatchClause() {
    auto clause = std::make_unique<MatchClause>();

    // Parse pattern
    if (auto pattern = ParsePattern()) {
        clause->patterns.push_back(std::move(pattern));
    }

    // Parse WHERE clause if present (skip for now)
    if (Match("WHERE")) {
        while (pos < query.size() && !Match("RETURN") && !Match("LIMIT") &&
               !Match("ORDER") && !Match("SKIP") && !Match("CREATE") &&
               !Match("DELETE") && !Match("SET")) {
            pos++;
        }
    }

    return clause;
}

std::unique_ptr<ReturnClause> CypherParser::ParseReturnClause() {
    auto clause = std::make_unique<ReturnClause>();

    // Check for DISTINCT
    if (Match("DISTINCT")) {
        clause->distinct = true;
    }

    // Check for *
    SkipWhitespace();
    if (Peek() == '*') {
        Get();
        ReturnItem item;
        item.expr = std::make_unique<Variable>("*");
        clause->return_items.push_back(std::move(item));
        return clause;
    }

    // Parse return items
    do {
        ReturnItem item;
        std::string ident = ReadIdentifier();
        if (!ident.empty()) {
            item.expr = std::make_unique<Variable>(ident);

            // Check for AS alias
            if (Match("AS")) {
                std::string alias = ReadIdentifier();
                item.alias = alias;
            }

            clause->return_items.push_back(std::move(item));
        }
    } while (Match(","));

    return clause;
}

std::unique_ptr<CreateClause> CypherParser::ParseCreateClause() {
    auto clause = std::make_unique<CreateClause>();

    // Parse pattern
    if (auto pattern = ParsePattern()) {
        clause->patterns.push_back(std::move(pattern));
    }

    return clause;
}

std::unique_ptr<DeleteClause> CypherParser::ParseDeleteClause() {
    auto clause = std::make_unique<DeleteClause>();
    clause->detach = false;

    // Check for DETACH
    // (Already consumed "DELETE", check if DETACH was before)
    // For simplicity, assume no DETACH

    do {
        std::string ident = ReadIdentifier();
        if (!ident.empty()) {
            clause->expressions.push_back(std::make_unique<Variable>(ident));
        }
    } while (Match(","));

    return clause;
}

std::unique_ptr<SetClause> CypherParser::ParseSetClause() {
    auto clause = std::make_unique<SetClause>();

    do {
        SetPropertyItem item;
        item.type = SetPropertyItem::SetType::PROPERTY;

        // Read target (variable or property)
        std::string target = ReadIdentifier();
        if (target.empty()) break;

        // Check if it's a property access
        SkipWhitespace();
        if (Peek() == '.') {
            Get();
            std::string prop = ReadIdentifier();
            item.expr = std::make_unique<Property>(std::make_unique<Variable>(target), prop);
        } else {
            item.expr = std::make_unique<Variable>(target);
        }

        // Expect =
        if (!Match("=")) {
            break;
        }

        // Read value (simple literal or variable)
        SkipWhitespace();
        if (Peek() == '\'' || Peek() == '"') {
            std::string str_val = ReadString();
            item.value = std::make_unique<Literal>(Value(str_val));
        } else if (std::isdigit(Peek())) {
            std::string num;
            while (pos < query.size() && (std::isdigit(static_cast<unsigned char>(query[pos])) ||
                                         query[pos] == '.')) {
                num += query[pos++];
            }
            try {
                if (num.find('.') != std::string::npos) {
                    item.value = std::make_unique<Literal>(Value(std::stod(num)));
                } else {
                    item.value = std::make_unique<Literal>(Value(static_cast<int64_t>(std::stoll(num))));
                }
            } catch (...) {
                item.value = std::make_unique<Literal>(Value(static_cast<int64_t>(0)));
            }
        } else {
            std::string var = ReadIdentifier();
            if (var == "true") {
                item.value = std::make_unique<Literal>(Value(true));
            } else if (var == "false") {
                item.value = std::make_unique<Literal>(Value(false));
            } else if (var == "null") {
                item.value = std::make_unique<Literal>(Value());
            } else {
                item.value = std::make_unique<Variable>(var);
            }
        }

        clause->items.push_back(std::move(item));
    } while (Match(","));

    return clause;
}

std::unique_ptr<PathPattern> CypherParser::ParsePattern() {
    auto pattern = std::make_unique<PathPattern>();

    SkipWhitespace();

    // Expect '(' for node pattern
    if (Peek() != '(') {
        return nullptr;
    }

    // Parse first node
    if (auto node = ParseNodePattern()) {
        pattern->left_node = std::move(node);
    }

    // Check for relationship pattern
    SkipWhitespace();
    if (Peek() == '-' || Peek() == '<') {
        if (auto rel = ParseRelationshipPattern()) {
            pattern->relationship = std::move(rel);
        }

        // Parse right node
        if (auto node = ParseNodePattern()) {
            pattern->right_node = std::move(node);
        }
    }

    return pattern;
}

std::unique_ptr<NodePattern> CypherParser::ParseNodePattern() {
    SkipWhitespace();
    if (Peek() != '(') {
        return nullptr;
    }
    Get(); // Consume '('

    auto node = std::make_unique<NodePattern>();

    SkipWhitespace();

    // Check for variable
    std::string ident = ReadIdentifier();
    if (!ident.empty() && ident != ":") {
        node->var_name = ident;
        SkipWhitespace();
    }

    // Check for label
    if (Peek() == ':') {
        Get(); // Consume ':'
        ident = ReadIdentifier();
        node->label = ident;
        SkipWhitespace();
    }

    // Skip properties for now {...}
    if (Peek() == '{') {
        int depth = 1;
        Get();
        while (pos < query.size() && depth > 0) {
            if (query[pos] == '{') depth++;
            else if (query[pos] == '}') depth--;
            pos++;
        }
    }

    if (Peek() == ')') {
        Get(); // Consume ')'
    }

    return node;
}

std::unique_ptr<RelationshipPattern> CypherParser::ParseRelationshipPattern() {
    SkipWhitespace();

    auto rel = std::make_unique<RelationshipPattern>();

    // Check direction
    if (Peek() == '<') {
        rel->direction = RelationshipPattern::Direction::LEFT;
        Get(); // Consume '<'
    }

    // Expect '-'
    if (Peek() != '-') {
        return nullptr;
    }
    Get(); // Consume '-'

    // Check for relationship detail
    if (Peek() == '[') {
        Get(); // Consume '['
        SkipWhitespace();

        // Variable
        std::string ident = ReadIdentifier();
        if (!ident.empty() && ident != ":") {
            rel->var_name = ident;
            SkipWhitespace();
        }

        // Type label
        if (Peek() == ':') {
            Get(); // Consume ':'
            ident = ReadIdentifier();
            rel->label = ident;
            SkipWhitespace();
        }

        // Skip properties
        if (Peek() == '{') {
            int depth = 1;
            Get();
            while (pos < query.size() && depth > 0) {
                if (query[pos] == '{') depth++;
                else if (query[pos] == '}') depth--;
                pos++;
            }
        }

        if (Peek() == ']') {
            Get(); // Consume ']'
        }
    }

    // Expect '-'
    if (Peek() != '-') {
        return nullptr;
    }
    Get(); // Consume '-'

    // Check for outgoing arrow
    if (Peek() == '>') {
        if (rel->direction == RelationshipPattern::Direction::LEFT) {
            rel->direction = RelationshipPattern::Direction::BOTH;
        } else {
            rel->direction = RelationshipPattern::Direction::RIGHT;
        }
        Get(); // Consume '>'
    }

    return rel;
}

// ============================================================================
// ASTVisitor Accept Implementations
// ============================================================================

void Query::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void Literal::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void Variable::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void Property::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void BinaryOp::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void UnaryOp::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void FunctionCall::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void CaseExpression::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void ListExpression::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void MapExpression::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void MatchClause::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void WhereClause::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void ReturnClause::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void CreateClause::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void DeleteClause::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void SetClause::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void NodePattern::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void RelationshipPattern::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void PathPattern::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

void PatternElement::Accept(ASTVisitor& visitor) {
    visitor.Visit(*this);
}

} // namespace cypher
} // namespace BACH
