#pragma once

#include "../../parser/expression.h"
#include "../../parser/data_type.h"
#include "BACH/db/DB.h"
#include "BACH/db/Transaction.h"
#include "BACH/label/LabelManager.h"
#include <memory>
#include <vector>
#include <functional>

namespace BACH {
namespace cypher {

// 前向声明
struct ExecutionContext;
class Operator;

// 数据库指针（用于操作符访问 BACH 数据库）
// 通过 ExecutionContext 传递
inline DB* GetDB(ExecutionContext* ctx) {
    // 需要在 ExecutionContext 中添加 db 成员
    return nullptr; // 占位，实际从 Executor 获取
}

// 表达式求值上下文
struct EvalContext {
    ExecutionContext* exec_ctx;
    DB* db;
    const std::unordered_map<std::string, Value>* current_row;

    Value Evaluate(Expression* expr);
    Value EvaluateBinaryOp(BinaryOpType op_type, const Value& left, const Value& right);
};

// 操作符基类（迭代器模型）
class Operator {
public:
    Operator() = default;
    virtual ~Operator() = default;

    // 初始化操作符
    virtual void Open() = 0;

    // 获取下一行数据
    // 返回 false 表示没有更多数据
    virtual bool Next() = 0;

    // 获取当前行的数据
    virtual const std::unordered_map<std::string, Value>& GetCurrent() const = 0;

    // 关闭操作符
    virtual void Close() = 0;

    // 设置子操作符（输入）
    void SetChild(std::unique_ptr<Operator> child) {
        children.push_back(std::move(child));
    }

    Operator* GetChild(size_t index = 0) const {
        return index < children.size() ? children[index].get() : nullptr;
    }

    // 设置数据库指针
    void SetDatabase(DB* db) { database = db; }
    void SetEvalContext(EvalContext* eval_ctx) { eval_ctx_ptr = eval_ctx; }

protected:
    std::vector<std::unique_ptr<Operator>> children;
    ExecutionContext* ctx = nullptr;
    DB* database = nullptr;
    EvalContext* eval_ctx_ptr = nullptr;
};

// 操作符工厂接口
using OperatorFactory = std::function<std::unique_ptr<Operator>(PlanNode*, ExecutionContext*)>;

// ============================================================================
// 扫描操作符
// ============================================================================

// 全节点扫描操作符
class AllNodeScanOp : public Operator {
public:
    AllNodeScanOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    ExecutionContext* ctx = nullptr;
    std::string output_var;
    label_t label_id;  // 标签 ID，0 表示所有标签
    Transaction* tx = nullptr;
    DB* db = nullptr;

    // 扫描状态
    bool is_eof = false;
    vertex_t current_vertex = 0;
    vertex_t max_vertex = 0;
    std::vector<std::pair<label_t, vertex_t>> vertices;  // (label, vertex_id)

    // 当前行数据
    std::unordered_map<std::string, Value> current_row;

    // 扫描指定标签的所有顶点
    void ScanLabelVertices();
};

// ============================================================================
// 遍历操作符
// ============================================================================

// 边展开操作符
class ExpandOp : public Operator {
public:
    ExpandOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    ExecutionContext* ctx = nullptr;
    std::string src_var;
    std::string dst_var;
    std::string edge_var;
    label_t edge_label_id;  // 0 表示所有标签
    enum class Direction { OUT, IN, BOTH } direction = Direction::OUT;

    Transaction* tx = nullptr;
    DB* db = nullptr;

    // 遍历状态
    std::unordered_map<std::string, Value> input_row;  // 来自子操作符的行
    bool has_input = false;
    bool is_eof = false;
    size_t current_edge_index = 0;
    std::vector<std::pair<vertex_t, edge_property_t>> neighbors;

    std::unordered_map<std::string, Value> current_row;
};

// ============================================================================
// 过滤操作符
// ============================================================================

// 过滤操作符
class FilterOp : public Operator {
public:
    FilterOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    ExpressionPtr condition;
    EvalContext eval_ctx;

    // 表达式求值器
    Value EvaluateExpression(Expression* expr);
};

// ============================================================================
// 投影操作符
// ============================================================================

// 投影操作符
class ProjectOp : public Operator {
public:
    ProjectOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    struct ProjectionItem {
        ExpressionPtr expr;
        std::string alias;
    };
    std::vector<ProjectionItem> projections;
    bool distinct = false;

    EvalContext eval_ctx;
    std::unordered_map<std::string, Value> current_row;

    // 用于去重
    std::unordered_set<std::string> seen_rows;

    Value EvaluateExpression(Expression* expr);
};

// ============================================================================
// 写操作符
// ============================================================================

// 创建节点操作符
class CreateNodeOp : public Operator {
public:
    CreateNodeOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    std::string var_name;
    label_t label_id;
    std::vector<std::pair<std::string, ExpressionPtr>> properties;

    Transaction* tx = nullptr;
    DB* db = nullptr;
    EvalContext eval_ctx;
    bool is_executed = false;

    std::unordered_map<std::string, Value> current_row;

    // 评估属性表达式
    std::string EvaluateProperty(Expression* expr);
};

// 创建边操作符
class CreateEdgeOp : public Operator {
public:
    CreateEdgeOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    std::string edge_var;
    std::string src_var;
    std::string dst_var;
    label_t edge_label_id;
    std::vector<std::pair<std::string, ExpressionPtr>> properties;

    Transaction* tx = nullptr;
    DB* db = nullptr;
    EvalContext eval_ctx;
    bool is_executed = false;

    std::unordered_map<std::string, Value> current_row;

    edge_property_t EvaluateEdgeProperty();
};

// 删除操作符
class DeleteOp : public Operator {
public:
    DeleteOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    struct DeleteItem {
        std::string var_name;
        bool is_node;      // true = 删除节点, false = 删除边
        label_t label_id;  // 用于删除节点时的标签
    };
    std::vector<DeleteItem> items_to_delete;
    bool detach = false;

    Transaction* tx = nullptr;
    DB* db = nullptr;
    bool is_executed = false;

    std::unordered_map<std::string, Value> current_row;
    std::unordered_map<std::string, Value> last_input_row;
};

// 设置属性操作符
class SetPropertyOp : public Operator {
public:
    SetPropertyOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    ExpressionPtr target_expr;  // 如 n.prop
    ExpressionPtr value_expr;

    Transaction* tx = nullptr;
    DB* db = nullptr;
    EvalContext eval_ctx;
    bool is_executed = false;

    std::unordered_map<std::string, Value> current_row;
};

// 设置标签操作符
class SetLabelsOp : public Operator {
public:
    SetLabelsOp(PlanNode* node, ExecutionContext* context, DB* db);

    void Open() override;
    bool Next() override;
    const std::unordered_map<std::string, Value>& GetCurrent() const override;
    void Close() override;

private:
    std::string var_name;
    std::vector<label_t> label_ids;

    Transaction* tx = nullptr;
    DB* db = nullptr;
    bool is_executed = false;

    std::unordered_map<std::string, Value> current_row;
};

// ============================================================================
// 工具函数
// ============================================================================

// 将 BACH 的顶点 ID 转换为 Cypher Value
inline Value VertexToValue(vertex_t vid) {
    return Value(static_cast<int64_t>(vid));
}

// 将 BACH 的边属性转换为 Cypher Value
inline Value EdgePropertyToValue(edge_property_t prop) {
    return Value(static_cast<double>(prop));
}

// 将 Cypher Value 转换为字符串（用于属性存储）
inline std::string ValueToString(const Value& v) {
    if (IsInt(v)) return std::to_string(std::get<int64_t>(v.data));
    if (IsFloat(v)) return std::to_string(std::get<double>(v.data));
    if (IsBool(v)) return std::get<bool>(v.data) ? "true" : "false";
    if (IsString(v)) return std::get<std::string>(v.data);
    if (IsNull(v)) return "null";
    return "";
}

} // namespace cypher
} // namespace BACH
