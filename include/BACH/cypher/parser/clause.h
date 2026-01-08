#pragma once

#include "ast.h"
#include "expression.h"
#include <string>
#include <vector>
#include <memory>

namespace BACH {
namespace cypher {

// 前向声明
class ASTVisitor;

// ============================================================================
// 子句基类
// ============================================================================
class Clause : public ASTNode {
public:
    explicit Clause(ASTNodeType type) : ASTNode(type) {}
    virtual ~Clause() = default;
};

using ClausePtr = std::unique_ptr<Clause>;

// ============================================================================
// MATCH 子句
// ============================================================================

// 图模式元素
class PatternElement : public ASTNode {
public:
    PatternElement() : ASTNode(ASTNodeType::PATTERN) {}

    void Accept(ASTVisitor& visitor) override;

    std::string var_name;      // 变量名（可空，匿名时为空）
    std::string label;         // 标签/类型
    std::vector<ExpressionPtr> properties;  // 属性约束
};

// 节点模式（如: (n:Person {name: 'Alice'})）
class NodePattern : public PatternElement {
public:
    NodePattern() : PatternElement() {
        node_type = ASTNodeType::NODE_PATTERN;
    }

    void Accept(ASTVisitor& visitor) override;
};

// 关系模式（如: -[r:KNOWS {since: 2020}]->）
class RelationshipPattern : public PatternElement {
public:
    RelationshipPattern() : PatternElement() {
        node_type = ASTNodeType::RELATIONSHIP_PATTERN;
    }

    void Accept(ASTVisitor& visitor) override;

    enum class Direction { NONE, LEFT, RIGHT, BOTH };
    Direction direction = Direction::BOTH;
    bool is_variable = false;  // 是否是变长路径（如: -[*1..3]->）
    size_t min_length = 1;
    size_t max_length = 1;
};

// 路径模式（如: (a)-[r]->(b)）
class PathPattern : public ASTNode {
public:
    PathPattern() : ASTNode(ASTNodeType::PATH_PATTERN) {}

    void Accept(ASTVisitor& visitor) override;

    std::unique_ptr<NodePattern> left_node;
    std::unique_ptr<RelationshipPattern> relationship;
    std::unique_ptr<NodePattern> right_node;
};

// MATCH 子句
class MatchClause : public Clause {
public:
    MatchClause() : Clause(ASTNodeType::MATCH_CLAUSE) {}
    MatchClause(bool optional) : Clause(ASTNodeType::MATCH_CLAUSE), is_optional(optional) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<std::unique_ptr<PathPattern>> patterns;
    ExpressionPtr where;  // WHERE 子句（可选）
    bool is_optional = false;  // OPTIONAL MATCH
};

// ============================================================================
// WHERE 子句
// ============================================================================
class WhereClause : public Clause {
public:
    explicit WhereClause(ExpressionPtr condition)
        : Clause(ASTNodeType::WHERE_CLAUSE), condition(std::move(condition)) {}

    void Accept(ASTVisitor& visitor) override;

    ExpressionPtr condition;
};

// ============================================================================
// RETURN 子句
// ============================================================================
class ReturnItem {
public:
    ExpressionPtr expr;
    std::string alias;  // 别名（可空）

    bool is_alias_set() const { return !alias.empty(); }
};

class ReturnClause : public Clause {
public:
    ReturnClause() : Clause(ASTNodeType::RETURN_CLAUSE) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<ReturnItem> return_items;
    bool distinct = false;     // RETURN DISTINCT
    bool is_star = false;      // RETURN *
};

// ============================================================================
// CREATE 子句
// ============================================================================
class CreateClause : public Clause {
public:
    CreateClause() : Clause(ASTNodeType::CREATE_CLAUSE) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<std::unique_ptr<PathPattern>> patterns;
};

// ============================================================================
// DELETE 子句
// ============================================================================
class DeleteClause : public Clause {
public:
    DeleteClause() : Clause(ASTNodeType::DELETE_CLAUSE) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<ExpressionPtr> expressions;  // 要删除的表达式（变量）
    bool detach = false;  // DELETE DETACH（同时删除相关边）
};

// ============================================================================
// SET 子句
// ============================================================================
class SetPropertyItem {
public:
    enum class SetType {
        PROPERTY,   // SET n.name = 'Alice'
        LABELS      // SET n:Person:Manager
    };

    SetType type;
    ExpressionPtr expr;       // 属性表达式
    ExpressionPtr value;      // 设置的值（仅 PROPERTY 使用）
    std::vector<std::string> labels;  // 标签列表（仅 LABELS 使用）
};

class SetClause : public Clause {
public:
    SetClause() : Clause(ASTNodeType::SET_CLAUSE) {}

    void Accept(ASTVisitor& visitor) override;

    std::vector<SetPropertyItem> items;
};

// ============================================================================
// MERGE 子句（可选，复杂度较高）
// ============================================================================
class MergeClause : public Clause {
public:
    MergeClause() : Clause(ASTNodeType::MERGE_CLAUSE) {}

    void Accept(ASTVisitor& visitor) override;

    std::unique_ptr<PathPattern> pattern;
    std::vector<std::unique_ptr<Clause>> on_match_clauses;  // ON MATCH SET ...
    std::vector<std::unique_ptr<Clause>> on_create_clauses;  // ON CREATE SET ...
};

} // namespace cypher
} // namespace BACH
