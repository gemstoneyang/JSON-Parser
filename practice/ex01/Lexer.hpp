#pragma once
#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <string>

#include "Token.hpp"

class Lexer {
 public:
  Lexer(void);
  ~Lexer(void);

  void setString(std::string input);
  Token nextToken(void);

 private:
  std::string input;
  size_t pos;

  Lexer(Lexer const& lexer);
  Lexer& operator=(Lexer const& lexer);
};

#endif