#include "BACH/cypher/planner/execution_plan.h"
#include <sstream>

namespace BACH {
namespace cypher {

// ============================================================================
// ExecutionPlan
// ============================================================================

std::string ExecutionPlan::ToString() const {
    std::ostringstream oss;
    ToStringHelper(oss, root.get(), 0);
    return oss.str();
}

void ExecutionPlan::ToStringHelper(std::ostringstream& oss, const PlanNode* node, int indent) const {
    if (!node) return;

    for (int i = 0; i < indent; ++i) oss << "  ";
    oss << node->ToString() << "\n";

    for (const auto& child : node->children) {
        ToStringHelper(oss, child.get(), indent + 1);
    }
}

std::vector<const PlanNode*> ExecutionPlan::GetAllNodes() const {
    std::vector<const PlanNode*> result;
    CollectNodes(root.get(), result);
    return result;
}

void ExecutionPlan::CollectNodes(const PlanNode* node, std::vector<const PlanNode*>& result) const {
    if (!node) return;
    result.push_back(node);
    for (const auto& child : node->children) {
        CollectNodes(child.get(), result);
    }
}

} // namespace cypher
} // namespace BACH
