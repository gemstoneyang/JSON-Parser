#include <iostream>
#include <string>

#include "Parser.hpp"

int main(void) {
  std::string input;

  Parser parser;

  while (true) {
    try {
      std::cout << "더하기 연산을 입력하세요: ";
      std::getline(std::cin, input);
      int result = parser.getResult(input);
      std::cout << result << std::endl;
    } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
    }
  }

  return 0;
}
