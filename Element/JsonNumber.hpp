#pragma once
#ifndef __JSONNUMBER_HPP__
#define __JSONNUMBER_HPP__

#include <string>

#include "JsonElement.hpp"

class JsonNumber : public JsonElement {
 private:
  double value;

 public:
  JsonNumber(double value);

  double getValue() const;
  virtual std::string toString(int indentLevel = 0) const;
};

#endif