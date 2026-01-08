#pragma once

#include "../parser/expression.h"
#include <memory>
#include <vector>
#include <string>

namespace BACH {
namespace cypher {

// 前向声明
class PlanNode;

// 计划节点类型
enum class PlanNodeType {
    // 扫描节点
    ALL_NODE_SCAN,      // 全节点扫描
    NODE_BY_ID_SCAN,    // 按 ID 扫描节点
    NODE_INDEX_SCAN,    // 索引扫描（未来扩展）
    LABEL_SCAN,         // 按标签扫描

    // 遍历节点
    EXPAND,             // 边展开（沿边遍历）
    VAR_LENGTH_EXPAND,  // 变长路径展开

    // 过滤节点
    FILTER,             // 过滤
    SELECT,             // 选择（基于属性）

    // 投影节点
    PROJECT,            // 投影（计算表达式）
    AGGREGATE,          // 聚合

    // 写节点
    CREATE_NODE,        // 创建节点
    CREATE_EDGE,        // 创建边
    DELETE_NODE,        // 删除节点
    DELETE_EDGE,        // 删除边
    SET_PROPERTY,       // 设置属性
    SET_LABELS,         // 设置标签

    // 其他
    CARTESIAN_PRODUCT,  // 笛卡尔积
    DISTINCT,           // 去重
    SORT,               // 排序
    LIMIT,              // 限制结果数量
    APPLY               // 应用子查询
};

// 计划节点基类
class PlanNode {
public:
    explicit PlanNode(PlanNodeType type) : node_type(type) {}
    virtual ~PlanNode() = default;

    PlanNodeType GetNodeType() const { return node_type; }

    // 子节点（输入节点）
    std::vector<std::unique_ptr<PlanNode>> children;
    std::vector<PlanNode*> producers;  // 依赖的生产者

    // 输出模式（该节点产生哪些列/变量）
    std::vector<std::string> output_columns;

    // 估算代价
    double estimated_cost = 0.0;
    size_t estimated_cardinality = 0;

    // 调试信息
    virtual std::string ToString() const { return "PlanNode"; }

protected:
    PlanNodeType node_type;
};

// ============================================================================
// 具体计划节点
// ============================================================================

// 全节点扫描
class AllNodeScan : public PlanNode {
public:
    AllNodeScan() : PlanNode(PlanNodeType::ALL_NODE_SCAN) {}

    std::string output_var;  // 输出的变量名
    std::string label_filter; // 可选的标签过滤

    std::string ToString() const override {
        return "AllNodeScan" + (label_filter.empty() ? "" : "(" + label_filter + ")");
    }
};

// 按 ID 扫描节点
class NodeByIdScan : public PlanNode {
public:
    NodeByIdScan() : PlanNode(PlanNodeType::NODE_BY_ID_SCAN) {}

    std::string output_var;
    std::vector<int64_t> ids;  // 要扫描的 ID 列表

    std::string ToString() const override {
        return "NodeByIdScan";
    }
};

// 边展开
class Expand : public PlanNode {
public:
    Expand() : PlanNode(PlanNodeType::EXPAND) {}

    std::string src_var;        // 源节点变量
    std::string dst_var;        // 目标节点变量
    std::string edge_var;       // 边变量（可空）
    std::string edge_label;     // 边标签（可空）
    enum class Direction { OUT, IN, BOTH };
    Direction direction = Direction::OUT;

    std::string ToString() const override {
        return "Expand(" + src_var + ")->(" + dst_var + ")";
    }
};

// 过滤节点
class Filter : public PlanNode {
public:
    Filter() : PlanNode(PlanNodeType::FILTER) {}

    ExpressionPtr condition;  // 过滤条件

    std::string ToString() const override {
        return "Filter";
    }
};

// 投影节点
class Project : public PlanNode {
public:
    Project() : PlanNode(PlanNodeType::PROJECT) {}

    struct ProjectionItem {
        ExpressionPtr expr;
        std::string alias;
    };

    std::vector<ProjectionItem> projections;
    bool distinct = false;

    std::string ToString() const override {
        return std::string("Project") + (distinct ? "Distinct" : "");
    }
};

// 聚合节点
class Aggregate : public PlanNode {
public:
    Aggregate() : PlanNode(PlanNodeType::AGGREGATE) {}

    struct AggregationItem {
        enum class AggType { COUNT, SUM, AVG, MIN, MAX, COUNT_DISTINCT };
        AggType type;
        ExpressionPtr expr;
        std::string alias;
        bool is_star = false;  // COUNT(*)
    };

    std::vector<ExpressionPtr> group_by;      // GROUP BY 表达式
    std::vector<AggregationItem> aggregations;

    std::string ToString() const override {
        return "Aggregate";
    }
};

// 创建节点
class CreateNode : public PlanNode {
public:
    CreateNode() : PlanNode(PlanNodeType::CREATE_NODE) {}

    std::string var_name;
    std::string label;
    std::vector<std::pair<std::string, ExpressionPtr>> properties;

    std::string ToString() const override {
        return "CreateNode(" + var_name + ":" + label + ")";
    }
};

// 创建边
class CreateEdge : public PlanNode {
public:
    CreateEdge() : PlanNode(PlanNodeType::CREATE_EDGE) {}

    std::string edge_var;
    std::string src_var;
    std::string dst_var;
    std::string edge_label;
    std::vector<std::pair<std::string, ExpressionPtr>> properties;

    std::string ToString() const override {
        return "CreateEdge(" + src_var + ")-[" + edge_label + "]->(" + dst_var + ")";
    }
};

// 删除节点
class DeleteNode : public PlanNode {
public:
    DeleteNode() : PlanNode(PlanNodeType::DELETE_NODE) {}

    std::string var_name;
    bool detach = false;  // 是否同时删除相关边

    std::string ToString() const override {
        return "DeleteNode(" + var_name + ")";
    }
};

// 删除边
class DeleteEdge : public PlanNode {
public:
    DeleteEdge() : PlanNode(PlanNodeType::DELETE_EDGE) {}

    std::string edge_var;

    std::string ToString() const override {
        return "DeleteEdge(" + edge_var + ")";
    }
};

// 设置属性
class SetProperty : public PlanNode {
public:
    SetProperty() : PlanNode(PlanNodeType::SET_PROPERTY) {}

    ExpressionPtr target_expr;  // 目标表达式（如 n.prop）
    ExpressionPtr value_expr;   // 值表达式

    std::string ToString() const override {
        return "SetProperty";
    }
};

// 设置标签
class SetLabels : public PlanNode {
public:
    SetLabels() : PlanNode(PlanNodeType::SET_LABELS) {}

    std::string var_name;
    std::vector<std::string> labels;

    std::string ToString() const override {
        return "SetLabels";
    }
};

// 排序节点
class Sort : public PlanNode {
public:
    Sort() : PlanNode(PlanNodeType::SORT) {}

    struct SortItem {
        ExpressionPtr expr;
        bool ascending = true;
    };

    std::vector<SortItem> sort_items;

    std::string ToString() const override {
        return "Sort";
    }
};

// 限制节点
class Limit : public PlanNode {
public:
    Limit() : PlanNode(PlanNodeType::LIMIT) {}

    size_t limit_count = 0;
    size_t skip_count = 0;

    std::string ToString() const override {
        return "Limit(" + std::to_string(limit_count) + ")";
    }
};

// 去重节点
class Distinct : public PlanNode {
public:
    Distinct() : PlanNode(PlanNodeType::DISTINCT) {}

    std::vector<std::string> distinct_columns;

    std::string ToString() const override {
        return "Distinct";
    }
};

// ============================================================================
// 执行计划
// ============================================================================

class ExecutionPlan {
public:
    ExecutionPlan() = default;
    ~ExecutionPlan() = default;

    // 计划的根节点
    std::unique_ptr<PlanNode> root;

    // 参数（用于参数化查询）
    std::unordered_map<std::string, Value> parameters;

    // 调试输出
    std::string ToString() const;

    // 获取所有节点
    std::vector<const PlanNode*> GetAllNodes() const;

private:
    // 辅助方法
    void ToStringHelper(std::ostringstream& oss, const PlanNode* node, int indent) const;
    void CollectNodes(const PlanNode* node, std::vector<const PlanNode*>& result) const;
};

} // namespace cypher
} // namespace BACH
