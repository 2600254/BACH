#pragma once

#include <string>
#include <variant>
#include <vector>
#include <unordered_map>
#include <memory>
#include <cstdint>

namespace BACH {
namespace cypher {

// Cypher 数据类型枚举
enum class DataType {
    UNKNOWN,
    NULL_VALUE,
    BOOLEAN,
    INTEGER,
    FLOAT,
    STRING,
    LIST,
    MAP,
    NODE,
    RELATIONSHIP,
    PATH
};

// Forward declarations
struct Value;
struct ListValue;
struct MapValue;

// Cypher 值类型 - 使用包装类支持递归
struct Value {
    std::variant<
        std::monostate,      // null
        bool,                // boolean
        int64_t,             // integer
        double,              // float
        std::string,         // string
        std::shared_ptr<ListValue>,   // list
        std::shared_ptr<MapValue>     // map
    > data;

    Value() : data(std::monostate{}) {}
    Value(std::monostate) : data(std::monostate{}) {}
    Value(bool v) : data(v) {}
    Value(int64_t v) : data(v) {}
    Value(int v) : data(static_cast<int64_t>(v)) {}
    Value(double v) : data(v) {}
    Value(const std::string& v) : data(v) {}
    Value(std::string&& v) : data(std::move(v)) {}
    Value(const char* v) : data(std::string(v)) {}
    Value(std::shared_ptr<ListValue> v) : data(std::move(v)) {}
    Value(std::shared_ptr<MapValue> v) : data(std::move(v)) {}

    bool IsNull() const { return std::holds_alternative<std::monostate>(data); }
    bool IsBool() const { return std::holds_alternative<bool>(data); }
    bool IsInt() const { return std::holds_alternative<int64_t>(data); }
    bool IsFloat() const { return std::holds_alternative<double>(data); }
    bool IsString() const { return std::holds_alternative<std::string>(data); }
    bool IsList() const { return std::holds_alternative<std::shared_ptr<ListValue>>(data); }
    bool IsMap() const { return std::holds_alternative<std::shared_ptr<MapValue>>(data); }
};

struct ListValue {
    std::vector<Value> elements;
};

struct MapValue {
    std::unordered_map<std::string, Value> properties;
};

// 值类型检查辅助函数
inline bool IsNull(const Value& v) {
    return v.IsNull();
}

inline bool IsBool(const Value& v) {
    return v.IsBool();
}

inline bool IsInt(const Value& v) {
    return v.IsInt();
}

inline bool IsFloat(const Value& v) {
    return v.IsFloat();
}

inline bool IsString(const Value& v) {
    return v.IsString();
}

inline bool IsList(const Value& v) {
    return v.IsList();
}

inline bool IsMap(const Value& v) {
    return v.IsMap();
}

// 获取数据类型
inline DataType GetDataType(const Value& v) {
    if (v.IsNull()) return DataType::NULL_VALUE;
    if (v.IsBool()) return DataType::BOOLEAN;
    if (v.IsInt()) return DataType::INTEGER;
    if (v.IsFloat()) return DataType::FLOAT;
    if (v.IsString()) return DataType::STRING;
    if (v.IsList()) return DataType::LIST;
    if (v.IsMap()) return DataType::MAP;
    return DataType::UNKNOWN;
}

} // namespace cypher
} // namespace BACH
