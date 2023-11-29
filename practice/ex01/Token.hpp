#pragma once
#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

enum TokenType {
  NUMBER,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  END,
  LPAREN,
  RPAREN,
  INVALID
};

struct Token {
  TokenType type;
  double value;  // only used for NUMBER token

  Token(TokenType type, double value) : type(type), value(value) {}

  Token(TokenType type) : type(type), value(0) {}
};

#endif
