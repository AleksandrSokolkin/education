#include <variant>
#include <string_view>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <cmath>


// types
struct JSONValue;

using JSONObject = std::vector<std::pair<std::string, JSONValue>>;
using JSONArray = std::vector<JSONValue>;
using JSONValueType = std::variant<
                            std::nullptr_t,
                            std::string,
                            double,
                            bool,
                            JSONObject,
                            JSONArray
                        >;

template <typename Type>
concept valid_JSONValueType = requires(JSONValueType value, Type v) {
    value = v;
};

struct JSONValue
{
    JSONValueType value;


    JSONValue() { value = nullptr; };

    template <valid_JSONValueType Type = std::nullptr_t>
    constexpr JSONValue(Type&& v) { value = std::forward<Type>(v); }
};


// parse functions
constexpr void skip_swhitespaces(std::string_view json, size_t& pos)
{
    size_t size = json.size();
    while (pos < size and std::isspace(static_cast<unsigned char>(json[pos]))) {
        ++pos;
    }
}

constexpr JSONValue parse_string(std::string_view json, size_t& pos)
{
    ++pos;
    size_t startPos = pos;
    size_t size = json.size();

    while (pos < size and json[pos] != '\"') ++pos;

    if (pos == size) throw std::logic_error("parse_string error");
    ++pos;
    return std::string(json.substr(startPos, pos - startPos));
}


constexpr JSONValue parse_double(std::string_view json, size_t& pos)
{
    size_t size = json.size();

    bool isSigned = false;
    if (not std::isdigit(json[pos])) {
        isSigned = json[pos] == '-';
        ++pos;
    }

    double result = 0;
    while (pos < size and std::isdigit(json[pos])) {
        result = result * 10 + json[pos++] - '0';
    }

    if (pos == size) return result;

    if (json[pos] == '.') ++pos;

    int power = -1;
    while (pos < size and std::isdigit(json[pos])) {
        result += std::pow(json[pos++] - '0', power--);
    }

    return result;
}

constexpr JSONValue parse_bool(std::string_view json, size_t& pos)
{
    size_t size = json.size();

    if (json[pos] == 't') {
        if (size - pos <= 4 || ) std::
    }
}


int main()
{
    return 0;
}

