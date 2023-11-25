#include <iostream>
#include <string>

int main(void) {
  std::string input;

  std::cout << "더하기 연산을 입력하세요: ";
  std::getline(std::cin, input);

  std::cout << input << std::endl;

  return 0;
}
