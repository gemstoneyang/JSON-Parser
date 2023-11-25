#include "Parser.hpp"

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

int Parser::parseNumber(void) {
  int value = nextToken() - '0';
  consumeToken();
  return value;
}

int Parser::getResult(std::string input) {
  this->input = input;

  int value = parseNumber();

  while (true) {
    if (nextToken() == '+') {
      consumeToken();
      value += parseNumber();
    } else {
      break;
    }
  }

  return value;
}
