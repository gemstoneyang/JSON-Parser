#pragma once
#ifndef __JSONELEMENT_HPP__
#define __JSONELEMENT_HPP__

#include <string>

class JsonElement {
 public:
  virtual ~JsonElement();
  virtual std::string toString(int indentLevel = 0) const = 0;
};

#endif