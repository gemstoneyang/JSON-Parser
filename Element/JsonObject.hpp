#pragma once
#ifndef __JSONOBJECT_HPP__
#define __JSONOBJECT_HPP__

#include <map>
#include <stdexcept>

#include "JsonElement.hpp"

typedef std::map<std::string, JsonElement*> JsonMap;

class JsonObject : public JsonElement {
 private:
  JsonMap members;

 public:
  JsonObject(void);
  virtual ~JsonObject(void);

  void add(const std::string& key, JsonElement* value);

  JsonElement* get(const std::string& key);

  virtual std::string toString(int indentLevel = 0) const;
};

#endif