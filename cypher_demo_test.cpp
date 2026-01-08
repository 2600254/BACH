#include "BACH/db/DB.h"
#include "BACH/db/Transaction.h"
#include "BACH/cypher/cypher.h"
#include <iostream>

using namespace BACH;

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "BACH Cypher Query Language Demo" << std::endl;
    std::cout << "========================================" << std::endl;

    try {
        // Create database
        auto options = std::make_shared<Options>();
        options->STORAGE_DIR = "./demo_db";
        DB* database = new DB(options);

        // Set up labels
        label_t person_label = database->AddVertexLabel("Person");
        label_t company_label = database->AddVertexLabel("Company");
        label_t knows_label = database->AddEdgeLabel("KNOWS", "Person", "Person");
        label_t works_at_label = database->AddEdgeLabel("WORKS_AT", "Person", "Company");

        // Add sample data
        {
            auto tx = database->BeginTransaction();

            // Add Person nodes
            vertex_t alice = tx.AddVertex(person_label);
            tx.PutVertex(person_label, alice, R"({"name": "Alice", "age": 30})");

            vertex_t bob = tx.AddVertex(person_label);
            tx.PutVertex(person_label, bob, R"({"name": "Bob", "age": 25})");

            vertex_t charlie = tx.AddVertex(person_label);
            tx.PutVertex(person_label, charlie, R"({"name": "Charlie", "age": 35})");

            // Add Company node
            vertex_t company = tx.AddVertex(company_label);
            tx.PutVertex(company_label, company, R"({"name": "TechCorp"})");

            // Add edges
            tx.PutEdge(alice, bob, knows_label, 1.0);
            tx.PutEdge(bob, charlie, knows_label, 1.0);
            tx.PutEdge(alice, charlie, knows_label, 0.5);
            tx.PutEdge(alice, company, works_at_label, 1.0);
            tx.PutEdge(bob, company, works_at_label, 1.0);
        }

        std::cout << "\nSample data created." << std::endl;
        std::cout << "  - 3 Person nodes (Alice, Bob, Charlie)" << std::endl;
        std::cout << "  - 1 Company node (TechCorp)" << std::endl;
        std::cout << "  - 5 edges" << std::endl;

        // Create CypherEngine
        std::cout << "\n========================================" << std::endl;
        std::cout << "Cypher Query Examples" << std::endl;
        std::cout << "========================================" << std::endl;

        cypher::CypherEngine engine;
        engine.SetDatabase(database);

        // Note: The parser is not fully implemented yet
        // These examples show how the engine would be used
        std::cout << "\nNote: The ANTLR4-based parser is not fully implemented." << std::endl;
        std::cout << "The parser/planner/executor pipeline architecture is in place." << std::endl;
        std::cout << "\nExample Cypher queries (when parser is complete):" << std::endl;
        std::cout << "  1. MATCH (n:Person) RETURN n" << std::endl;
        std::cout << "  2. MATCH (a:Person)-[r:KNOWS]->(b:Person) RETURN a, b" << std::endl;
        std::cout << "  3. MATCH (n:Person {name: 'Alice'}) RETURN n" << std::endl;
        std::cout << "  4. CREATE (n:Person {name: 'Dave', age: 28})" << std::endl;

        // Direct database query for comparison
        std::cout << "\n========================================" << std::endl;
        std::cout << "Direct Database Query (for comparison)" << std::endl;
        std::cout << "========================================" << std::endl;

        {
            auto tx = database->BeginReadOnlyTransaction();
            vertex_num_t num = tx.GetVertexNum(person_label);
            std::cout << "\nDirect API result: " << num << " Person nodes" << std::endl;
        }

        // Clean up
        delete database;

        std::cout << "\n========================================" << std::endl;
        std::cout << "Demo completed successfully!" << std::endl;
        std::cout << "========================================" << std::endl;

        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
