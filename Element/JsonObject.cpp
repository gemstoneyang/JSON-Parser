#include "JsonObject.hpp"

#include <sstream>

JsonObject::JsonObject(void) : JsonElement(JSON_OBJECT) {}

JsonObject::~JsonObject(void) {
  for (JsonMap::iterator it = members.begin(); it != members.end(); ++it) {
    delete it->second;
  }
}

void JsonObject::add(const std::string& key, JsonElement* value) {
  if (members.find(key) != members.end()) {
    throw std::runtime_error("JsonObject - duplicate key: " + key);
  }
  members[key] = value;
}

JsonElement* JsonObject::get(const std::string& key) {
  JsonMap::const_iterator it = members.find(key);
  if (it != members.end()) {
    return it->second;
  }
  throw std::runtime_error("JsonObject - key not found:" + key);
}

std::string JsonObject::toString(int indentLevel) const {
  std::ostringstream oss;
  std::string indent(indentLevel * 4, ' ');

  oss << "{\n";
  for (JsonMap::const_iterator it = members.begin(); it != members.end();) {
    oss << indent << "    \"" << it->first
        << "\": " << it->second->toString(indentLevel + 1);
    if (++it != members.end()) {
      oss << ",";
    }
    oss << "\n";
  }
  oss << indent << "}";
  return oss.str();
}
