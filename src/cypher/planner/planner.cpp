#include "BACH/cypher/planner/planner.h"
#include "BACH/cypher/parser/clause.h"
#include "BACH/cypher/parser/expression.h"
#include "BACH/db/DB.h"
#include <iostream>

namespace BACH {
namespace cypher {

Planner::Planner() = default;

Planner::~Planner() = default;

std::unique_ptr<ExecutionPlan> Planner::Plan(const Query& query) {
    auto plan = std::make_unique<ExecutionPlan>();

    if (query.clauses.empty()) {
        return plan;
    }

    // 处理每个子句，构建执行计划
    std::unique_ptr<PlanNode> current_root = nullptr;

    for (const auto& clause : query.clauses) {
        switch (clause->GetNodeType()) {
            case ASTNodeType::MATCH_CLAUSE:
                {
                    auto* match_clause = static_cast<MatchClause*>(clause.get());
                    auto match_plan = PlanMatchClause(*match_clause);
                    if (match_plan) {
                        if (current_root) {
                            match_plan->children.push_back(std::move(current_root));
                        }
                        current_root = std::move(match_plan);
                    }
                }
                break;

            case ASTNodeType::CREATE_CLAUSE:
                {
                    auto* create_clause = static_cast<CreateClause*>(clause.get());
                    auto create_plan = PlanCreateClause(*create_clause);
                    if (create_plan) {
                        if (current_root) {
                            create_plan->children.push_back(std::move(current_root));
                        }
                        current_root = std::move(create_plan);
                    }
                }
                break;

            case ASTNodeType::DELETE_CLAUSE:
                {
                    auto* delete_clause = static_cast<DeleteClause*>(clause.get());
                    auto delete_plan = PlanDeleteClause(*delete_clause);
                    if (delete_plan) {
                        if (current_root) {
                            delete_plan->children.push_back(std::move(current_root));
                        }
                        current_root = std::move(delete_plan);
                    }
                }
                break;

            case ASTNodeType::SET_CLAUSE:
                {
                    auto* set_clause = static_cast<SetClause*>(clause.get());
                    auto set_plan = PlanSetClause(*set_clause);
                    if (set_plan) {
                        if (current_root) {
                            set_plan->children.push_back(std::move(current_root));
                        }
                        current_root = std::move(set_plan);
                    }
                }
                break;

            case ASTNodeType::RETURN_CLAUSE:
                {
                    auto* return_clause = static_cast<ReturnClause*>(clause.get());
                    auto return_plan = PlanReturnClause(*return_clause);
                    if (return_plan) {
                        if (current_root) {
                            return_plan->children.push_back(std::move(current_root));
                        }
                        current_root = std::move(return_plan);
                    }
                }
                break;

            default:
                std::cerr << "Warning: Unsupported clause type in planner" << std::endl;
                break;
        }
    }

    plan->root = std::move(current_root);

    // 运行优化规则
    Optimize(plan.get());

    return plan;
}

std::unique_ptr<PlanNode> Planner::PlanMatchClause(const MatchClause& clause) {
    // 简化实现：只支持单节点模式或简单的路径模式
    std::unique_ptr<PlanNode> root = nullptr;

    if (clause.patterns.empty()) {
        return nullptr;
    }

    // 处理第一个模式
    const auto& pattern = clause.patterns[0];

    if (pattern->left_node) {
        // 创建左节点的扫描
        auto scan = std::make_unique<AllNodeScan>();
        scan->output_var = pattern->left_node->var_name.empty() ?
                           "_node" : pattern->left_node->var_name;
        if (!pattern->left_node->label.empty()) {
            scan->label_filter = pattern->left_node->label;
        }
        root = std::move(scan);
    }

    if (pattern->relationship && pattern->right_node) {
        // 创建边展开
        auto expand = std::make_unique<Expand>();
        expand->src_var = pattern->left_node->var_name.empty() ?
                         "_node" : pattern->left_node->var_name;
        expand->dst_var = pattern->right_node->var_name.empty() ?
                         "_dst" : pattern->right_node->var_name;

        if (pattern->relationship) {
            expand->edge_var = pattern->relationship->var_name;
            expand->edge_label = pattern->relationship->label;

            // 设置方向
            if (pattern->relationship->direction == RelationshipPattern::Direction::RIGHT) {
                expand->direction = Expand::Direction::OUT;
            } else if (pattern->relationship->direction == RelationshipPattern::Direction::LEFT) {
                expand->direction = Expand::Direction::IN;
            } else {
                expand->direction = Expand::Direction::BOTH;
            }
        }

        expand->children.push_back(std::move(root));
        root = std::move(expand);
    }

    // 处理 WHERE 子句
    if (clause.where) {
        auto filter = std::make_unique<Filter>();
        // Move the condition - we can't clone, so we take ownership
        // Note: This modifies the AST, which is not ideal but works for now
        filter->condition = std::move(const_cast<ExpressionPtr&>(clause.where));
        filter->children.push_back(std::move(root));
        root = std::move(filter);
    }

    return root;
}

std::unique_ptr<PlanNode> Planner::PlanReturnClause(const ReturnClause& clause) {
    auto project = std::make_unique<Project>();
    project->distinct = clause.distinct;

    if (clause.is_star) {
        // RETURN * - 返回所有列
        auto item = std::make_unique<Variable>("*");
        project->projections.push_back({std::move(item), "*"});
    } else {
        for (const auto& return_item : clause.return_items) {
            std::string alias = return_item.is_alias_set() ?
                               return_item.alias : "";
            // Move the expression - we can't clone
            project->projections.push_back({std::move(const_cast<ExpressionPtr&>(return_item.expr)), alias});
        }
    }

    return project;
}

std::unique_ptr<PlanNode> Planner::PlanCreateClause(const CreateClause& clause) {
    std::unique_ptr<PlanNode> root = nullptr;

    if (clause.patterns.empty()) {
        return nullptr;
    }

    // 处理第一个模式
    const auto& pattern = clause.patterns[0];

    // 创建左节点
    if (pattern->left_node) {
        auto create_node = std::make_unique<CreateNode>();
        create_node->var_name = pattern->left_node->var_name.empty() ?
                               "_node" : pattern->left_node->var_name;
        create_node->label = pattern->left_node->label;

        root = std::move(create_node);
    }

    // 创建边
    if (pattern->relationship && pattern->right_node) {
        // 先创建右节点
        auto create_dst = std::make_unique<CreateNode>();
        create_dst->var_name = pattern->right_node->var_name.empty() ?
                               "_dst" : pattern->right_node->var_name;
        create_dst->label = pattern->right_node->label;

        // 创建边
        auto create_edge = std::make_unique<CreateEdge>();
        create_edge->edge_var = pattern->relationship->var_name;
        create_edge->src_var = root ? pattern->left_node->var_name : "_node";
        create_edge->dst_var = create_dst->var_name;
        create_edge->edge_label = pattern->relationship->label;

        create_edge->children.push_back(std::move(root));
        create_dst->children.push_back(std::move(create_edge));
        root = std::move(create_dst);
    }

    return root;
}

std::unique_ptr<PlanNode> Planner::PlanDeleteClause(const DeleteClause& clause) {
    auto delete_node = std::make_unique<DeleteNode>();
    delete_node->detach = clause.detach;

    // 从表达式中提取变量名
    if (!clause.expressions.empty()) {
        auto* var_expr = static_cast<Variable*>(clause.expressions[0].get());
        if (var_expr) {
            delete_node->var_name = var_expr->name;
        }
    }

    return delete_node;
}

std::unique_ptr<PlanNode> Planner::PlanSetClause(const SetClause& clause) {
    if (clause.items.empty()) {
        return nullptr;
    }

    const auto& item = clause.items[0];

    if (item.type == SetPropertyItem::SetType::LABELS) {
        auto set_labels = std::make_unique<SetLabels>();
        set_labels->labels = item.labels;
        return set_labels;
    } else {
        auto set_prop = std::make_unique<SetProperty>();
        // Move the expressions - we can't clone
        set_prop->target_expr = std::move(const_cast<ExpressionPtr&>(item.expr));
        set_prop->value_expr = std::move(const_cast<ExpressionPtr&>(item.value));
        return set_prop;
    }
}

void Planner::Optimize(ExecutionPlan* plan) {
    // 简化实现：暂时不做优化
    // 未来可以添加：
    // - 谓词下推
    // - 投影剪枝
    // - 索引扫描选择
    // 等
}

} // namespace cypher
} // namespace BACH
