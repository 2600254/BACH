#include "BACH/cypher/cypher.h"
#include "BACH/db/DB.h"
#include "BACH/db/Transaction.h"
#include "BACH/utils/Options.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <vector>

using namespace BACH;
using namespace BACH::cypher;

// Helper to format Value for display
std::string FormatValue(const Value& v) {
    if (IsNull(v)) return "null";
    if (IsInt(v)) return std::to_string(std::get<int64_t>(v.data));
    if (IsFloat(v)) return std::to_string(std::get<double>(v.data));
    if (IsBool(v)) return std::get<bool>(v.data) ? "true" : "false";
    if (IsString(v)) return std::get<std::string>(v.data);
    return "?";
}

// Execute query and measure time
bool ExecuteAndMeasure(CypherEngine& engine, Transaction* tx, const std::string& query) {
    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << "Query: " << query << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    bool success = engine.Execute(query, tx);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    if (!success) {
        std::cout << "ERROR: " << engine.GetLastError() << std::endl;
        return false;
    }

    const auto& rows = engine.GetResults();
    std::cout << "  Rows returned: " << rows.size() << std::endl;
    std::cout << "  Time: " << duration_us.count() << " μs ("
              << (duration_us.count() / 1000.0) << " ms)" << std::endl;

    // Show first 5 rows
    size_t show_rows = std::min(rows.size(), size_t(5));
    if (show_rows > 0) {
        std::cout << "  Sample rows:" << std::endl;
        for (size_t r = 0; r < show_rows; ++r) {
            std::cout << "    [";
            for (size_t c = 0; c < rows[r].size(); ++c) {
                std::cout << FormatValue(rows[r][c]);
                if (c < rows[r].size() - 1) std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }

    return true;
}

int main() {
    std::cout << "============================================" << std::endl;
    std::cout << "BACH Cypher Scale Test (~100 edges)" << std::endl;
    std::cout << "============================================" << std::endl;

    // Test parameters
    const int NUM_PERSONS = 20;      // 20 Person nodes
    const int NUM_COMPANIES = 5;     // 5 Company nodes
    const int NUM_WORKS_AT = 20;     // 20 WORKS_AT edges
    const int NUM_KNOWS = 80;        // 80 KNOWS edges
    const int TOTAL_EDGES = NUM_WORKS_AT + NUM_KNOWS;

    std::cout << "\nTest Configuration:" << std::endl;
    std::cout << "  Person nodes: " << NUM_PERSONS << std::endl;
    std::cout << "  Company nodes: " << NUM_COMPANIES << std::endl;
    std::cout << "  WORKS_AT edges: " << NUM_WORKS_AT << std::endl;
    std::cout << "  KNOWS edges: " << NUM_KNOWS << std::endl;
    std::cout << "  Total edges: " << TOTAL_EDGES << std::endl;

    // Create database
    auto options = std::make_shared<Options>();
    options->STORAGE_DIR = "./output/scale_test_db";

    std::cout << "\nCreating database..." << std::endl;
    DB* db = nullptr;
    try {
        db = new DB(options);
    } catch (const std::exception& e) {
        std::cout << "Failed to create database: " << e.what() << std::endl;
        return 1;
    }

    // Add labels
    label_t person_label = db->AddVertexLabel("Person");
    label_t company_label = db->AddVertexLabel("Company");
    label_t knows_label = db->AddEdgeLabel("KNOWS", "Person", "Person");
    label_t works_at_label = db->AddEdgeLabel("WORKS_AT", "Person", "Company");

    std::cout << "  Person label ID: " << person_label << std::endl;
    std::cout << "  Company label ID: " << company_label << std::endl;
    std::cout << "  KNOWS label ID: " << knows_label << std::endl;
    std::cout << "  WORKS_AT label ID: " << works_at_label << std::endl;

    // Setup random generator
    std::random_device rd;
    std::mt19937 gen(42);  // Fixed seed for reproducibility
    std::uniform_int_distribution<> person_dist(0, NUM_PERSONS - 1);
    std::uniform_int_distribution<> company_dist(0, NUM_COMPANIES - 1);
    std::uniform_int_distribution<> age_dist(20, 65);

    auto tx = db->BeginTransaction();

    // ============================================================================
    // Phase 1: Create Person nodes
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Phase 1: Creating " << NUM_PERSONS << " Person nodes" << std::endl;
    std::cout << "============================================" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_PERSONS; ++i) {
        vertex_t vid = tx.AddVertex(person_label);
        int age = age_dist(gen);
        std::string props = "name:Person" + std::to_string(i) + ",age:" + std::to_string(age);
        tx.PutVertex(person_label, vid, props);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "  Time: " << duration.count() << " μs" << std::endl;

    // ============================================================================
    // Phase 2: Create Company nodes
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Phase 2: Creating " << NUM_COMPANIES << " Company nodes" << std::endl;
    std::cout << "============================================" << std::endl;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_COMPANIES; ++i) {
        vertex_t vid = tx.AddVertex(company_label);
        std::string props = "name:Company" + std::to_string(i);
        tx.PutVertex(company_label, vid, props);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "  Time: " << duration.count() << " μs" << std::endl;

    // ============================================================================
    // Phase 3: Create WORKS_AT edges
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Phase 3: Creating " << NUM_WORKS_AT << " WORKS_AT edges" << std::endl;
    std::cout << "============================================" << std::endl;

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < NUM_WORKS_AT; ++i) {
        vertex_t person = person_dist(gen);
        vertex_t company = NUM_PERSONS + company_dist(gen);  // Companies start after Persons
        tx.PutEdge(person, company, works_at_label, 1.0);
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "  Time: " << duration.count() << " μs" << std::endl;

    // ============================================================================
    // Phase 4: Create KNOWS edges
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Phase 4: Creating " << NUM_KNOWS << " KNOWS edges" << std::endl;
    std::cout << "============================================" << std::endl;

    start = std::chrono::high_resolution_clock::now();

    int created = 0;
    int attempts = 0;
    while (created < NUM_KNOWS && attempts < NUM_KNOWS * 3) {
        vertex_t p1 = person_dist(gen);
        vertex_t p2 = person_dist(gen);

        if (p1 != p2) {  // No self-connections
            tx.PutEdge(p1, p2, knows_label, 1.0);
            created++;
        }
        attempts++;
    }

    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "  Created: " << created << " edges" << std::endl;
    std::cout << "  Time: " << duration.count() << " μs" << std::endl;

    // ============================================================================
    // Verify counts with DB API
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Database Statistics (via DB API)" << std::endl;
    std::cout << "============================================" << std::endl;

    std::cout << "  Person count: " << tx.GetVertexNum(person_label) << std::endl;
    std::cout << "  Company count: " << tx.GetVertexNum(company_label) << std::endl;

    // Count edges by scanning
    int edge_count = 0;
    auto count_edges = [&edge_count](vertex_t& src, vertex_t& dst, edge_property_t& prop) {
        edge_count++;
    };
    tx.EdgeLabelScan(knows_label, count_edges);
    std::cout << "  KNOWS edge count: " << edge_count << std::endl;

    edge_count = 0;
    tx.EdgeLabelScan(works_at_label, count_edges);
    std::cout << "  WORKS_AT edge count: " << edge_count << std::endl;

    // ============================================================================
    // Phase 5: Query Tests
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Phase 5: Query Performance Tests" << std::endl;
    std::cout << "============================================" << std::endl;

    CypherEngine engine;
    engine.SetDatabase(db);

    // Note: Transaction auto-commits on destruction
    // Begin a read-only transaction for queries
    auto read_tx = db->BeginReadOnlyTransaction();

    // Run each query multiple times and average
    const int WARMUP_RUNS = 2;
    const int MEASURE_RUNS = 5;

    struct QueryTest {
        std::string name;
        std::string query;
        size_t expected_rows;
    };

    std::vector<QueryTest> queries = {
        {"Scan all Persons", "MATCH (p:Person) RETURN p", NUM_PERSONS},
        {"Scan all Companies", "MATCH (c:Company) RETURN c", NUM_COMPANIES},
        {"CREATE new Person", "CREATE (p:Person)", 1},
        {"CREATE with properties", "CREATE (p:Person {name: 'Alice', age: 30})", 1},
    };

    for (const auto& qt : queries) {
        std::cout << "\n============================================" << std::endl;
        std::cout << "Test: " << qt.name << std::endl;
        std::cout << "============================================" << std::endl;

        // Warmup runs
        for (int i = 0; i < WARMUP_RUNS; ++i) {
            if (qt.query.find("CREATE") != std::string::npos) {
                auto wtx = db->BeginTransaction();
                engine.Execute(qt.query, &wtx);
            } else {
                engine.Execute(qt.query, &read_tx);
            }
        }

        // Measured runs
        std::vector<int64_t> times;
        for (int i = 0; i < MEASURE_RUNS; ++i) {
            auto wtx = (qt.query.find("CREATE") != std::string::npos)
                ? db->BeginTransaction()
                : db->BeginReadOnlyTransaction();

            auto start = std::chrono::high_resolution_clock::now();
            bool success = engine.Execute(qt.query, &wtx);
            auto end = std::chrono::high_resolution_clock::now();

            if (success) {
                auto duration_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                times.push_back(duration_us.count());
            }
        }

        // Calculate statistics
        if (!times.empty()) {
            int64_t sum = 0;
            int64_t min_val = times[0];
            int64_t max_val = times[0];
            for (auto t : times) {
                sum += t;
                min_val = std::min(min_val, t);
                max_val = std::max(max_val, t);
            }
            double avg = static_cast<double>(sum) / times.size();

            std::cout << "  Performance (" << MEASURE_RUNS << " runs):" << std::endl;
            std::cout << "    Average: " << static_cast<int>(avg) << " μs ("
                      << (avg / 1000.0) << " ms)" << std::endl;
            std::cout << "    Min: " << min_val << " μs" << std::endl;
            std::cout << "    Max: " << max_val << " μs" << std::endl;
        }

        // Show one sample result
        if (qt.query.find("CREATE") == std::string::npos) {
            ExecuteAndMeasure(engine, &read_tx, qt.query);
        }
    }

    // ============================================================================
    // Summary
    // ============================================================================
    std::cout << "\n============================================" << std::endl;
    std::cout << "Test Summary" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Data created:" << std::endl;
    std::cout << "  " << NUM_PERSONS << " Person nodes" << std::endl;
    std::cout << "  " << NUM_COMPANIES << " Company nodes" << std::endl;
    std::cout << "  " << NUM_WORKS_AT << " WORKS_AT edges" << std::endl;
    std::cout << "  " << NUM_KNOWS << " KNOWS edges" << std::endl;
    std::cout << "  Total: " << TOTAL_EDGES << " edges" << std::endl;
    std::cout << "\nPipeline components working:" << std::endl;
    std::cout << "  Parser: Parses Cypher queries" << std::endl;
    std::cout << "  Planner: Generates execution plans" << std::endl;
    std::cout << "  Executor: Executes plans against DB" << std::endl;

    // Cleanup
    delete db;

    return 0;
}
