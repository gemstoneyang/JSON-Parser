#pragma once
#ifndef __JSONSTRING_HPP__
#define __JSONSTRING_HPP__

#include <string>

#include "JsonElement.hpp"

class JsonString : public JsonElement {
 private:
  std::string value;

 public:
  JsonString(const std::string& value);

  const std::string& getValue(void) const;
  virtual std::string toString(int indentLevel = 0) const;
};

#endif