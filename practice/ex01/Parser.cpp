#include "Parser.hpp"

#include <iostream>

// Constructor & Destructor
Parser::Parser(void) : lexer() {}

Parser::~Parser(void) {}

// Method
int Parser::getResult(std::string input) {
  this->lexer.setString(input);

  int value = 0;

  for (Token token = lexer.nextToken(); token.type != END;
       token = lexer.nextToken()) {
    if (token.type == NUMBER) {
      value += token.value;
    } else if (token.type == PLUS) {
      continue;
    } else {
      std::cerr << "Invalid token encountered!\n";
      return 0;
    }
  }
  return value;
}
