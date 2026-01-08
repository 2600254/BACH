#pragma once

#include "data_type.h"
#include <memory>
#include <vector>
#include <string>

namespace BACH {
namespace cypher {

// 前向声明
class ASTVisitor;
class ASTNode;

// AST 节点类型枚举
enum class ASTNodeType {
    // 查询语句
    QUERY,

    // 子句类型
    MATCH_CLAUSE,
    WHERE_CLAUSE,
    RETURN_CLAUSE,
    CREATE_CLAUSE,
    DELETE_CLAUSE,
    SET_CLAUSE,
    MERGE_CLAUSE,

    // 表达式类型
    LITERAL,
    VARIABLE,
    PROPERTY,
    BINARY_OP,
    UNARY_OP,
    FUNCTION_CALL,
    AGGREGATE,
    CASE_EXPR,
    LIST_COMPREHENSION,
    MAP,
    LIST_EXPR,

    // 模式类型
    PATTERN,
    NODE_PATTERN,
    RELATIONSHIP_PATTERN,
    PATH_PATTERN,
    PATTERN_ELEMENT,

    // 其他
    PARAMETER,
    IDENTIFIER
};

// AST 节点基类
class ASTNode {
public:
    explicit ASTNode(ASTNodeType type) : node_type(type) {}
    virtual ~ASTNode() = default;

    ASTNodeType GetNodeType() const { return node_type; }

    // 访问者模式
    virtual void Accept(ASTVisitor& visitor) = 0;

    // 位置信息（用于错误报告）
    size_t line = 0;
    size_t column = 0;

protected:
    ASTNodeType node_type;
};

// AST 节点智能指针类型
using ASTNodePtr = std::unique_ptr<ASTNode>;

// 语句（完整的 Cypher 查询）
class Query : public ASTNode {
public:
    Query() : ASTNode(ASTNodeType::QUERY) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<ASTNodePtr> clauses;  // 查询中的子句序列
};

} // namespace cypher
} // namespace BACH
