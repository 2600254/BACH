/**
 * @file cypher_test.cpp
 * @brief Test suite for BACH Cypher query language module
 */

#include "BACH/cypher/cypher.h"
#include "BACH/db/DB.h"
#include <iostream>
#include <cassert>

using namespace BACH;
using namespace BACH::cypher;

void test_data_types() {
    std::cout << "Testing data types..." << std::endl;

    // Test null value
    Value v1;
    assert(IsNull(v1));
    assert(GetDataType(v1) == DataType::NULL_VALUE);

    // Test boolean
    Value v2 = true;
    assert(IsBool(v2));
    assert(std::get<bool>(v2.data) == true);

    // Test integer
    Value v3 = int64_t(42);
    assert(IsInt(v3));
    assert(std::get<int64_t>(v3.data) == 42);

    // Test float
    Value v4 = 3.14;
    assert(IsFloat(v4));
    assert(std::get<double>(v4.data) == 3.14);

    // Test string
    Value v5 = std::string("Hello");
    assert(IsString(v5));
    assert(std::get<std::string>(v5.data) == "Hello");

    // TODO: Test list and map when constructors are fixed
    // Value v6 = std::vector<Value>{1, 2, 3};
    // Value v7 = std::unordered_map<std::string, Value>{{"key", Value(42)}};

    std::cout << "  Data types OK!" << std::endl;
}

void test_ast_construction() {
    std::cout << "Testing AST construction..." << std::endl;

    // Create a simple query: MATCH (n) RETURN n
    Query query;

    // Add MATCH clause
    auto match_clause = std::make_unique<MatchClause>();
    auto node_pattern = std::make_unique<NodePattern>();
    node_pattern->var_name = "n";
    auto path_pattern = std::make_unique<PathPattern>();
    path_pattern->left_node = std::move(node_pattern);
    match_clause->patterns.push_back(std::move(path_pattern));
    query.clauses.push_back(std::move(match_clause));

    // Add RETURN clause
    auto return_clause = std::make_unique<ReturnClause>();
    ReturnItem item;
    item.expr = std::make_unique<Variable>("n");
    return_clause->return_items.push_back(std::move(item));
    query.clauses.push_back(std::move(return_clause));

    assert(query.clauses.size() == 2);

    std::cout << "  AST construction OK!" << std::endl;
}

void test_expressions() {
    std::cout << "Testing expressions..." << std::endl;

    // Test literal expression
    auto lit = std::make_unique<Literal>(int64_t(42));
    assert(IsInt(lit->value));

    // Test variable expression
    auto var = std::make_unique<Variable>("n");
    assert(var->name == "n");

    // Test property expression
    auto var2 = std::make_unique<Variable>("n");
    auto prop = std::make_unique<Property>(std::move(var2), "name");
    assert(prop->prop_name == "name");

    // Test binary operation
    auto binop = std::make_unique<BinaryOp>(
        BinaryOpType::EQ,
        std::make_unique<Variable>("n"),
        std::make_unique<Literal>(std::string("Alice"))
    );
    assert(binop->op_type == BinaryOpType::EQ);

    // Test function call
    auto func = std::make_unique<FunctionCall>("id", std::vector<ExpressionPtr>{});
    assert(func->func_name == "id");

    std::cout << "  Expressions OK!" << std::endl;
}

void test_execution_plan() {
    std::cout << "Testing execution plan..." << std::endl;

    ExecutionPlan plan;

    // Create a simple plan: AllNodeScan -> Project
    auto scan = std::make_unique<AllNodeScan>();
    scan->output_var = "n";

    auto project = std::make_unique<Project>();
    Project::ProjectionItem pitem;
    pitem.expr = std::make_unique<Variable>("n");
    pitem.alias = "n";
    project->projections.push_back(std::move(pitem));
    project->children.push_back(std::move(scan));

    plan.root = std::move(project);

    assert(plan.root != nullptr);
    assert(plan.root->GetNodeType() == PlanNodeType::PROJECT);

    auto nodes = plan.GetAllNodes();
    assert(nodes.size() == 2);

    std::cout << "  Execution plan OK!" << std::endl;
}

void test_symbol_table() {
    std::cout << "Testing symbol table..." << std::endl;

    SymbolTable table;

    table.EnterScope();
    table.AddSymbol("n", DataType::INTEGER, true);
    table.AddSymbol("m", DataType::INTEGER, true);

    assert(table.Exists("n"));
    assert(table.Exists("m"));
    assert(!table.Exists("x"));

    auto* info = table.Lookup("n");
    assert(info != nullptr);
    assert(info->name == "n");
    assert(info->is_node == true);

    table.LeaveScope();

    std::cout << "  Symbol table OK!" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "BACH Cypher Module Test Suite" << std::endl;
    std::cout << "========================================" << std::endl;

    try {
        test_data_types();
        test_ast_construction();
        test_expressions();
        test_execution_plan();
        test_symbol_table();

        std::cout << "========================================" << std::endl;
        std::cout << "All tests passed!" << std::endl;
        std::cout << "========================================" << std::endl;
        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}
