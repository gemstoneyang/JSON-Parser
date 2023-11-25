#pragma once
#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>

class Parser {
 public:
  Parser(void);
  ~Parser(void);

  int getResult(std::string input);

 private:
  std::string input;
  size_t pos;

  char nextToken(void);
  void consumeToken(void);
  void ignoreWhitespace(void);
  int parseNumber(void);

  Parser(Parser const& parser);
  Parser& operator=(Parser const& parser);
};

#endif