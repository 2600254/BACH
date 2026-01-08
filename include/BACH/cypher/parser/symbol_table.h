#pragma once

#include "expression.h"
#include <string>
#include <unordered_map>
#include <memory>

namespace BACH {
namespace cypher {

// 符号表中变量的信息
struct SymbolInfo {
    std::string name;
    size_t scope_id;           // 作用域 ID
    size_t index;              // 在作用域中的索引
    DataType type;             // 推导出的类型
    bool is_node = false;      // 是否是节点变量
    bool is_relationship = false;  // 是否是关系变量
    std::string label;         // 如果有标签约束
};

// 符号表
class SymbolTable {
public:
    SymbolTable() : current_scope_id(0), parent_table(nullptr) {}
    explicit SymbolTable(SymbolTable* parent) : current_scope_id(0), parent_table(parent) {}

    // 进入新作用域
    void EnterScope() {
        current_scope_id++;
        scopes.push_back({});
    }

    // 离开当前作用域
    void LeaveScope() {
        if (!scopes.empty()) {
            scopes.pop_back();
        }
    }

    // 添加符号
    bool AddSymbol(const std::string& name, DataType type, bool is_node = false) {
        if (scopes.empty()) {
            EnterScope();
        }
        auto& scope = scopes.back();

        // 检查是否已存在
        if (scope.find(name) != scope.end()) {
            return false;
        }

        SymbolInfo info;
        info.name = name;
        info.scope_id = current_scope_id;
        info.index = scope.size();
        info.type = type;
        info.is_node = is_node;

        scope[name] = info;
        return true;
    }

    // 查找符号（先查当前作用域，再查父作用域）
    SymbolInfo* Lookup(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) {
                return &found->second;
            }
        }
        if (parent_table) {
            return parent_table->Lookup(name);
        }
        return nullptr;
    }

    // 检查符号是否存在
    bool Exists(const std::string& name) {
        return Lookup(name) != nullptr;
    }

    // 获取当前作用域中的所有符号
    std::vector<SymbolInfo> GetCurrentScopeSymbols() const {
        std::vector<SymbolInfo> result;
        if (!scopes.empty()) {
            for (const auto& entry : scopes.back()) {
                result.push_back(entry.second);
            }
        }
        return result;
    }

    // 获取所有符号（所有作用域）
    std::vector<SymbolInfo> GetAllSymbols() const {
        std::vector<SymbolInfo> result;
        for (const auto& scope : scopes) {
            for (const auto& entry : scope) {
                result.push_back(entry.second);
            }
        }
        return result;
    }

    size_t CurrentScopeId() const { return current_scope_id; }

private:
    size_t current_scope_id;
    std::vector<std::unordered_map<std::string, SymbolInfo>> scopes;
    SymbolTable* parent_table;
};

} // namespace cypher
} // namespace BACH
