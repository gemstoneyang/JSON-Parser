#pragma once
#ifndef __JSONELEMENT_HPP__
#define __JSONELEMENT_HPP__

#include <string>

class JsonElement {
 public:
  virtual ~JsonElement();
  virtual std::string toString() const = 0;
};

#endif