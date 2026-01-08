# BACH Cypher 模块进度总结

## 当前完成度概览

**总体进度: 约 35-40%** (不考虑分布式/恢复)

与 TuGraph 等生产级图数据库相比，BACH Cypher 模块已完成核心基础架构，但查询语言完整度、性能优化、服务层等方面仍有较大差距。

---

## 已完成功能 ✓

### 1. Parser (解析器) - 90%

| 功能 | 状态 |
|------|------|
| 递归下降解析器 | ✓ |
| 关键字解析 | |
| - MATCH / RETURN / CREATE / DELETE / SET | ✓ |
| - WHERE / LIMIT / ORDER BY (识别) | ✓ |
| 模式解析 | |
| - 节点模式 `(n:Label)` | ✓ |
| - 关系模式 `-[:REL]->` | ✓ |
| - 路径模式 `(a)-[:REL]->(b)` | ✓ |
| 属性解析 | |
| - 基础字面量 (字符串/数字/布尔) | ✓ |
| - Map 属性 `{k:v, ...}` | 解析但未执行 |
| 表达式解析 | |
| - 二元运算 (=, !=, <, >, AND, OR, ...) | ✓ |
| - 一元运算 (NOT, -) | ✓ |
| - 函数调用 | 语法解析 |

**文件**: `src/cypher/parser/cypher_parser.cpp`

### 2. Planner (查询规划器) - 70%

| 计划节点 | 状态 |
|---------|------|
| AllNodeScan (全节点扫描) | ✓ |
| Expand (关系展开) | ✓ |
| Filter (WHERE 过滤) | 部分实现 |
| Project (投影) | ✓ |
| Aggregate (聚合) | 结构定义，未实现 |
| CreateNode / CreateEdge | ✓ |
| DeleteNode / DeleteEdge | 基础实现 |
| SetProperty / SetLabels | 部分实现 |
| Limit (限制) | 结构定义，未实现 |
| Sort (排序) | 结构定义，未实现 |

**文件**: `src/cypher/planner/planner.cpp`

### 3. Executor (执行器) - 75%

| 操作符 | 状态 |
|--------|------|
| 迭代器模型 (Open/Next/GetCurrent/Close) | ✓ |
| AllNodeScanOp | ✓ (已修复 label_id 歧义) |
| ExpandOp | ✓ |
| FilterOp | ✓ |
| ProjectOp | ✓ (含 DISTINCT) |
| CreateNodeOp | ✓ |
| CreateEdgeOp | ✓ |
| DeleteOp | ✓ |
| SetPropertyOp | 部分 |
| 表达式求值 | |
| - 字面量 | ✓ |
| - 变量查找 | ✓ |
| - 属性访问 | 框架存在，未实现 |
| - 二元/一元运算 | ✓ |

**文件**: `src/cypher/executor/executor.cpp`

### 4. 数据库集成 - 90%

| 功能 | 状态 |
|------|------|
| Transaction 对接 | ✓ |
| LabelManager 对接 | ✓ |
| AddVertex / PutVertex | ✓ |
| PutEdge / GetEdges | ✓ |
| DelVertex | ✓ |

### 5. 测试套件 - 80%

| 测试 | 规模 | 状态 |
|------|------|------|
| cypher_parser_test | N/A | ✓ |
| cypher_verify_test | 8 nodes, 5 edges | ✓ |
| cypher_scale_test | 25 nodes, ~100 edges | ✓ |
| cypher_e2e_test | 110 nodes, ~250 edges | ✓ |

**性能**: ~1-2 μs per query at 100-edge scale

---

## 缺失功能 ✗

### 1. 查询语言完整度 (当前 ~40% → 目标 90%)

#### 1.1 子句与语法

| 功能 | 状态 | 优先级 | 说明 |
|------|------|--------|------|
| LIMIT | ✗ 未实现 | **高** | Planner 未生成 Limit 节点 |
| OFFSET | ✗ 未实现 | **高** | |
| ORDER BY | ✗ 未实现 | **高** | Sort 节点未实现 |
| GROUP BY | ✗ 未实现 | **高** | Aggregate 节点未实现 |
| HAVING | ✗ 未实现 | **高** | 依赖 GROUP BY |
| 聚合函数 | ✗ | **高** | COUNT/SUM/AVG/MIN/MAX |
| UNION / UNION ALL | ✗ | 中 | |
| WITH 子句 | ✗ | 中 | 中间结果命名 |
| CALL { ... } | ✗ | 低 | 子查询 |
| 多 MATCH | 部分 | 中 | 单条多 MATCH 部分支持 |

#### 1.2 模式匹配

| 功能 | 状态 | 优先级 |
|------|------|--------|
| 变长路径 `()-[*..3]->()` | ✗ | **高** |
| 最短路径 `shortestPath()` | ✗ | **高** |
| 可选匹配 `OPTIONAL MATCH` | ✗ | 中 |
| 命名路径 `p = (a)-->(b)` | ✗ | 中 |
| 关系方向 `<--` | ✓ | |
| 无方向关系 `--` | 部分实现 | |

### 2. 表达式求值 (当前 ~50% → 目标 95%)

| 功能 | 状态 | 优先级 |
|------|------|--------|
| **属性访问** | | |
| `n.name` | 解析未执行 | **高** |
| `n.prop1.prop2` | ✗ | **高** |
| **函数调用** | | |
| `id(n)`, `labels(n)` | ✗ | **高** |
| `type(r)` | ✗ | **高** |
| `count()`, `sum()`, `avg()` | ✗ | **高** |
| `min()`, `max()` | ✗ | **高** |
| `collect()` | ✗ | 中 |
| `startsWith()`, `endsWith()` | ✗ | 中 |
| `contains()` | ✗ | 中 |
| `coalesce()` | ✗ | 中 |
| `toString()`, `toInteger()` | ✗ | 中 |
| `timestamp()` | ✗ | 低 |
| **字符串操作** | | |
| `n.name STARTS WITH 'A'` | ✗ | 中 |
| `n.name ENDS WITH 'z'` | ✗ | 中 |
| `n.name CONTAINS 'abc'` | ✗ | 中 |
| `n.name =~ 'regex'` | ✗ | 中 |
| 字符串拼接 `+` | ✓ | |
| **CASE 表达式** | 解析未执行 | 中 |
| **IN 操作符** | `n.id IN [1,2,3]` | ✗ | 中 |
| **列表操作** | | |
| 列表字面量 `[1,2,3]` | 解析未执行 | 低 |
| 列表索引 `list[0]` | ✗ | 低 |
| 列表切片 `list[0..2]` | ✗ | 低 |
| **Map 操作** | | |
| Map 字面量 `{k:v, ...}` | 解析未执行 | 低 |
| Map 键访问 `map.key` | ✗ | 低 |

### 3. 写操作完整度 (当前 40% → 目标 90%)

| 功能 | 状态 | 优先级 |
|------|------|--------|
| **MERGE** | ✗ | **高** |
| "CREATE if not exists" | | |
| 需要配合 ON CREATE / ON MATCH | | |
| **SET 完整** | | |
| `SET n.prop = value` | 需完善属性执行 | **高** |
| `SET n = {prop: value}` | ✗ | **高** |
| `SET n += {prop: value}` | ✗ | 中 |
| `SET n.prop1.prop2 = value` | ✗ | 中 |
| **REMOVE** | | |
| `REMOVE n.prop` | ✗ | 中 |
| `REMOVE n:Label` | ✗ | 中 |
| **DELETE 完整** | | |
| `DETACH DELETE n` | 部分 | 中 |
| 删除属性 | ✗ | 低 |
| **批量操作** | ✗ | 中 |

### 4. 执行优化 (当前 0% → 目标 70%)

| 优化技术 | 状态 | 优先级 | 预期收益 |
|----------|------|--------|----------|
| **查询优化器** | | | |
| 谓词下推 | ✗ | **高** | 减少中间结果 |
| 投影剪枝 | ✗ | **高** | 减少数据传输 |
| JOIN 顺序优化 | ✗ | 中 | 提升多表查询 |
| 子查询展开 | ✗ | 中 | |
| 常量折叠 | ✗ | 低 | |
| **索引支持** | | | |
| Label 索引 | ✗ | **高** | 加速标签过滤 |
| 属性索引 | ✗ | **高** | 加速属性过滤 |
| 全文索引 | ✗ | 中 | 文本搜索 |
| 复合索引 | ✗ | 低 | |
| **执行缓存** | | | |
| 执行计划缓存 | ✗ | 中 | 避免重复规划 |
| 查询结果缓存 | ✗ | 低 | |
| **其他** | | | |
| 并行执行 | ✗ | 低 | |
| 向量化执行 | ✗ | 低 | |

### 5. 结果处理 (当前 60% → 目标 95%)

| 功能 | 状态 | 优先级 |
|------|------|--------|
| 分页 | LIMIT 未实现 | **高** |
| 列名返回 | 部分为空 | 中 |
| 多格式输出 | | |
| - JSON | ✗ | 中 |
| - CSV | ✗ | 低 |
| - Graph 格式 | ✗ | 低 |
| 流式返回 | ✗ 一次性返回 | 中 |
| 结果集大小限制 | ✗ | 中 |
| 元数据返回 | 部分实现 | 低 |

### 6. 服务层 (当前 0% → 目标 80%)

| 功能 | 状态 | 优先级 |
|------|------|--------|
| **网络协议** | | |
| Bolt 协议 | ✗ | **高** |
| HTTP REST API | ✗ | **高** |
| WebSocket | ✗ | 低 |
| **安全** | | |
| 认证 (用户名/密码) | ✗ | **高** |
| TLS/SSL | ✗ | 中 |
| 权限控制 | ✗ | 中 |
| **连接管理** | | |
| 连接池 | ✗ | 中 |
| 连接限制 | ✗ | 中 |
| 超时处理 | ✗ | 中 |
| **可观测性** | | |
| 慢查询日志 | ✗ | **高** |
| 查询统计 | 基础实现 | 中 |
| 性能指标 | ✗ | 中 |
| 查询profiling | ✗ | 低 |

### 7. 类型系统 (当前 50% → 目标 90%)

| 类型 | 状态 | 优先级 |
|------|------|--------|
| 基础类型 | | |
| - Boolean | ✓ | |
| - Integer (int64) | ✓ | |
| - Float (double) | ✓ | |
| - String | ✓ | |
| - Null | ✓ | |
| **数值类型** | | |
| - Float (单精度) | ✗ | 低 |
| - BigInteger | ✗ | 低 |
| **时间类型** | | |
| - Date | ✗ | 中 |
| - Time | ✗ | 中 |
| - DateTime | ✗ | 中 |
| - Duration | ✗ | 低 |
| **空间类型** | | |
| - Point (2D) | ✗ | 低 |
| - Point (3D) | ✗ | 低 |
| - LineString | ✗ | 低 |
| - Polygon | ✗ | 低 |
| **类型转换** | 部分实现 | 中 |
| **类型推断** | 基础实现 | 中 |

---

## 开发路线图

### Phase 1: 核心查询完善 (2-3周)

**目标**: 使 Cypher 查询语言达到基本可用状态

```
Week 1-2:
1. LIMIT / OFFSET 实现
   - Limit 节点实现
   - 与 Project 结合处理

2. ORDER BY 实现
   - Sort 节点实现
   - 多字段排序
   - ASC/DESC

3. 属性访问执行
   - 从图数据库读取属性
   - Property 表达式求值

Week 3:
4. 基础聚合函数
   - COUNT(*) / COUNT(expr)
   - SUM / AVG / MIN / MAX
   - Aggregate 节点实现

5. GROUP BY
   - 分组逻辑
   - 与聚合结合
```

### Phase 2: 写操作完善 (1-2周)

```
Week 4:
1. MERGE 语句
   - 检查是否存在
   - ON CREATE / ON MATCH 子句
   - MergeNode / MergeEdge 节点

2. SET 完整实现
   - SET n.prop = value (执行属性设置)
   - SET n = {props}
   - SET n += {props}
```

### Phase 3: 性能优化 (2-3周)

```
Week 5-6:
1. 查询优化器
   - 谓词下推到扫描层
   - 投影剪枝
   - 简单的 JOIN 优化

2. 索引支持
   - Label 索引 (加速标签过滤)
   - 属性索引设计
   - 索引扫描节点

Week 7:
3. 执行计划缓存
4. 查询性能测试与调优
```

### Phase 4: 服务层 (3-4周)

```
Week 8-10:
1. Bolt 协议实现
   - 握手与认证
   - 消息编解码
   - 查询执行与结果返回

2. HTTP REST API
   - /cypher 端点
   - JSON 请求/响应
   - 批处理支持

Week 11:
3. 认证与安全
4. 连接池管理
5. 慢查询日志
```

---

## 对比分析

### TuGraph vs BACH Cypher

| 维度 | TuGraph | BACH | 差距 |
|------|---------|------|------|
| **Cypher 兼容性** | ~95% | ~40% | **大** |
| **查询性能** | 高性能 | 小数据集快 | 未知 |
| **并发控制** | MVCC + 锁 | 基础事务 | **大** |
| **索引** | Label/属性/全文 | 无 | **大** |
| **服务接口** | Bolt/REST | 无 | **大** |
| **优化器** | 基于规则/代价 | 无 | **大** |
| **可观测性** | 完善 | 基础 | 中 |
| **存储** | 列存+行存 | LSM-Tree | 不同架构 |

### 完成度评估

| 模块 | 当前 | 单机版目标 |
|------|------|-----------|
| Parser | 90% | 95% |
| Planner | 70% | 85% |
| Executor | 75% | 90% |
| 表达式求值 | 50% | 95% |
| 写操作 | 40% | 90% |
| 优化器 | 0% | 70% |
| 服务层 | 0% | 80% |
| **总体** | **35-40%** | **85%** |

---

## 测试运行指南

```bash
# 1. 安装依赖
sudo apt-get install antlr4 libantlr4-runtime-dev

# 2. 生成解析器文件
cd grammar && ./generate.sh && cd ..

# 3. 配置构建
rm -rf CMakeCache.txt CMakeFiles/ Makefile
cmake . -DBUILD_CYPHER=ON

# 4. 编译
make -j4

# 5. 运行测试
./cypher_verify_test    # 小规模验证 (5-8 节点)
./cypher_scale_test     # 性能测试 (~100 边)
./cypher_e2e_test       # 端到端测试 (100+ 节点)
```

---

## 参考文档

- [CYPHER_TEST.md](./CYPHER_TEST.md) - 详细测试文档
- [CLAUDE.md](./CLAUDE.md) - 项目架构指南

---

**最后更新**: 2026-01-08
**分支**: `feature/cypher-compiler`
