#include "JsonBoolean.hpp"

JsonBoolean::JsonBoolean(bool value)
    : JsonElement(JSON_BOOLEAN), value(value) {}

bool JsonBoolean::getValue(void) const { return value; }

std::string JsonBoolean::toString(int indentLevel) const {
  (void)indentLevel;
  return value ? "true" : "false";
}
