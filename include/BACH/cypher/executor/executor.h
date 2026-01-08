#pragma once

#include "../planner/execution_plan.h"
#include "ops/op.h"
#include "BACH/db/DB.h"
#include "BACH/db/Transaction.h"
#include "BACH/label/LabelManager.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace BACH {
namespace cypher {

// 执行上下文 - 保存执行过程中的状态
struct ExecutionContext {
    Transaction* tx = nullptr;  // 当前事务
    DB* db = nullptr;           // 数据库指针

    // 符号表（变量名 -> 值）
    std::unordered_map<std::string, Value> symbols;

    // 当前行数据（用于流水线传递）
    std::unordered_map<std::string, Value> current_row;

    // 结果收集
    std::vector<std::vector<Value>> result_rows;
    std::vector<std::string> result_columns;

    // 统计信息
    size_t nodes_created = 0;
    size_t nodes_deleted = 0;
    size_t relationships_created = 0;
    size_t relationships_deleted = 0;

    // 清空上下文
    void Reset() {
        symbols.clear();
        current_row.clear();
        result_rows.clear();
        result_columns.clear();
        nodes_created = 0;
        nodes_deleted = 0;
        relationships_created = 0;
        relationships_deleted = 0;
    }

    // 获取 Label ID（辅助函数）
    label_t GetLabelId(const std::string& label_name, bool is_vertex) const;
};

// 执行引擎 - 负责执行执行计划
class Executor {
public:
    Executor();
    ~Executor();

    // 执行计划并返回结果
    bool Execute(ExecutionPlan* plan, Transaction* tx, ExecutionContext* ctx);

    // 设置数据库
    void SetDatabase(DB* db) { database = db; }

    // 获取统计信息
    std::string GetStats(const ExecutionContext& ctx) const;

private:
    DB* database = nullptr;

    // 执行单个计划节点
    bool ExecuteNode(PlanNode* node, ExecutionContext* ctx);

    // 创建操作符
    std::unique_ptr<Operator> CreateOperator(PlanNode* node, ExecutionContext* ctx);
};

} // namespace cypher
} // namespace BACH
