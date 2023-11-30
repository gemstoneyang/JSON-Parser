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
  JsonElement(JsonElementType type);
  virtual ~JsonElement(void);

  JsonElementType getType(void) const;
  virtual std::string toString(int indentLevel = 0) const = 0;
};

#endif