#pragma once
#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>

#include "Lexer.hpp"
#include "Token.hpp"

class Parser {
 public:
  Parser(void);
  ~Parser(void);

  int getResult(std::string input);

 private:
  Lexer lexer;
  Token token;

  int factor(void);
  int term(void);
  int expression(void);

  Parser(Parser const& parser);
  Parser& operator=(Parser const& parser);
};

#endif