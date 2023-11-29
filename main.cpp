#include <iostream>
#include <string>

#include "JsonData.hpp"

int main(void) {
  std::string s = "hello";
  JsonData data(s);

  // JsonType type = data.getType();
  std::string str = data.getString();

  std::cout << str << std::endl;

  return 0;
}
