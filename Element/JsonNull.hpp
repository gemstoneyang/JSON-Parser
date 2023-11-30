#pragma once
#ifndef __JSONNULL_HPP__
#define __JSONNULL_HPP__

#include <string>

#include "JsonElement.hpp"

class JsonNull : public JsonElement {
  public:
    JsonNull(void);

    virtual std::string toString(int indentLevel = 0) const;
};

#endif