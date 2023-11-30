#include "JsonNull.hpp"

JsonNull::JsonNull(void) : JsonElement(JSON_NULL) {}

std::string JsonNull::toString(int indentLevel) const {
  (void)indentLevel;
  return "null";
}