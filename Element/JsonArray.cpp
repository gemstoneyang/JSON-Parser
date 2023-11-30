#include "JsonArray.hpp"

#include <sstream>

JsonArray::JsonArray(void) : JsonElement(JSON_ARRAY) {}

JsonArray::~JsonArray(void) {
  for (size_t i = 0; i < elements.size(); ++i) {
    delete elements[i];
  }
}

void JsonArray::add(JsonElement* element) { elements.push_back(element); }

std::string JsonArray::toString(int indentLevel) const {
  std::ostringstream oss;
  std::string indent(indentLevel * 4, ' ');

  oss << "[\n";
  for (size_t i = 0; i < elements.size(); ++i) {
    oss << indent << "    " << elements[i]->toString(indentLevel + 1);
    if (i != elements.size() - 1) {
      oss << ",";
    }
    oss << "\n";
  }
  oss << indent << "]";
  return oss.str();
}