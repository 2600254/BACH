#include "BACH/cypher/parser/cypher_parser.h"
#include "BACH/cypher/parser/ast_visitor.h"

namespace BACH {
namespace cypher {

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
