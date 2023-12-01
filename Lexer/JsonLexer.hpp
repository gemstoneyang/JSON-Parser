#pragma once
#ifndef __JSONLEXER_HPP__
#define __JSONLEXER_HPP__

#include <string>

#include "JsonToken.hpp"

class JsonLexer {
 private:
  std::string input;
  size_t position;
  char currentChar;

 public:
  JsonLexer(const std::string& input);

  JsonToken nextToken(void);

 private:
  void advance(void);
  void skipWhitespace(void);
  JsonToken stringToken(void);
  JsonToken numberToken(void);
  JsonToken keywordToken(void);
};

#endif