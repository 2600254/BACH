#include "BACH/cypher/cypher.h"
#include "BACH/cypher/parser/clause.h"
#include <iostream>
#include <iomanip>

using namespace BACH;
using namespace BACH::cypher;

// Helper to print AST
void PrintClause(const ASTNode* clause, int indent = 0) {
    std::string ind(indent * 2, ' ');

    switch (clause->GetNodeType()) {
        case ASTNodeType::MATCH_CLAUSE:
            {
                auto* mc = static_cast<const MatchClause*>(clause);
                std::cout << ind << "MATCH" << std::endl;
                for (const auto& pattern : mc->patterns) {
                    if (pattern->left_node) {
                        std::cout << ind << "  Node: ";
                        if (!pattern->left_node->var_name.empty()) {
                            std::cout << pattern->left_node->var_name;
                        } else {
                            std::cout << "(anonymous)";
                        }
                        if (!pattern->left_node->label.empty()) {
                            std::cout << ":" << pattern->left_node->label;
                        }
                        std::cout << std::endl;
                    }
                    if (pattern->relationship) {
                        std::cout << ind << "  Relationship: ";
                        if (!pattern->relationship->label.empty()) {
                            std::cout << pattern->relationship->label;
                        } else {
                            std::cout << "(any)";
                        }
                        if (pattern->relationship->direction == RelationshipPattern::Direction::RIGHT) {
                            std::cout << " -->";
                        } else if (pattern->relationship->direction == RelationshipPattern::Direction::LEFT) {
                            std::cout << " <--";
                        } else {
                            std::cout << " --";
                        }
                        std::cout << std::endl;
                    }
                    if (pattern->right_node) {
                        std::cout << ind << "  Node: ";
                        if (!pattern->right_node->var_name.empty()) {
                            std::cout << pattern->right_node->var_name;
                        } else {
                            std::cout << "(anonymous)";
                        }
                        if (!pattern->right_node->label.empty()) {
                            std::cout << ":" << pattern->right_node->label;
                        }
                        std::cout << std::endl;
                    }
                }
            }
            break;

        case ASTNodeType::RETURN_CLAUSE:
            {
                auto* rc = static_cast<const ReturnClause*>(clause);
                std::cout << ind << "RETURN";
                if (rc->distinct) std::cout << " DISTINCT";
                std::cout << std::endl;
                for (const auto& item : rc->return_items) {
                    std::cout << ind << "  ";
                    if (auto* var = dynamic_cast<Variable*>(item.expr.get())) {
                        std::cout << var->name;
                        if (!item.alias.empty()) {
                            std::cout << " AS " << item.alias;
                        }
                    }
                    std::cout << std::endl;
                }
            }
            break;

        case ASTNodeType::CREATE_CLAUSE:
            {
                auto* cc = static_cast<const CreateClause*>(clause);
                std::cout << ind << "CREATE" << std::endl;
                for (const auto& pattern : cc->patterns) {
                    if (pattern->left_node) {
                        std::cout << ind << "  Node: ";
                        if (!pattern->left_node->label.empty()) {
                            std::cout << "(" << pattern->left_node->label;
                            if (!pattern->left_node->var_name.empty()) {
                                std::cout << " " << pattern->left_node->var_name;
                            }
                            std::cout << ")";
                        } else {
                            std::cout << "()";
                        }
                        std::cout << std::endl;
                    }
                }
            }
            break;

        default:
            std::cout << ind << "Unknown clause type" << std::endl;
            break;
    }
}

void TestParse(const std::string& query) {
    std::cout << "\nQuery: " << query << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    CypherParser parser;
    auto ast = parser.Parse(query);

    if (!ast) {
        std::cout << "Parse failed: " << parser.GetLastError() << std::endl;
        return;
    }

    std::cout << "Parsed successfully!" << std::endl;
    std::cout << "Clauses: " << ast->clauses.size() << std::endl;

    for (const auto& clause : ast->clauses) {
        PrintClause(clause.get());
    }
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "BACH Cypher Parser Test" << std::endl;
    std::cout << "========================================" << std::endl;

    // Test basic MATCH queries
    TestParse("MATCH (n:Person) RETURN n");
    TestParse("MATCH (n:Person)-[r:KNOWS]->(m:Person) RETURN n, m");
    TestParse("MATCH (n) RETURN n");
    TestParse("MATCH (n:Person {name: 'Alice'}) RETURN n");

    // Test CREATE queries
    TestParse("CREATE (n:Person)");
    TestParse("CREATE (n:Person {name: 'Bob', age: 25})");
    TestParse("CREATE (n:Person)-[r:KNOWS]->(m:Person)");

    // Test RETURN *
    TestParse("MATCH (n) RETURN *");

    // Test DISTINCT
    TestParse("MATCH (n:Person) RETURN DISTINCT n");

    // Test combined queries
    TestParse("MATCH (n:Person) RETURN n LIMIT 10");

    std::cout << "\n========================================" << std::endl;
    std::cout << "All tests completed!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}
