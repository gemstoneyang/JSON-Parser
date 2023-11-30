#include <iostream>
#include <string>

#include "Element/JsonElement.hpp"
#include "Element/JsonObject.hpp"

int main(void) {
  JsonObject *elem = new JsonObject();
  JsonObject *value = new JsonObject();
  JsonObject *value2 = new JsonObject();
  JsonObject *value3 = new JsonObject();

  elem->add("hello", value);
  value->add("wow", value2);
  value->add("yes", value3);

  std::cout << elem->toString() << std::endl;

  return 0;
}
