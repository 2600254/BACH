#include "BACH/cypher/cypher.h"
#include "BACH/db/DB.h"
#include "BACH/db/Transaction.h"
#include <sstream>

namespace BACH {
namespace cypher {

CypherEngine::CypherEngine()
    : parser(std::make_unique<CypherParser>()),
      planner(std::make_unique<Planner>()),
      executor(std::make_unique<Executor>()) {
}

CypherEngine::~CypherEngine() = default;

bool CypherEngine::Execute(const std::string& query, class Transaction* tx) {
    // Reset execution context
    exec_ctx.Reset();
    last_error.clear();

    if (!tx) {
        last_error = "Transaction is null";
        return false;
    }

    // 1. Parse the query
    auto ast = parser->Parse(query);
    if (!ast) {
        last_error = "Parse error: " + parser->GetLastError();
        return false;
    }

    // 2. Plan the query
    auto plan = planner->Plan(*ast);
    if (!plan || !plan->root) {
        last_error = "Planning failed: empty execution plan";
        return false;
    }

    // 3. Set up execution context
    // Note: The db pointer should be set externally or via Execute overload
    exec_ctx.tx = tx;

    executor->SetDatabase(exec_ctx.db);
    planner->SetDatabase(exec_ctx.db);

    // 4. Execute the plan
    if (!executor->Execute(plan.get(), tx, &exec_ctx)) {
        last_error = "Execution failed";
        return false;
    }

    return true;
}

std::string CypherEngine::GetStats() const {
    std::ostringstream oss;
    oss << "Nodes created: " << exec_ctx.nodes_created << "\n";
    oss << "Nodes deleted: " << exec_ctx.nodes_deleted << "\n";
    oss << "Relationships created: " << exec_ctx.relationships_created << "\n";
    oss << "Relationships deleted: " << exec_ctx.relationships_deleted << "\n";
    oss << "Rows returned: " << exec_ctx.result_rows.size() << "\n";
    return oss.str();
}

// Convenience function
bool ExecuteCypher(class DB* db, const std::string& query,
                   std::vector<std::vector<Value>>& results) {
    if (!db) {
        return false;
    }

    // Begin a read-only transaction
    auto tx = db->BeginReadOnlyTransaction();

    // Create engine and execute
    CypherEngine engine;
    if (!engine.Execute(query, &tx)) {
        return false;
    }

    // Copy results
    results = engine.GetResults();

    return true;
}

} // namespace cypher
} // namespace BACH
