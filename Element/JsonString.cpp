#include "JsonString.hpp"

#include <sstream>

JsonString::JsonString(const std::string& value)
    : JsonElement(JSON_STRING), value(value) {}

const std::string& JsonString::getValue(void) const { return value; }

std::string JsonString::toString(int indentLevel) const {
  (void)indentLevel;
  std::ostringstream oss;
  oss << "\"" << value << "\"";
  return oss.str();
}