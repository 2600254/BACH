#include "BACH/cypher/executor/executor.h"
#include "BACH/cypher/executor/ops/op.h"
#include "BACH/cypher/planner/execution_plan.h"
#include <sstream>
#include <iostream>

namespace BACH {
namespace cypher {

// ============================================================================
// ExecutionContext - GetLabelId 辅助函数
// ============================================================================

label_t ExecutionContext::GetLabelId(const std::string& label_name, bool is_vertex) const {
    if (!db) return 0;

    if (is_vertex) {
        return db->Labels->GetVertexLabelId(label_name);
    } else {
        return db->Labels->GetEdgeLabelId(label_name);
    }
}

// ============================================================================
// Executor - 执行引擎
// ============================================================================

Executor::Executor() = default;

Executor::~Executor() = default;

bool Executor::Execute(ExecutionPlan* plan, Transaction* tx, ExecutionContext* ctx) {
    if (!plan || !plan->root || !tx || !ctx) {
        return false;
    }

    ctx->tx = tx;
    ctx->Reset();

    // 创建 EvalContext
    EvalContext eval_ctx;
    eval_ctx.exec_ctx = ctx;
    eval_ctx.db = database;

    // 创建根操作符
    auto op = CreateOperator(plan->root.get(), ctx);
    if (!op) {
        return false;
    }

    // 设置数据库指针到所有操作符
    std::function<void(Operator*)> set_db = [&](Operator* o) {
        o->SetDatabase(database);
        o->SetEvalContext(&eval_ctx);
        // TODO: 遍历子操作符
    };
    set_db(op.get());

    op->Open();

    while (op->Next()) {
        const auto& row = op->GetCurrent();

        // 收集结果
        if (ctx->result_columns.empty()) {
            for (const auto& [col, val] : row) {
                ctx->result_columns.push_back(col);
            }
        }

        ctx->result_rows.push_back({});
        for (const auto& col : ctx->result_columns) {
            auto it = row.find(col);
            if (it != row.end()) {
                ctx->result_rows.back().push_back(it->second);
            } else {
                ctx->result_rows.back().push_back(Value()); // null
            }
        }
    }

    op->Close();

    return true;
}

std::string Executor::GetStats(const ExecutionContext& ctx) const {
    std::ostringstream oss;
    oss << "Nodes created: " << ctx.nodes_created << "\n";
    oss << "Nodes deleted: " << ctx.nodes_deleted << "\n";
    oss << "Relationships created: " << ctx.relationships_created << "\n";
    oss << "Relationships deleted: " << ctx.relationships_deleted << "\n";
    return oss.str();
}

std::unique_ptr<Operator> Executor::CreateOperator(PlanNode* node, ExecutionContext* ctx) {
    if (!node) return nullptr;

    // 递归创建子操作符
    std::vector<std::unique_ptr<Operator>> children;
    for (auto& child_node : node->children) {
        auto child_op = CreateOperator(child_node.get(), ctx);
        if (!child_op) return nullptr;
        children.push_back(std::move(child_op));
    }

    // 创建当前操作符
    std::unique_ptr<Operator> op;
    switch (node->GetNodeType()) {
        case PlanNodeType::ALL_NODE_SCAN:
            op = std::make_unique<AllNodeScanOp>(node, ctx, database);
            break;
        case PlanNodeType::EXPAND:
            op = std::make_unique<ExpandOp>(node, ctx, database);
            break;
        case PlanNodeType::FILTER:
            op = std::make_unique<FilterOp>(node, ctx, database);
            break;
        case PlanNodeType::PROJECT:
            op = std::make_unique<ProjectOp>(node, ctx, database);
            break;
        case PlanNodeType::CREATE_NODE:
            op = std::make_unique<CreateNodeOp>(node, ctx, database);
            break;
        case PlanNodeType::CREATE_EDGE:
            op = std::make_unique<CreateEdgeOp>(node, ctx, database);
            break;
        case PlanNodeType::DELETE_NODE:
        case PlanNodeType::DELETE_EDGE:
            op = std::make_unique<DeleteOp>(node, ctx, database);
            break;
        case PlanNodeType::SET_PROPERTY:
        case PlanNodeType::SET_LABELS:
            // 根据 node 类型选择
            if (node->GetNodeType() == PlanNodeType::SET_LABELS) {
                op = std::make_unique<SetLabelsOp>(node, ctx, database);
            } else {
                op = std::make_unique<SetPropertyOp>(node, ctx, database);
            }
            break;
        default:
            return nullptr;
    }

    if (!op) return nullptr;

    // 添加子操作符
    for (auto& child : children) {
        op->SetChild(std::move(child));
    }

    return op;
}

// ============================================================================
// EvalContext - 表达式求值上下文
// ============================================================================

Value EvalContext::Evaluate(Expression* expr) {
    if (!expr) return Value();

    switch (expr->GetNodeType()) {
        case ASTNodeType::LITERAL: {
            auto* lit = static_cast<Literal*>(expr);
            return lit->value;
        }
        case ASTNodeType::VARIABLE: {
            auto* var = static_cast<Variable*>(expr);
            // 从 current_row 中查找
            if (current_row) {
                auto it = current_row->find(var->name);
                if (it != current_row->end()) {
                    return it->second;
                }
            }
            // 从符号表中查找
            if (exec_ctx) {
                auto it = exec_ctx->symbols.find(var->name);
                if (it != exec_ctx->symbols.end()) {
                    return it->second;
                }
            }
            return Value(); // 未找到，返回 null
        }
        case ASTNodeType::PROPERTY: {
            auto* prop = static_cast<Property*>(expr);
            auto base_value = Evaluate(prop->expr.get());
            // TODO: 实现属性访问
            // 简化实现：返回 null
            return Value();
        }
        case ASTNodeType::BINARY_OP: {
            auto* binop = static_cast<BinaryOp*>(expr);
            auto left = Evaluate(binop->left.get());
            auto right = Evaluate(binop->right.get());

            return EvaluateBinaryOp(binop->op_type, left, right);
        }
        case ASTNodeType::UNARY_OP: {
            auto* unop = static_cast<UnaryOp*>(expr);
            auto operand = Evaluate(unop->expr.get());

            switch (unop->op_type) {
                case UnaryOpType::NOT:
                    if (IsBool(operand)) {
                        return Value(!std::get<bool>(operand.data));
                    }
                    return Value();
                case UnaryOpType::NEGATE:
                    if (IsInt(operand)) {
                        return Value(-std::get<int64_t>(operand.data));
                    } else if (IsFloat(operand)) {
                        return Value(-std::get<double>(operand.data));
                    }
                    return Value();
                default:
                    return Value();
            }
        }
        default:
            return Value();
    }
}

Value EvalContext::EvaluateBinaryOp(BinaryOpType op_type, const Value& left, const Value& right) {
    // 比较运算
    if (op_type == BinaryOpType::EQ) {
        if (IsNull(left) || IsNull(right)) return Value(false);
        if (IsInt(left) && IsInt(right)) {
            return Value(std::get<int64_t>(left.data) == std::get<int64_t>(right.data));
        }
        if (IsFloat(left) && IsFloat(right)) {
            return Value(std::get<double>(left.data) == std::get<double>(right.data));
        }
        if (IsString(left) && IsString(right)) {
            return Value(std::get<std::string>(left.data) == std::get<std::string>(right.data));
        }
        return Value(false);
    }

    if (op_type == BinaryOpType::NEQ) {
        auto eq = EvaluateBinaryOp(BinaryOpType::EQ, left, right);
        if (IsBool(eq)) return Value(!std::get<bool>(eq.data));
        return Value();
    }

    if (op_type == BinaryOpType::LT) {
        if (IsInt(left) && IsInt(right)) {
            return Value(std::get<int64_t>(left.data) < std::get<int64_t>(right.data));
        }
        if (IsFloat(left) && IsFloat(right)) {
            return Value(std::get<double>(left.data) < std::get<double>(right.data));
        }
        return Value();
    }

    if (op_type == BinaryOpType::LTE) {
        auto lt = EvaluateBinaryOp(BinaryOpType::LT, left, right);
        auto eq = EvaluateBinaryOp(BinaryOpType::EQ, left, right);
        if (IsBool(lt) && IsBool(eq)) {
            return Value(std::get<bool>(lt.data) || std::get<bool>(eq.data));
        }
        return Value();
    }

    if (op_type == BinaryOpType::GT) {
        if (IsInt(left) && IsInt(right)) {
            return Value(std::get<int64_t>(left.data) > std::get<int64_t>(right.data));
        }
        if (IsFloat(left) && IsFloat(right)) {
            return Value(std::get<double>(left.data) > std::get<double>(right.data));
        }
        return Value();
    }

    if (op_type == BinaryOpType::GTE) {
        auto gt = EvaluateBinaryOp(BinaryOpType::GT, left, right);
        auto eq = EvaluateBinaryOp(BinaryOpType::EQ, left, right);
        if (IsBool(gt) && IsBool(eq)) {
            return Value(std::get<bool>(gt.data) || std::get<bool>(eq.data));
        }
        return Value();
    }

    // 逻辑运算
    if (op_type == BinaryOpType::AND) {
        if (IsBool(left) && IsBool(right)) {
            return Value(std::get<bool>(left.data) && std::get<bool>(right.data));
        }
        return Value();
    }

    if (op_type == BinaryOpType::OR) {
        if (IsBool(left) && IsBool(right)) {
            return Value(std::get<bool>(left.data) || std::get<bool>(right.data));
        }
        return Value();
    }

    // 算术运算
    if (op_type == BinaryOpType::ADD) {
        if (IsInt(left) && IsInt(right)) {
            return Value(std::get<int64_t>(left.data) + std::get<int64_t>(right.data));
        }
        if (IsFloat(left) || IsFloat(right)) {
            double l = IsFloat(left) ? std::get<double>(left.data) : static_cast<double>(std::get<int64_t>(left.data));
            double r = IsFloat(right) ? std::get<double>(right.data) : static_cast<double>(std::get<int64_t>(right.data));
            return Value(l + r);
        }
        if (IsString(left) && IsString(right)) {
            return Value(std::get<std::string>(left.data) + std::get<std::string>(right.data));
        }
        return Value();
    }

    if (op_type == BinaryOpType::SUB) {
        if (IsInt(left) && IsInt(right)) {
            return Value(std::get<int64_t>(left.data) - std::get<int64_t>(right.data));
        }
        if (IsFloat(left) || IsFloat(right)) {
            double l = IsFloat(left) ? std::get<double>(left.data) : static_cast<double>(std::get<int64_t>(left.data));
            double r = IsFloat(right) ? std::get<double>(right.data) : static_cast<double>(std::get<int64_t>(right.data));
            return Value(l - r);
        }
        return Value();
    }

    if (op_type == BinaryOpType::MUL) {
        if (IsInt(left) && IsInt(right)) {
            return Value(std::get<int64_t>(left.data) * std::get<int64_t>(right.data));
        }
        if (IsFloat(left) || IsFloat(right)) {
            double l = IsFloat(left) ? std::get<double>(left.data) : static_cast<double>(std::get<int64_t>(left.data));
            double r = IsFloat(right) ? std::get<double>(right.data) : static_cast<double>(std::get<int64_t>(right.data));
            return Value(l * r);
        }
        return Value();
    }

    if (op_type == BinaryOpType::DIV) {
        if (IsInt(left) && IsInt(right)) {
            int64_t r = std::get<int64_t>(right.data);
            if (r == 0) return Value();
            return Value(std::get<int64_t>(left.data) / r);
        }
        if (IsFloat(left) || IsFloat(right)) {
            double l = IsFloat(left) ? std::get<double>(left.data) : static_cast<double>(std::get<int64_t>(left.data));
            double r = IsFloat(right) ? std::get<double>(right.data) : static_cast<double>(std::get<int64_t>(right.data));
            if (r == 0.0) return Value();
            return Value(l / r);
        }
        return Value();
    }

    return Value();
}

// ============================================================================
// AllNodeScanOp - 全节点扫描
// ============================================================================

AllNodeScanOp::AllNodeScanOp(PlanNode* node, ExecutionContext* context, DB* db)
    : ctx(context), tx(context->tx), db(db) {
    auto* scan = static_cast<AllNodeScan*>(node);
    output_var = scan->output_var;

    // 获取标签 ID
    if (!scan->label_filter.empty()) {
        label_id = ctx->GetLabelId(scan->label_filter, true);
    } else {
        label_id = 0;  // 0 表示扫描所有标签
    }
}

void AllNodeScanOp::ScanLabelVertices() {
    if (!db || !tx) return;

    if (label_id == 0) {
        // 扫描所有标签的所有顶点
        // 使用 EdgeLabelScan 来遍历边，从而发现所有顶点
        // 这里简化实现：假设顶点 ID 从 0 开始连续
        // TODO: 需要从数据库获取顶点数量
        // 当前是简化实现
        max_vertex = 1000; // 占位值
    } else {
        // 扫描指定标签的顶点
        vertex_num_t num_vertices = tx->GetVertexNum(label_id);
        max_vertex = num_vertices;
    }
}

void AllNodeScanOp::Open() {
    is_eof = false;
    current_vertex = 0;
    vertices.clear();

    ScanLabelVertices();
}

bool AllNodeScanOp::Next() {
    if (is_eof || current_vertex >= max_vertex) {
        is_eof = true;
        return false;
    }

    current_row.clear();
    current_row[output_var] = VertexToValue(current_vertex);
    current_vertex++;
    return true;
}

const std::unordered_map<std::string, Value>& AllNodeScanOp::GetCurrent() const {
    return current_row;
}

void AllNodeScanOp::Close() {
    vertices.clear();
    current_row.clear();
}

// ============================================================================
// ExpandOp - 边展开
// ============================================================================

ExpandOp::ExpandOp(PlanNode* node, ExecutionContext* context, DB* db)
    : ctx(context), tx(context->tx), db(db) {
    auto* expand = static_cast<Expand*>(node);
    src_var = expand->src_var;
    dst_var = expand->dst_var;
    edge_var = expand->edge_var;

    // 获取边标签 ID
    if (!expand->edge_label.empty()) {
        edge_label_id = ctx->GetLabelId(expand->edge_label, false);
    } else {
        edge_label_id = 0;  // 0 表示所有标签
    }

    direction = static_cast<Direction>(static_cast<int>(expand->direction));
}

void ExpandOp::Open() {
    has_input = false;
    is_eof = false;
    current_edge_index = 0;
    neighbors.clear();
}

bool ExpandOp::Next() {
    auto child = GetChild();
    if (!child) return false;

    while (true) {
        if (!has_input) {
            if (!child->Next()) {
                is_eof = true;
                return false;
            }
            input_row = child->GetCurrent();
            has_input = true;

            // 获取源顶点 ID
            auto src_it = input_row.find(src_var);
            if (src_it == input_row.end() || !IsInt(src_it->second)) {
                has_input = false;
                continue;
            }

            vertex_t src_id = static_cast<vertex_t>(std::get<int64_t>(src_it->second.data));

            // 获取邻居
            neighbors.clear();
            if (edge_label_id == 0) {
                // TODO: 遍历所有边标签
                // 当前简化：只处理单一标签
            } else {
                auto edges = tx->GetEdges(src_id, edge_label_id);
                if (edges) {
                    neighbors = *edges;
                }
            }
            current_edge_index = 0;
        }

        if (current_edge_index < neighbors.size()) {
            current_row = input_row;
            const auto& [dst_id, prop] = neighbors[current_edge_index];
            current_row[dst_var] = VertexToValue(dst_id);
            if (!edge_var.empty()) {
                current_row[edge_var] = EdgePropertyToValue(prop);
            }
            current_edge_index++;
            return true;
        } else {
            has_input = false;
        }
    }
}

const std::unordered_map<std::string, Value>& ExpandOp::GetCurrent() const {
    return current_row;
}

void ExpandOp::Close() {
    neighbors.clear();
    input_row.clear();
    current_row.clear();
}

// ============================================================================
// FilterOp - 过滤
// ============================================================================

FilterOp::FilterOp(PlanNode* node, ExecutionContext* context, DB* db)
    : eval_ctx{context, db, nullptr} {
    auto* filter = static_cast<Filter*>(node);
    condition = std::move(filter->condition);
}

void FilterOp::Open() {
    if (auto child = GetChild()) {
        child->Open();
    }
}

bool FilterOp::Next() {
    auto child = GetChild();
    if (!child) return false;

    while (child->Next()) {
        eval_ctx.current_row = &child->GetCurrent();

        // 评估条件
        auto result = EvaluateExpression(condition.get());

        if (IsBool(result) && std::get<bool>(result.data)) {
            return true;
        }
    }

    return false;
}

const std::unordered_map<std::string, Value>& FilterOp::GetCurrent() const {
    auto child = GetChild();
    return child ? child->GetCurrent() : eval_ctx.exec_ctx->current_row;
}

void FilterOp::Close() {
    if (auto child = GetChild()) {
        child->Close();
    }
}

Value FilterOp::EvaluateExpression(Expression* expr) {
    return eval_ctx.Evaluate(expr);
}

// ============================================================================
// ProjectOp - 投影
// ============================================================================

ProjectOp::ProjectOp(PlanNode* node, ExecutionContext* context, DB* db)
    : eval_ctx{context, db, nullptr} {
    auto* project = static_cast<Project*>(node);
    distinct = project->distinct;
    projections.reserve(project->projections.size());
    for (const auto& item : project->projections) {
        projections.push_back({item.expr.get(), item.alias});
    }
}

void ProjectOp::Open() {
    if (auto child = GetChild()) {
        child->Open();
    }
    seen_rows.clear();
}

bool ProjectOp::Next() {
    auto child = GetChild();
    if (!child) return false;

    while (child->Next()) {
        eval_ctx.current_row = &child->GetCurrent();
        current_row.clear();

        for (const auto& proj : projections) {
            auto value = eval_ctx.Evaluate(proj.expr);
            current_row[proj.alias] = value;
        }

        if (distinct) {
            // 构建去重键
            std::string key;
            for (const auto& [k, v] : current_row) {
                key += k + ":";
                if (IsInt(v)) {
                    key += std::to_string(std::get<int64_t>(v.data));
                } else if (IsFloat(v)) {
                    key += std::to_string(std::get<double>(v.data));
                } else if (IsString(v)) {
                    key += std::get<std::string>(v.data);
                } else if (IsBool(v)) {
                    key += std::get<bool>(v.data) ? "true" : "false";
                }
                key += ";";
            }
            if (seen_rows.contains(key)) {
                continue; // 跳过重复
            }
            seen_rows.insert(key);
        }

        return true;
    }

    return false;
}

const std::unordered_map<std::string, Value>& ProjectOp::GetCurrent() const {
    return current_row;
}

void ProjectOp::Close() {
    if (auto child = GetChild()) {
        child->Close();
    }
    seen_rows.clear();
}

Value ProjectOp::EvaluateExpression(Expression* expr) {
    return eval_ctx.Evaluate(expr);
}

// ============================================================================
// CreateNodeOp - 创建节点
// ============================================================================

CreateNodeOp::CreateNodeOp(PlanNode* node, ExecutionContext* context, DB* db)
    : tx(context->tx), db(db), eval_ctx{context, db, nullptr} {
    auto* create = static_cast<CreateNode*>(node);
    var_name = create->var_name;
    label_id = context->GetLabelId(create->label, true);
    properties.reserve(create->properties.size());
    for (const auto& [k, v] : create->properties) {
        properties.push_back({k, v.get()});
    }
}

std::string CreateNodeOp::EvaluateProperty(Expression* expr) {
    auto value = eval_ctx.Evaluate(expr);
    return ValueToString(value);
}

void CreateNodeOp::Open() {
    is_executed = false;
    current_row.clear();
}

bool CreateNodeOp::Next() {
    if (is_executed) return false;

    // 获取输入行（如果有）
    auto child = GetChild();
    if (child) {
        if (!child->Next()) {
            is_executed = true;
            return false;
        }
        current_row = child->GetCurrent();
        eval_ctx.current_row = &current_row;
    }

    // 创建节点
    vertex_t new_vid = tx->AddVertex(label_id);

    // 设置属性
    std::string props_str;
    for (const auto& [key, expr] : properties) {
        std::string value = EvaluateProperty(expr);
        if (!value.empty()) {
            if (!props_str.empty()) props_str += ",";
            props_str += key + ":" + value;
        }
    }

    if (!props_str.empty()) {
        tx->PutVertex(label_id, new_vid, props_str);
    }

    current_row[var_name] = VertexToValue(new_vid);
    ctx->nodes_created++;
    is_executed = true;
    return true;
}

const std::unordered_map<std::string, Value>& CreateNodeOp::GetCurrent() const {
    return current_row;
}

void CreateNodeOp::Close() {
    current_row.clear();
}

// ============================================================================
// CreateEdgeOp - 创建边
// ============================================================================

CreateEdgeOp::CreateEdgeOp(PlanNode* node, ExecutionContext* context, DB* db)
    : tx(context->tx), db(db), eval_ctx{context, db, nullptr} {
    auto* create = static_cast<CreateEdge*>(node);
    edge_var = create->edge_var;
    src_var = create->src_var;
    dst_var = create->dst_var;
    edge_label_id = context->GetLabelId(create->edge_label, false);
    properties.reserve(create->properties.size());
    for (const auto& [k, v] : create->properties) {
        properties.push_back({k, v.get()});
    }
}

edge_property_t CreateEdgeOp::EvaluateEdgeProperty() {
    // 简化实现：如果有属性表达式，评估第一个作为边权重
    if (properties.empty()) return 1.0;

    auto value = eval_ctx.Evaluate(properties[0].second);
    if (IsInt(value)) {
        return static_cast<edge_property_t>(std::get<int64_t>(value.data));
    } else if (IsFloat(value)) {
        return static_cast<edge_property_t>(std::get<double>(value.data));
    }
    return 1.0;
}

void CreateEdgeOp::Open() {
    is_executed = false;
    current_row.clear();
}

bool CreateEdgeOp::Next() {
    if (is_executed) return false;

    auto child = GetChild();
    if (!child || !child->Next()) {
        is_executed = true;
        return false;
    }

    current_row = child->GetCurrent();
    eval_ctx.current_row = &current_row;

    auto src_it = current_row.find(src_var);
    auto dst_it = current_row.find(dst_var);
    if (src_it == current_row.end() || dst_it == current_row.end()) {
        is_executed = true;
        return false;
    }

    vertex_t src_id = static_cast<vertex_t>(std::get<int64_t>(src_it->second.data));
    vertex_t dst_id = static_cast<vertex_t>(std::get<int64_t>(dst_it->second.data));

    // 创建边
    edge_property_t prop = EvaluateEdgeProperty();
    tx->PutEdge(src_id, dst_id, edge_label_id, prop);

    if (!edge_var.empty()) {
        current_row[edge_var] = EdgePropertyToValue(prop);
    }

    ctx->relationships_created++;
    is_executed = true;
    return true;
}

const std::unordered_map<std::string, Value>& CreateEdgeOp::GetCurrent() const {
    return current_row;
}

void CreateEdgeOp::Close() {
    current_row.clear();
}

// ============================================================================
// DeleteOp - 删除
// ============================================================================

DeleteOp::DeleteOp(PlanNode* node, ExecutionContext* context, DB* db)
    : tx(context->tx), db(db) {
    auto* del = static_cast<DeleteNode*>(node);  // or DeleteEdge
    if (node->GetNodeType() == PlanNodeType::DELETE_EDGE) {
        // 删除边
        DeleteItem item;
        item.is_node = false;
        // TODO: 从 plan 获取边变量信息
        items_to_delete.push_back(item);
    } else {
        // 删除节点
        detach = del->detach;
        DeleteItem item;
        item.is_node = true;
        item.var_name = del->var_name;
        // 尝试获取标签 ID
        item.label_id = 0;  // 0 表示所有标签
        items_to_delete.push_back(item);
    }
}

void DeleteOp::Open() {
    is_executed = false;
}

bool DeleteOp::Next() {
    if (is_executed) return false;

    auto child = GetChild();
    if (!child) {
        is_executed = true;
        return false;
    }

    bool has_rows = false;
    while (child->Next()) {
        has_rows = true;
        last_input_row = child->GetCurrent();

        for (const auto& item : items_to_delete) {
            auto it = last_input_row.find(item.var_name);
            if (it != last_input_row.end() && IsInt(it->second)) {
                if (item.is_node) {
                    vertex_t vid = static_cast<vertex_t>(std::get<int64_t>(it->second.data));
                    tx->DelVertex(vid, item.label_id);
                    ctx->nodes_deleted++;
                } else {
                    // 删除边
                    // TODO: 需要获取 src, dst, label 信息
                    ctx->relationships_deleted++;
                }
            }
        }
    }

    is_executed = true;
    // 对于写操作，不返回行
    return false;
}

const std::unordered_map<std::string, Value>& DeleteOp::GetCurrent() const {
    return last_input_row;
}

void DeleteOp::Close() {
    current_row.clear();
    last_input_row.clear();
}

// ============================================================================
// SetPropertyOp - 设置属性
// ============================================================================

SetPropertyOp::SetPropertyOp(PlanNode* node, ExecutionContext* context, DB* db)
    : tx(context->tx), db(db), eval_ctx{context, db, nullptr} {
    auto* set = static_cast<SetProperty*>(node);
    target_expr = std::move(set->target_expr);
    value_expr = std::move(set->value_expr);
}

void SetPropertyOp::Open() {
    is_executed = false;
}

bool SetPropertyOp::Next() {
    if (is_executed) return false;

    auto child = GetChild();
    if (!child) {
        is_executed = true;
        return false;
    }

    bool has_rows = false;
    while (child->Next()) {
        has_rows = true;
        current_row = child->GetCurrent();
        eval_ctx.current_row = &current_row;

        // 评估目标表达式和值
        // TODO: 实现属性设置逻辑
        // 当前简化：只做评估
        eval_ctx.Evaluate(value_expr.get());
    }

    is_executed = true;
    return has_rows;
}

const std::unordered_map<std::string, Value>& SetPropertyOp::GetCurrent() const {
    return current_row;
}

void SetPropertyOp::Close() {
    current_row.clear();
}

// ============================================================================
// SetLabelsOp - 设置标签
// ============================================================================

SetLabelsOp::SetLabelsOp(PlanNode* node, ExecutionContext* context, DB* db)
    : tx(context->tx), db(db) {
    auto* set = static_cast<SetLabels*>(node);
    var_name = set->var_name;
    for (const auto& label : set->labels) {
        label_t lid = context->GetLabelId(label, true);
        label_ids.push_back(lid);
    }
}

void SetLabelsOp::Open() {
    is_executed = false;
}

bool SetLabelsOp::Next() {
    if (is_executed) return false;

    auto child = GetChild();
    if (!child) {
        is_executed = true;
        return false;
    }

    bool has_rows = false;
    while (child->Next()) {
        has_rows = true;
        current_row = child->GetCurrent();

        // TODO: 实现标签设置逻辑
        // BACH 的当前 API 可能不支持动态添加标签
    }

    is_executed = true;
    return has_rows;
}

const std::unordered_map<std::string, Value>& SetLabelsOp::GetCurrent() const {
    return current_row;
}

void SetLabelsOp::Close() {
    current_row.clear();
}

} // namespace cypher
} // namespace BACH
