/**
 * @file cypher_interactive_test.cpp
 * @brief Interactive test for BACH database (basic operations)
 */

#include "BACH/db/DB.h"
#include "BACH/db/Transaction.h"
#include <iostream>
#include <string>
#include <memory>

using namespace BACH;

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "BACH Database Interface" << std::endl;
    std::cout << "========================================" << std::endl;

    // Initialize database
    auto options = std::make_shared<Options>();
    options->STORAGE_DIR = "./test_db";

    std::cout << "Opening database at: " << options->STORAGE_DIR << std::endl;

    try {
        // Use BACH::DB directly
        DB* database = new DB(options);

        // Add some labels
        label_t person_label = database->AddVertexLabel("Person");
        label_t company_label = database->AddVertexLabel("Company");
        label_t knows_label = database->AddEdgeLabel("KNOWS", "Person", "Person");
        label_t works_at_label = database->AddEdgeLabel("WORKS_AT", "Person", "Company");

        std::cout << "Added labels:" << std::endl;
        std::cout << "  Person: " << person_label << std::endl;
        std::cout << "  Company: " << company_label << std::endl;
        std::cout << "  KNOWS: " << knows_label << std::endl;
        std::cout << "  WORKS_AT: " << works_at_label << std::endl;

        // Declare vertex IDs outside the transaction block
        vertex_t alice, bob, charlie, company;

        // Create some sample data
        {
            auto tx = database->BeginTransaction();

            // Add Person nodes
            alice = tx.AddVertex(person_label);
            tx.PutVertex(person_label, alice, R"({"name": "Alice", "age": 30})");

            bob = tx.AddVertex(person_label);
            tx.PutVertex(person_label, bob, R"({"name": "Bob", "age": 25})");

            charlie = tx.AddVertex(person_label);
            tx.PutVertex(person_label, charlie, R"({"name": "Charlie", "age": 35})");

            // Add Company node
            company = tx.AddVertex(company_label);
            tx.PutVertex(company_label, company, R"({"name": "TechCorp"})");

            // Add edges
            tx.PutEdge(alice, bob, knows_label, 1.0);
            tx.PutEdge(bob, charlie, knows_label, 1.0);
            tx.PutEdge(alice, charlie, knows_label, 0.5);
            tx.PutEdge(alice, company, works_at_label, 1.0);
            tx.PutEdge(bob, company, works_at_label, 1.0);

            // Transaction auto-commits on destruction
            std::cout << "\nAdded sample data:" << std::endl;
            std::cout << "  3 Person nodes (Alice, Bob, Charlie)" << std::endl;
            std::cout << "  1 Company node (TechCorp)" << std::endl;
            std::cout << "  5 edges" << std::endl;
        }

        // Query test
        std::cout << "\n========================================" << std::endl;
        std::cout << "Query Test" << std::endl;
        std::cout << "========================================" << std::endl;

        {
            auto tx = database->BeginReadOnlyTransaction();

            // Test vertex scan
            std::cout << "\n1. Vertex Scan Test:" << std::endl;
            vertex_t num_vertices = tx.GetVertexNum(person_label);
            std::cout << "   Person nodes: " << num_vertices << std::endl;

            // Test get vertex
            std::cout << "\n2. Get Vertex Test:" << std::endl;
            auto alice_prop = tx.GetVertex(alice, person_label);
            if (alice_prop) {
                std::cout << "   Alice properties: " << *alice_prop << std::endl;
            }

            // Test get edges
            std::cout << "\n3. Get Edges Test:" << std::endl;
            auto alice_edges = tx.GetEdges(alice, knows_label);
            if (alice_edges) {
                std::cout << "   Alice's KNOWS edges: " << alice_edges->size() << std::endl;
                for (const auto& [dst, prop] : *alice_edges) {
                    std::cout << "     -> vertex " << dst << " (weight: " << prop << ")" << std::endl;
                }
            }
        }

        std::cout << "\n========================================" << std::endl;
        std::cout << "Test completed successfully!" << std::endl;
        std::cout << "========================================" << std::endl;

        delete database;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
