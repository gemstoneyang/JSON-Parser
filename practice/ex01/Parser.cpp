#include "Parser.hpp"

// Constructor & Destructor
Parser::Parser(void) : lexer() {}

Parser::~Parser(void) {}

// Method
int Parser::getResult(std::string input) {
  lexer.setLexer(input);

  Token token = lexer.nextToken();
  if (token.type != NUMBER) {
    throw std::invalid_argument("Invalid token encountered!");
  }

  int value = token.value;
  token = lexer.nextToken();

  while (token.type == PLUS) {
    token = lexer.nextToken();
    if (token.type != NUMBER) {
      throw std::invalid_argument("Invalid token encountered!");
    }
    value += token.value;
    token = lexer.nextToken();
  }

  if (token.type != END) {
    throw std::invalid_argument("Invalid token encountered!");
  }

  return value;
}
