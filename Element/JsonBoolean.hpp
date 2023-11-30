#pragma once
#ifndef __JSONBOOLEAN_HPP__
#define __JSONBOOLEAN_HPP__

#include <string>

#include "JsonElement.hpp"

class JsonBoolean : public JsonElement {
 private:
  bool value;

 public:
  JsonBoolean(bool value);

  bool getValue(void) const;
  virtual std::string toString(int indentLevel = 0) const;
};

#endif