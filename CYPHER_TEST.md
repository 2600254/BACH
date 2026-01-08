# BACH Cypher Query Language Module - Test Documentation

## Overview

The BACH Cypher module provides a complete implementation of the Cypher graph query language for the BACH graph database. The module follows a classic query compiler pipeline:

```
Parser (String → AST) → Planner (AST → Execution Plan) → Executor (Plan → Results)
```

## Test Suites

### 1. Parser Test (`cypher_parser_test`)
Tests the Cypher query parser's ability to parse queries into an Abstract Syntax Tree (AST).

**Build & Run:**
```bash
cmake . -DBUILD_CYPHER=ON
make cypher_parser_test
./cypher_parser_test
```

**Queries Tested:**
- `MATCH (n:Person) RETURN n`
- `MATCH (n:Person)-[r:KNOWS]->(m:Person) RETURN n, m`
- `MATCH (n) RETURN n`
- `MATCH (n:Person {name: 'Alice'}) RETURN n`
- `CREATE (n:Person)`
- `CREATE (n:Person {name: 'Bob', age: 25})`
- `CREATE (n:Person)-[r:KNOWS]->(m:Person)`
- `MATCH (n) RETURN *`
- `MATCH (n:Person) RETURN DISTINCT n`

### 2. Verification Test (`cypher_verify_test`)
Small-scale test that validates query correctness with expected results.

**Build & Run:**
```bash
make cypher_verify_test
./cypher_verify_test
```

**Test Data:**
- 5 Person nodes
- 3 Company nodes
- 5 KNOWS relationships

**Validates:**
- Exact row count matching
- Correct node IDs returned
- CREATE clause behavior
- Database state after operations

**Expected Output:**
```
✓ All tests passed!
Passed: 4
Failed: 0
```

### 3. Scale Test (`cypher_scale_test`)
Performance test with ~100 edges.

**Build & Run:**
```bash
make cypher_scale_test
./cypher_scale_test
```

**Test Data:**
- 20 Person nodes
- 5 Company nodes
- 20 WORKS_AT edges
- 80 KNOWS edges
- **Total: ~100 edges**

**Performance Results:**
| Query | Average Time | Rows |
|-------|-------------|------|
| `MATCH (p:Person) RETURN p` | 1.4 μs | 20 |
| `MATCH (c:Company) RETURN c` | 0.8 μs | 5 |
| `CREATE (p:Person)` | <1 μs | 1 |

### 4. End-to-End Test (`cypher_e2e_test`)
Large-scale integration test with 100+ nodes.

**Build & Run:**
```bash
make cypher_e2e_test
./cypher_e2e_test
```

**Test Data:**
- 100 Person nodes
- 10 Company nodes
- 100 WORKS_AT relationships
- ~150 KNOWS relationships

## Architecture

### Parser (`src/cypher/parser/`)
- **cypher_parser.cpp**: Hand-written recursive descent parser
- **ast.h**: AST node definitions
- **expression.h**: Expression types (Literal, Variable, Property, BinaryOp, etc.)
- **clause.h**: Cypher clauses (Match, Where, Return, Create, Delete, Set)

### Planner (`src/cypher/planner/`)
- **planner.cpp**: Converts AST to ExecutionPlan
- **execution_plan.cpp**: Plan node definitions (AllNodeScan, Expand, Filter, Project, CreateNode, etc.)

### Executor (`src/cypher/executor/`)
- **executor.cpp**: Executes plans via operator tree
- **ops/op.h**: Operator implementations following iterator model

## Supported Cypher Features

| Clause | Status | Notes |
|--------|--------|-------|
| MATCH | ✓ | With node patterns, labels, relationships |
| WHERE | Partial | Parsed but evaluation limited |
| RETURN | ✓ | With DISTINCT, * (not AS alias yet) |
| CREATE | ✓ | Creates nodes with labels and properties |
| DELETE | ✓ | Deletes nodes (DETACH not fully implemented) |
| SET | Partial | Properties parsed, execution limited |
| LIMIT | ✗ | Not yet implemented in planner |
| ORDER BY | ✗ | Not yet implemented |

## Known Limitations

1. **LIMIT clause**: Parser recognizes LIMIT but planner doesn't generate Limit plan node
2. **Column names**: Results return correct data but column names may be empty
3. **No-label scans**: `MATCH (n) RETURN n` uses placeholder (scans up to 1000 vertices)
4. **Property access**: Property evaluation in WHERE clause not fully implemented

## Build Requirements

- GCC-12
- C++20
- ANTLR4 runtime (`libantlr4-runtime-dev`)
- Folly (included as submodule)
- dynamic_bitset (included as submodule)

## Quick Start

```bash
# Install ANTLR4
sudo apt-get install antlr4 libantlr4-runtime-dev

# Generate parser files (if needed)
cd grammar && ./generate.sh && cd ..

# Configure and build
rm -rf CMakeCache.txt CMakeFiles/ Makefile
cmake . -DBUILD_CYPHER=ON
make -j4

# Run tests
./cypher_verify_test
./cypher_scale_test
./cypher_e2e_test
```

## Test Results Summary

| Test | Scale | Status |
|------|-------|--------|
| cypher_parser_test | N/A | ✓ Parses all test queries |
| cypher_verify_test | 8 nodes, 5 edges | ✓ All assertions pass |
| cypher_scale_test | 25 nodes, ~100 edges | ✓ Performance < 2μs per query |
| cypher_e2e_test | 110 nodes, ~250 edges | ✓ Creates and queries data |

## Example Usage

```cpp
#include "BACH/cypher/cypher.h"
#include "BACH/db/DB.h"

// Create database
auto options = std::make_shared<Options>();
DB* db = new DB(options);
db->AddVertexLabel("Person");
db->AddEdgeLabel("KNOWS", "Person", "Person");

// Create Cypher engine
CypherEngine engine;
engine.SetDatabase(db);

// Execute query
auto tx = db->BeginTransaction();
if (engine.Execute("MATCH (n:Person) RETURN n", &tx)) {
    const auto& results = engine.GetResults();
    // Process results...
}
```
