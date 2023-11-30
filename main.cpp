#include <iostream>
#include <string>

#include "Element/JsonArray.hpp"
#include "Element/JsonBoolean.hpp"
#include "Element/JsonElement.hpp"
#include "Element/JsonNumber.hpp"
#include "Element/JsonObject.hpp"

int main(void) {
  JsonObject *elem = new JsonObject();
  JsonObject *value = new JsonObject();
  JsonArray *arr = new JsonArray();
  JsonNumber *num1 = new JsonNumber(13);
  JsonNumber *num2 = new JsonNumber(42.42);
  JsonBoolean *boolean = new JsonBoolean(false);

  elem->add("hello", value);
  value->add("wow", arr);
  arr->add(num1);
  arr->add(num2);
  value->add("yes", boolean);

  std::cout << elem->toString() << std::endl;

  return 0;
}
