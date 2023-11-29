#include "Parser.hpp"

// Constructor & Destructor
Parser::Parser(void) : lexer(), token(INVALID) {}

Parser::~Parser(void) {}

// Method
double Parser::getResult(std::string input) {
  lexer.setLexer(input);
  token = lexer.nextToken();

  double value = expression();

  if (token.type != END) {
    throw std::invalid_argument("Invalid token encountered!");
  }

  return value;
}

double Parser::expression(void) {
  double value = term();

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

double Parser::factor(void) {
  if (token.type == NUMBER) {
    double value = token.value;
    token = lexer.nextToken();
    return value;
  }

  if (token.type == LPAREN) {
    token = lexer.nextToken();
    double value = expression();
    if (token.type != RPAREN) {
      throw std::invalid_argument("Invalid token encountered!");
    }
    token = lexer.nextToken();
    return value;
  }

  throw std::invalid_argument("Invalid token encountered!");
}

double Parser::term(void) {
  double value = factor();

  while (token.type == MULTIPLY || token.type == DIVIDE) {
    if (token.type == MULTIPLY) {
      token = lexer.nextToken();
      value *= factor();
    } else {
      token = lexer.nextToken();
      double f = factor();
      if (f == 0) {
        throw std::invalid_argument("Devide by zero!");
      }
      value /= f;
    }
  }

  return value;
}
