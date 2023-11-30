#include "JsonNumber.hpp"

#include <sstream>

JsonNumber::JsonNumber(double value) : JsonElement(JSON_NUMBER), value(value) {}

double JsonNumber::getValue() const { return value; }

std::string JsonNumber::toString(int indentLevel) const {
  (void)indentLevel;
  std::ostringstream oss;
  oss << value;
  return oss.str();
}