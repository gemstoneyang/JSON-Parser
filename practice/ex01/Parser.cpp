#include "Parser.hpp"

#include <iostream>

// Constructor & Destructor
Parser::Parser(void) : input(""), pos(0) {}

Parser::~Parser(void) {}

// Method
char Parser::nextToken(void) {
  if (pos >= input.size()) {
    return '\0';
  }
  return input[pos];
}

void Parser::consumeToken(void) { pos++; }

void Parser::ignoreWhitespace(void) {
  while (isspace(nextToken())) {
    consumeToken();
  }
}

int Parser::parseNumber(void) {
  int value = nextToken() - '0';
  consumeToken();
  return value;
}

int Parser::getResult(std::string input) {
  this->pos = 0;
  this->input = input;

  ignoreWhitespace();
  int value = parseNumber();

  while (true) {
    ignoreWhitespace();
    if (nextToken() == '+') {
      consumeToken();
      ignoreWhitespace();
      value += parseNumber();
    } else {
      break;
    }
  }

  return value;
}
