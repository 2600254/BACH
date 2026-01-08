#pragma once

#include "ast.h"
#include <string>
#include <vector>
#include <memory>

namespace BACH {
namespace cypher {

// 前向声明
class ASTVisitor;

// ============================================================================
// 表达式基类
// ============================================================================
class Expression : public ASTNode {
public:
    explicit Expression(ASTNodeType type) : ASTNode(type) {}
    virtual ~Expression() = default;

    // 获取表达式的数据类型（推导后）
    DataType data_type = DataType::UNKNOWN;
};

using ExpressionPtr = std::unique_ptr<Expression>;

// ============================================================================
// 字面量表达式
// ============================================================================
class Literal : public Expression {
public:
    explicit Literal(const Value& value) : Expression(ASTNodeType::LITERAL), value(value) {}

    void Accept(ASTVisitor& visitor) override;

    Value value;
};

// ============================================================================
// 变量表达式（如: n, p, rel）
// ============================================================================
class Variable : public Expression {
public:
    explicit Variable(const std::string& name) : Expression(ASTNodeType::VARIABLE), name(name) {}

    void Accept(ASTVisitor& visitor) override;

    std::string name;
    size_t scope_id = 0;  // 作用域 ID
};

// ============================================================================
// 属性访问表达式（如: n.name, p.age）
// ============================================================================
class Property : public Expression {
public:
    Property(ExpressionPtr expr, const std::string& prop_name)
        : Expression(ASTNodeType::PROPERTY), expr(std::move(expr)), prop_name(prop_name) {}

    void Accept(ASTVisitor& visitor) override;

    ExpressionPtr expr;   // 被访问的表达式（通常是变量）
    std::string prop_name; // 属性名
};

// ============================================================================
// 二元操作符（如: a + b, x > 5, n.name = 'Alice'）
// ============================================================================
enum class BinaryOpType {
    // 算术运算
    ADD, SUB, MUL, DIV, MOD,
    // 比较运算
    EQ, NEQ, LT, LTE, GT, GTE,
    // 逻辑运算
    AND, OR, XOR,
    // 字符串匹配
    STARTS_WITH, ENDS_WITH, CONTAINS,
    // 其他
    IN, IS_NULL
};

class BinaryOp : public Expression {
public:
    BinaryOp(BinaryOpType op_type, ExpressionPtr left, ExpressionPtr right)
        : Expression(ASTNodeType::BINARY_OP), op_type(op_type),
          left(std::move(left)), right(std::move(right)) {}

    void Accept(ASTVisitor& visitor) override;

    BinaryOpType op_type;
    ExpressionPtr left;
    ExpressionPtr right;
};

// ============================================================================
// 一元操作符（如: -n, NOT exists)
// ============================================================================
enum class UnaryOpType {
    NEGATE,    // 算术取负
    NOT,       // 逻辑取反
    IS_NULL    // 判空
};

class UnaryOp : public Expression {
public:
    UnaryOp(UnaryOpType op_type, ExpressionPtr expr)
        : Expression(ASTNodeType::UNARY_OP), op_type(op_type), expr(std::move(expr)) {}

    void Accept(ASTVisitor& visitor) override;

    UnaryOpType op_type;
    ExpressionPtr expr;
};

// ============================================================================
// 函数调用（如: id(n), labels(p), count(*)）
// ============================================================================
class FunctionCall : public Expression {
public:
    FunctionCall(const std::string& func_name, std::vector<ExpressionPtr> args)
        : Expression(ASTNodeType::FUNCTION_CALL),
          func_name(func_name), args(std::move(args)) {}

    void Accept(ASTVisitor& visitor) override;

    std::string func_name;
    std::vector<ExpressionPtr> args;
    bool is_aggregate = false;  // 是否是聚合函数
};

// ============================================================================
// CASE 表达式
// ============================================================================
class CaseExpression : public Expression {
public:
    struct CaseBranch {
        ExpressionPtr condition;
        ExpressionPtr result;
    };

    CaseExpression(std::vector<CaseBranch> branches, ExpressionPtr else_result)
        : Expression(ASTNodeType::CASE_EXPR),
          branches(std::move(branches)), else_result(std::move(else_result)) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<CaseBranch> branches;
    ExpressionPtr else_result;  // 可空
};

// ============================================================================
// 列表表达式（字面量列表）
// ============================================================================
class ListExpression : public Expression {
public:
    explicit ListExpression(std::vector<ExpressionPtr> elements)
        : Expression(ASTNodeType::LIST_EXPR), elements(std::move(elements)) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<ExpressionPtr> elements;
};

// ============================================================================
// Map/属性列表表达式（如: {name: 'Alice', age: 30}）
// ============================================================================
class MapExpression : public Expression {
public:
    struct MapEntry {
        std::string key;
        ExpressionPtr value;
    };

    explicit MapExpression(std::vector<MapEntry> entries)
        : Expression(ASTNodeType::MAP), entries(std::move(entries)) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<MapEntry> entries;
};

} // namespace cypher
} // namespace BACH
