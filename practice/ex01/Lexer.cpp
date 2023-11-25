#include "Lexer.hpp"

// Constructor & Destructor
Lexer::Lexer(void) : input(""), pos(0) {}

Lexer::~Lexer(void) {}

// Method
void Lexer::setString(std::string input) { this->input = input; }

Token Lexer::nextToken() {
  while (pos < input.size() && isspace(input[pos])) {
    pos++;
  }

  if (pos >= input.size()) {
    return Token(END);
  }

  if (isdigit(input[pos])) {
    int value = input[pos] - '0';
    pos++;
    return Token(NUMBER, value);
  }

  if (input[pos] == '+') {
    pos++;
    return Token(PLUS);
  }

  return Token(INVALID);
}