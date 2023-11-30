#pragma once
#ifndef __JSONELEMENT_HPP__
#define __JSONELEMENT_HPP__

#include <string>

enum JsonElementType {
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_STRING,
  JSON_NUMBER,
  JSON_BOOLEAN,
  JSON_NULL
};

class JsonElement {
 protected:
  JsonElementType type;

 public:
  JsonElement(JsonElementType type) : type(type) {}
  virtual ~JsonElement();

  JsonElementType getType() const { return type; }
  virtual std::string toString(int indentLevel = 0) const = 0;
};

#endif