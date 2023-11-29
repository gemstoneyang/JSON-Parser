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

  double getResult(std::string input);

 private:
  Lexer lexer;
  Token token;

  double factor(void);
  double term(void);
  double expression(void);

  Parser(Parser const& parser);
  Parser& operator=(Parser const& parser);
};

#endif