# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

### Basic Build (without Cypher module)
```bash
rm -rf CMakeCache.txt CMakeFiles/ Makefile
cmake .
make -j4
```

### Build with Cypher Module
```bash
# Install ANTLR4 first
sudo apt-get install antlr4 libantlr4-runtime-dev

# Generate parser files
cd grammar && ./generate.sh && cd ..

# Build with Cypher enabled
rm -rf CMakeCache.txt CMakeFiles/ Makefile
cmake . -DBUILD_CYPHER=ON
make -j4
```

### Compiler Requirements
- GCC-12 (explicitly set in CMakeLists.txt)
- C++20 standard

### Dependencies
- **Folly** - Facebook's library (included as git submodule in `include/folly`)
- **dynamic_bitset** - Included as git submodule in `include/dynamic_bitset`
- **ANTLR4** - For Cypher module (libantlr4-runtime-dev)

## Architecture Overview

BACH is a disk-based graph database using LSM-Tree architecture for HGTAP (Hybrid Graph Transactional/Analytical Processing) workloads.

### Core Storage Architecture

The system uses an LSM-Tree variant (GR-LSM-Tree) that accommodates different graph data layouts across levels:
- **Upper levels**: Adjacency list format (TP-friendly, optimized for writes)
- **Deeper levels**: CSR format (AP-friendly, optimized for analytical queries)
- **Compaction**: Transforms adjacency list → CSR through data propagation

### Key Type Definitions
- `vertex_t`: uint32_t - Vertex ID
- `label_t`: uint16_t - Label ID (for vertex/edge types)
- `edge_property_t`: double - Edge property values

### Module Structure

```
include/BACH/
├── db/           # Database core (DB, Transaction)
├── label/        # LabelManager for vertex/edge label management
├── memory/       # MemoryManager / Memtable
├── sstable/      # SSTable files, FileManager, Version management
├── file/         # File I/O (FileReader, FileWriter, caches)
├── property/     # Property file builders/parsers
├── utils/        # Utilities (ConcurrentList, etc.)
└── cypher/       # Cypher query language module (optional)
    ├── parser/      # ANTLR4-based parser, AST definitions
    ├── planner/     # Query planner, execution plan nodes
    └── executor/    # Execution engine with operator model
```

### Transaction Model
- Snapshot isolation via multi-versioning
- `BeginTransaction()` - Read-write transaction (auto-commits on destruction)
- `BeginReadOnlyTransaction()` - Read-only transaction
- No explicit `Commit()` method - transactions commit automatically when destroyed

### Database API Usage

```cpp
// Create database
auto options = std::make_shared<Options>();
options->STORAGE_DIR = "./db_path";
DB* database = new DB(options);

// Add labels
label_t person_label = database->AddVertexLabel("Person");
label_t knows_label = database->AddEdgeLabel("KNOWS", "Person", "Person");

// Transaction operations
{
    auto tx = database->BeginTransaction();
    vertex_t v = tx.AddVertex(person_label);
    tx.PutVertex(person_label, v, R"({"name": "Alice"})");
    tx.PutEdge(src_id, dst_id, knows_label, 1.0);
    // Auto-commits when tx goes out of scope
}
```

## Cypher Module Architecture

The Cypher module follows a classic query compiler pipeline:

```
Cypher Query String
    ↓
Parser (ANTLR4) → AST
    ↓
Planner → ExecutionPlan
    ↓
Executor → Operators
    ↓
BACH Database API
```

### Parser (`src/cypher/parser/`)

- `cypher_parser.cpp`: CypherParser class with Parse() method (currently stub - ANTLR4 integration TBD)
- `data_type.h`: Value types using std::variant with recursive wrapper for lists
- `ast.h`: AST node base classes (ASTNode, Query)
- `expression.h`: Expression types (Literal, Variable, Property, BinaryOp, UnaryOp, FunctionCall)
- `clause.h`: Cypher clauses (Match, Where, Return, Create, Delete, Set)

### Planner (`src/cypher/planner/`)

- `planner.cpp`: Planner class with clause planning methods (PlanMatchClause, PlanReturnClause, etc.)
- `execution_plan.cpp`: ExecutionPlan container class
- Plan nodes defined in `execution_plan.h`: AllNodeScan, Expand, Filter, Project, CreateNode, CreateEdge, DeleteOp, SetPropertyOp, SetLabelsOp

### Executor (`src/cypher/executor/`)

- `executor.cpp`: Executor class that executes plans via operator tree
- Operators follow iterator model: `Open()`, `Next()`, `GetCurrent()`, `Close()`
- `ExecutionContext` holds: tx, db, symbols, current_row, result_rows, result_columns, stats

### Important: Expression Ownership in Operators

PlanNode owns Expression objects (stored as unique_ptr). Operators should only reference them as raw pointers:

```cpp
// In op.h - operators store raw pointers
struct ProjectionItem {
    Expression* expr;  // Raw pointer - PlanNode owns the expression
    std::string alias;
};
```

When moving expressions from AST to PlanNode during planning, ownership is transferred. The planner uses `std::move(const_cast<ExpressionPtr&>(...))` to take ownership since there's no clone() method.

### CypherEngine (`src/cypher/cypher_engine.cpp`)

Main entry point that ties everything together:
- `SetDatabase(DB* db)` - Set database pointer before Execute()
- `Execute(const std::string& query, Transaction* tx)` - Run query
- `GetResults()` - Get result rows
- `GetStats()` - Get execution statistics

## Testing

Run test executables after build:

```bash
# Cypher module tests
rm -rf demo_db && ./cypher_demo_test      # Cypher architecture demo
rm -rf test_db && ./cypher_interactive_test  # Basic DB operations
./cypher_test                              # Unit tests

# BACH core tests
./example_test
./visualize_test
```

See `cypher_readme.md` for detailed test documentation.

## Working with Submodules

Folly and dynamic_bitset are git submodules. To restore them:
```bash
git submodule update --init --recursive
```
