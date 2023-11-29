#include "Lexer.hpp"

// Constructor & Destructor
Lexer::Lexer(void) : input(""), pos(0) {}

Lexer::~Lexer(void) {}

// Method
void Lexer::setLexer(std::string input) {
  this->input = input;
  this->pos = 0;
}

Token Lexer::nextToken(void) {
  skipWhiteSpace();

  if (isEndOfInput()) {
    return Token(END);
  }

  if (isdigit(input[pos])) {
    return parseNumberToken();
  }

  if (isOperator(input[pos])) {
    return parseOperatorToken();
  }

  return Token(INVALID);
}

void Lexer::skipWhiteSpace(void) {
  while (pos < input.size() && isspace(input[pos])) {
    pos++;
  }
}

bool Lexer::isEndOfInput(void) { return pos >= input.size(); }

Token Lexer::parseNumberToken(void) {
  int value = parseNumber();
  return Token(NUMBER, value);
}

Token Lexer::parseOperatorToken(void) {
  char operatorChar = input[pos++];
  switch (operatorChar) {
    case '+':
      return Token(PLUS);
    case '-':
      return Token(MINUS);
    case '*':
      return Token(MULTIPLY);
    case '/':
      return Token(DIVIDE);
    case '(':
      return Token(LPAREN);
    case ')':
      return Token(RPAREN);
    default:
      return Token(INVALID);
  }
}

bool Lexer::isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int Lexer::parseNumber(void) {
  int value = 0;

  while (pos < input.size() && isdigit(input[pos])) {
    value = value * 10 + (input[pos] - '0');
    pos++;
  }

  return value;
}
