#include "Parser.hpp"

// Constructor & Destructor
Parser::Parser(void) : lexer(), token(INVALID) {}

Parser::~Parser(void) {}

// Method
int Parser::getResult(std::string input) {
  lexer.setLexer(input);
  token = lexer.nextToken();

  int value = expression();

  if (token.type != END) {
    throw std::invalid_argument("Invalid token encountered!");
  }

  return value;
}

int Parser::expression(void) {
  int value = term();

  while (token.type == PLUS || token.type == MINUS) {
    if (token.type == PLUS) {
      token = lexer.nextToken();
      value += term();
    } else {
      token = lexer.nextToken();
      value -= term();
    }
  }

  return value;
}

int Parser::factor(void) {
  if (token.type == NUMBER) {
    int value = token.value;
    token = lexer.nextToken();
    return value;
  }

  if (token.type == LPAREN) {
    token = lexer.nextToken();
    int value = expression();
    if (token.type != RPAREN) {
      throw std::invalid_argument("Invalid token encountered!");
    }
    token = lexer.nextToken();
    return value;
  }

  throw std::invalid_argument("Invalid token encountered!");
}

int Parser::term(void) {
  int value = factor();

  while (token.type == MULTIPLY || token.type == DIVIDE) {
    if (token.type == MULTIPLY) {
      token = lexer.nextToken();
      value *= factor();
    } else {
      token = lexer.nextToken();
      int f = factor();
      if (f == 0) {
        throw std::invalid_argument("Devide by zero!");
      }
      value /= f;
    }
  }

  return value;
}
