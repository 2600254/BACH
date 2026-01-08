#pragma once

#include "../parser/ast.h"
#include "../parser/clause.h"
#include "execution_plan.h"
#include "BACH/db/DB.h"
#include <memory>

namespace BACH {
namespace cypher {

// 查询规划器
// 负责将 AST 转换为可执行的执行计划
class Planner {
public:
    Planner();
    ~Planner();

    // 从 AST 构建执行计划
    std::unique_ptr<ExecutionPlan> Plan(const Query& query);

    // 设置数据库连接（用于优化时访问元数据）
    void SetDatabase(::BACH::DB* db) { database = db; }

private:
    ::BACH::DB* database = nullptr;

    // 规划各个子句
    std::unique_ptr<PlanNode> PlanMatchClause(const MatchClause& clause);
    std::unique_ptr<PlanNode> PlanReturnClause(const ReturnClause& clause);
    std::unique_ptr<PlanNode> PlanCreateClause(const CreateClause& clause);
    std::unique_ptr<PlanNode> PlanDeleteClause(const DeleteClause& clause);
    std::unique_ptr<PlanNode> PlanSetClause(const SetClause& clause);

    // 优化规则
    void Optimize(ExecutionPlan* plan);
};

} // namespace cypher
} // namespace BACH
