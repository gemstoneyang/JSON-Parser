#pragma once
#ifndef __JSONARRAY_HPP__
#define __JSONARRAY_HPP__

#include <vector>

#include "JsonElement.hpp"

class JsonArray : public JsonElement {
 private:
  std::vector<JsonElement*> elements;

 public:
  JsonArray(void);
  virtual ~JsonArray(void);

  void add(JsonElement* element);
  JsonElement* get(int index);
  std::size_t size() const;
  virtual std::string toString(int indentLevel = 0) const;
};

#endif