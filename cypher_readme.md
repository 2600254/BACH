# BACH Cypher Query Language Module

## 概述

BACH Cypher 模块为 BACH 图数据库提供了 Cypher 查询语言支持。该模块实现了经典的查询编译器架构：

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

## 构建方法

### 前置要求

```bash
# 安装 ANTLR4
sudo apt-get install antlr4 libantlr4-runtime-dev

# 生成解析器文件
cd grammar && ./generate.sh
cd ..
```

### 编译

```bash
rm -rf CMakeCache.txt CMakeFiles/ Makefile
cmake . -DBUILD_CYPHER=ON
make -j4
```

## 测试方法

### 1. Cypher 演示测试 (推荐)

```bash
rm -rf demo_db && ./cypher_demo_test
```

**功能**: 展示 Cypher 模块架构和使用示例

**测试内容**:
- 创建数据库和标签 (Person, Company)
- 添加示例节点和边
- 演示 Cypher 查询示例（解析器完成后可用）
- 直接数据库查询对比

**预期输出**:
```
========================================
BACH Cypher Query Language Demo
========================================

Sample data created.
  - 3 Person nodes (Alice, Bob, Charlie)
  - 1 Company node (TechCorp)
  - 5 edges

========================================
Cypher Query Examples
========================================

Note: The ANTLR4-based parser is not fully implemented.
The parser/planner/executor pipeline architecture is in place.

Example Cypher queries (when parser is complete):
  1. MATCH (n:Person) RETURN n
  2. MATCH (a:Person)-[r:KNOWS]->(b:Person) RETURN a, b
  3. MATCH (n:Person {name: 'Alice'}) RETURN n
  4. CREATE (n:Person {name: 'Dave', age: 28})

========================================
Direct Database Query (for comparison)
========================================

Direct API result: 3 Person nodes

========================================
Demo completed successfully!
========================================
```

### 2. 基础数据库交互测试

```bash
rm -rf test_db && ./cypher_interactive_test
```

**功能**: 测试基础的数据库操作

**测试内容**:
- 创建顶点标签 (Person, Company)
- 创建边标签 (KNOWS, WORKS_AT)
- 添加节点 (Alice, Bob, Charlie, TechCorp)
- 添加边
- 查询节点数量
- 获取节点属性
- 获取边列表

**预期输出**:
```
========================================
BACH Database Interface
========================================
Opening database at: ./test_db
Added labels:
  Person: 0
  Company: 1
  KNOWS: 0
  WORKS_AT: 1

Added sample data:
  3 Person nodes (Alice, Bob, Charlie)
  1 Company node (TechCorp)
  5 edges

========================================
Query Test
========================================

1. Vertex Scan Test:
   Person nodes: 3

2. Get Vertex Test:
   Alice properties: {"name": "Alice", "age": 30}

3. Get Edges Test:
   Alice's KNOWS edges: 2
     -> vertex 1 (weight: 1)
     -> vertex 2 (weight: 0.5)

========================================
Test completed successfully!
========================================
```

### 3. 单元测试

```bash
./cypher_test
```

**功能**: 运行 Cypher 模块的单元测试

### 4. BACH 原有功能测试

```bash
./example_test
./visualize_test
```

**功能**: 确保 BACH 数据库原有功能正常

## 架构说明

### 目录结构

```
include/BACH/cypher/
├── parser/          # ANTLR4 解析器
│   ├── cypher_parser.h
│   ├── ast.h
│   ├── expression.h
│   ├── clause.h
│   └── data_type.h
├── planner/         # 查询规划器
│   ├── planner.h
│   └── execution_plan.h
└── executor/        # 执行引擎
    ├── executor.h
    └── ops/op.h

src/cypher/
├── parser/
│   └── cypher_parser.cpp
├── planner/
│   ├── planner.cpp
│   └── execution_plan.cpp
├── executor/
│   └── executor.cpp
└── cypher_engine.cpp
```

### 支持的 Cypher 子句

| 子句 | 状态 | 说明 |
|------|------|------|
| MATCH | 部分支持 | 节点扫描、边展开 |
| WHERE | 部分支持 | 基础过滤条件 |
| RETURN | 支持 | 投影、DISTINCT |
| CREATE | 支持 | 创建节点和边 |
| DELETE | 支持 | 删除节点和边 |
| SET | 部分支持 | 设置属性和标签 |

### 执行计划节点

- `AllNodeScan` - 全节点扫描
- `Expand` - 边展开
- `Filter` - 条件过滤
- `Project` - 结果投影
- `CreateNode` - 创建节点
- `CreateEdge` - 创建边
- `DeleteOp` - 删除操作
- `SetPropertyOp` - 设置属性
- `SetLabelsOp` - 设置标签

## 待完成工作

1. **完整的 ANTLR4 解析器实现**
   - 完成 `CypherParser::Parse()` 方法
   - 集成生成的解析器代码

2. **更多表达式求值**
   - 属性访问 (`n.name`)
   - 函数调用 (`id()`, `labels()`)
   - 复杂条件表达式

3. **高级子句支持**
   - 聚合 (COUNT, SUM, AVG, etc.)
   - 排序 (ORDER BY)
   - 分页 (SKIP, LIMIT)
   - 模式合并 (MERGE)

4. **优化规则**
   - 谓词下推
   - 投影剪枝
   - 索引扫描选择

## 测试数据示例

测试使用的图数据:

```
(Alice:Person {name: "Alice", age: 30})
    │
    ├──[:KNOWS]→ (Bob:Person {name: "Bob", age: 25})
    │
    ├──[:KNOWS]→ (Charlie:Person {name: "Charlie", age: 35})
    │
    └──[:WORKS_AT]→ (TechCorp:Company {name: "TechCorp"})

(Bob)──[:KNOWS]→(Charlie)
(Bob)──[:WORKS_AT]→(TechCorp)
```

## 故障排查

### 编译错误

如果遇到链接错误：
```bash
# 确保 ANTLR4 已安装
sudo apt-get install libantlr4-runtime-dev

# 重新生成解析器
cd grammar && ./generate.sh && cd ..
```

### 运行时错误

如果数据库目录已存在，先清理：
```bash
rm -rf demo_db test_db
```

## 开发者

BACH Cypher 模块是 BACH 图数据库的扩展组件，用于支持图查询语言标准。
