#pragma once

/**
 * @file cypher.h
 * @brief BACH Cypher Query Language Module
 *
 * This module provides Cypher query language support for the BACH graph database.
 * It supports the following Cypher clauses:
 * - MATCH: Pattern matching
 * - WHERE: Filtering
 * - RETURN: Result projection
 * - CREATE: Create nodes and relationships
 * - DELETE: Delete nodes and relationships
 * - SET: Set properties and labels
 */

#include "parser/cypher_parser.h"
#include "parser/ast.h"
#include "parser/expression.h"
#include "parser/clause.h"
#include "parser/symbol_table.h"
#include "planner/planner.h"
#include "planner/execution_plan.h"
#include "executor/executor.h"
#include "executor/ops/op.h"

namespace BACH {
namespace cypher {

/**
 * @brief Cypher query engine
 *
 * Main entry point for executing Cypher queries against BACH database.
 */
class CypherEngine {
public:
    CypherEngine();
    ~CypherEngine();

    /**
     * @brief Execute a Cypher query
     * @param query The Cypher query string
     * @param tx The transaction to use
     * @return true if execution succeeded, false otherwise
     */
    bool Execute(const std::string& query, class Transaction* tx);

    /**
     * @brief Get the query results
     * @return Vector of result rows
     */
    const std::vector<std::vector<Value>>& GetResults() const {
        return exec_ctx.result_rows;
    }

    /**
     * @brief Get the result column names
     * @return Vector of column names
     */
    const std::vector<std::string>& GetColumns() const {
        return exec_ctx.result_columns;
    }

    /**
     * @brief Get execution statistics
     * @return Statistics string
     */
    std::string GetStats() const;

    /**
     * @brief Get the last error message
     * @return Error message string
     */
    std::string GetLastError() const { return last_error; }

private:
    std::unique_ptr<CypherParser> parser;
    std::unique_ptr<Planner> planner;
    std::unique_ptr<Executor> executor;

    ExecutionContext exec_ctx;
    std::string last_error;
};

/**
 * @brief Convenience function to execute a Cypher query
 *
 * @param db The database instance
 * @param query The Cypher query string
 * @param results Output parameter for results
 * @return true if successful, false otherwise
 */
bool ExecuteCypher(class DB* db, const std::string& query,
                   std::vector<std::vector<Value>>& results);

} // namespace cypher
} // namespace BACH
