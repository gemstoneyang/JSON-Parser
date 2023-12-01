#include <iostream>
#include <string>

#include "Element/JsonArray.hpp"
#include "Element/JsonBoolean.hpp"
#include "Element/JsonElement.hpp"
#include "Element/JsonNull.hpp"
#include "Element/JsonNumber.hpp"
#include "Element/JsonObject.hpp"
#include "Element/JsonString.hpp"
#include "Lexer/JsonLexer.hpp"

int main(void) {
  JsonObject *elem = new JsonObject();
  JsonObject *value = new JsonObject();
  JsonArray *arr = new JsonArray();
  JsonNumber *num1 = new JsonNumber(13);
  JsonNumber *num2 = new JsonNumber(42.42);
  JsonBoolean *boolean = new JsonBoolean(false);
  JsonNull *nullVal = new JsonNull();
  JsonString *str = new JsonString("very fun!");

  elem->add("hello", value);
  value->add("wow", arr);
  arr->add(num1);
  arr->add(num2);
  arr->add(str);
  value->add("yes", boolean);
  value->add("none", nullVal);

  std::cout << elem->toString() << std::endl;

  std::cout << "---------------------\n" << std::endl;

  std::string jsonInput =
      "{\"name\": \"John\", \"age\": 30, \"isMarried\": false, \"hobbies\": "
      "[\"reading\", \"coding\"], \"address\": null}";

  JsonLexer lexer(jsonInput);
  JsonToken token;

  try {
    while ((token = lexer.nextToken()).type != END_OF_FILE) {
      std::cout << "Token Type: ";

      switch (token.type) {
        case OBJECT_START:
          std::cout << "OBJECT_START";
          break;
        case OBJECT_END:
          std::cout << "OBJECT_END";
          break;
        case ARRAY_START:
          std::cout << "ARRAY_START";
          break;
        case ARRAY_END:
          std::cout << "ARRAY_END";
          break;
        case STRING:
          std::cout << "STRING";
          break;
        case NUMBER:
          std::cout << "NUMBER";
          break;
        case BOOLEAN_TRUE:
          std::cout << "BOOLEAN_TRUE";
          break;
        case BOOLEAN_FALSE:
          std::cout << "BOOLEAN_FALSE";
          break;
        case NULL_VALUE:
          std::cout << "NULL_VALUE";
          break;
        case COMMA:
          std::cout << "COMMA";
          break;
        case COLON:
          std::cout << "COLON";
          break;
        default:
          std::cout << "INVALID";
          break;
      }

      std::cout << " | Value: " << token.value << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
