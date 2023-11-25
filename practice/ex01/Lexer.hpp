#pragma once
#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <exception>
#include <string>

#include "Token.hpp"

class Lexer {
 public:
  Lexer(void);
  ~Lexer(void);

  void setLexer(std::string input);
  Token nextToken(void);

 private:
  std::string input;
  size_t pos;

  int parseNumber(void);

  Lexer(Lexer const& lexer);
  Lexer& operator=(Lexer const& lexer);
};

#endif