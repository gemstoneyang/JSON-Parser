#include "Lexer.hpp"

// Constructor & Destructor
Lexer::Lexer(void) : input(""), pos(0) {}

Lexer::~Lexer(void) {}

// Method
void Lexer::setLexer(std::string input) {
  this->input = input;
  this->pos = 0;
}

Token Lexer::nextToken() {
  while (pos < input.size() && isspace(input[pos])) {
    pos++;
  }

  if (pos >= input.size()) {
    return Token(END);
  }

  if (isdigit(input[pos])) {
    int value = parseNumber();
    return Token(NUMBER, value);
  }

  if (input[pos] == '+') {
    pos++;
    return Token(PLUS);
  }

  return Token(INVALID);
}

int Lexer::parseNumber(void) {
  int value = 0;

  while (pos < input.size() && isdigit(input[pos])) {
    value = value * 10 + (input[pos] - '0');
    pos++;
  }

  return value;
}