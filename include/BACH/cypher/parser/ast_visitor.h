#pragma once

#include "ast.h"
#include "clause.h"
#include "expression.h"

namespace BACH {
namespace cypher {

// AST 访问者接口（Visitor 模式）
// 用于遍历和分析 AST，或在 AST 构建过程中填充数据结构
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;

    // 语句访问
    virtual void Visit(Query& node) { (void)node; }

    // 子句访问
    virtual void Visit(MatchClause& node) { (void)node; }
    virtual void Visit(WhereClause& node) { (void)node; }
    virtual void Visit(ReturnClause& node) { (void)node; }
    virtual void Visit(CreateClause& node) { (void)node; }
    virtual void Visit(DeleteClause& node) { (void)node; }
    virtual void Visit(SetClause& node) { (void)node; }

    // 表达式访问
    virtual void Visit(Literal& node) { (void)node; }
    virtual void Visit(Variable& node) { (void)node; }
    virtual void Visit(Property& node) { (void)node; }
    virtual void Visit(BinaryOp& node) { (void)node; }
    virtual void Visit(UnaryOp& node) { (void)node; }
    virtual void Visit(FunctionCall& node) { (void)node; }
    virtual void Visit(CaseExpression& node) { (void)node; }
    virtual void Visit(ListExpression& node) { (void)node; }
    virtual void Visit(MapExpression& node) { (void)node; }

    // 模式访问
    virtual void Visit(PatternElement& node) { (void)node; }
    virtual void Visit(NodePattern& node) { (void)node; }
    virtual void Visit(RelationshipPattern& node) { (void)node; }
    virtual void Visit(PathPattern& node) { (void)node; }
};

} // namespace cypher
} // namespace BACH
