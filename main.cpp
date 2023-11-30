#include <iostream>
#include <string>

#include "Element/JsonArray.hpp"
#include "Element/JsonElement.hpp"
#include "Element/JsonObject.hpp"

int main(void) {
  JsonObject *elem = new JsonObject();
  JsonObject *value = new JsonObject();
  JsonArray *value2 = new JsonArray();
  JsonObject *value3 = new JsonObject();

  elem->add("hello", value);
  value->add("wow", value2);
  value2->add(value3);

  std::cout << elem->toString() << std::endl;

  return 0;
}
