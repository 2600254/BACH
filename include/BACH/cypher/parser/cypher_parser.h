#pragma once

#include "ast.h"
#include "clause.h"
#include "expression.h"
#include "symbol_table.h"
#include <string>
#include <memory>

namespace BACH {
namespace cypher {

// Cypher 解析器入口类
// 负责：将 Cypher 查询字符串解析为 AST
class CypherParser {
public:
    CypherParser();
    ~CypherParser();

    // 解析 Cypher 查询字符串，返回 AST
    // 返回 nullptr 表示解析失败
    std::unique_ptr<Query> Parse(const std::string& query);

    // 获取最后一个错误信息
    std::string GetLastError() const { return last_error; }

    // 获取符号表（解析后填充）
    const SymbolTable& GetSymbolTable() const { return symbol_table; }

private:
    std::string last_error;
    SymbolTable symbol_table;

    // 内部实现（使用 ANTLR4）
    class Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace cypher
} // namespace BACH
