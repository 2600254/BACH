#pragma once

#include "ast.h"
#include "clause.h"
#include "expression.h"
#include <string>
#include <memory>

namespace BACH {
namespace cypher {

// Simple Cypher Parser
// Parses Cypher query strings into AST
class CypherParser {
public:
    CypherParser();
    ~CypherParser();

    // Parse Cypher query string, returns AST
    // Returns nullptr on parse failure
    std::unique_ptr<Query> Parse(const std::string& query);

    // Get last error message
    std::string GetLastError() const { return last_error; }

private:
    std::string last_error;
    size_t pos;
    std::string query;

    // Token handling
    void SkipWhitespace();
    char Peek() const;
    char Get();
    bool Match(const std::string& s);
    std::string ReadIdentifier();
    std::string ReadString();

    // Parsing methods
    std::unique_ptr<MatchClause> ParseMatchClause();
    std::unique_ptr<ReturnClause> ParseReturnClause();
    std::unique_ptr<CreateClause> ParseCreateClause();
    std::unique_ptr<DeleteClause> ParseDeleteClause();
    std::unique_ptr<SetClause> ParseSetClause();
    std::unique_ptr<PathPattern> ParsePattern();
    std::unique_ptr<NodePattern> ParseNodePattern();
    std::unique_ptr<RelationshipPattern> ParseRelationshipPattern();
};

} // namespace cypher
} // namespace BACH
