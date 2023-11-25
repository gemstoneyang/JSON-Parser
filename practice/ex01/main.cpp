#include <iostream>
#include <string>

#include "Parser.hpp"

int main(void) {
  std::string input;

  std::cout << "더하기 연산을 입력하세요: ";
  std::getline(std::cin, input);

  Parser parser;

  int result = parser.getResult(input);

  std::cout << result << std::endl;

  return 0;
}
