#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Element/JsonElements.hpp"
#include "Lexer/JsonLexer.hpp"
#include "Parser/JsonParser.hpp"

void printJsonElement(JsonElement *element, int indent = 0) {
  if (!element) return;

  std::string indentStr(indent, ' ');
  switch (element->getType()) {
    case JSON_OBJECT:
      std::cout << indentStr << "Object" << std::endl;
      // 여기서 JsonObject에 대한 추가 처리를 할 수 있음
      break;
    case JSON_ARRAY:
      std::cout << indentStr << "Array" << std::endl;
      // 여기서 JsonArray에 대한 추가 처리를 할 수 있음
      break;
    case JSON_STRING:
      std::cout << indentStr
                << "String: " << static_cast<JsonString *>(element)->getValue()
                << std::endl;
      break;
    case JSON_NUMBER:
      std::cout << indentStr
                << "Number: " << static_cast<JsonNumber *>(element)->getValue()
                << std::endl;
      break;
    case JSON_BOOLEAN:
      std::cout << indentStr << "Boolean: "
                << (static_cast<JsonBoolean *>(element)->getValue() ? "true"
                                                                    : "false")
                << std::endl;
      break;
    case JSON_NULL:
      std::cout << indentStr << "Null" << std::endl;
      break;
    default:
      std::cout << indentStr << "Unknown Type" << std::endl;
      break;
  }
}

int main(int argc, char **argv) {
  {
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
  }

  std::cout << "---------------------\n" << std::endl;

  {
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
  }

  std::cout << "---------------------\n" << std::endl;

  {
    std::string jsonInput =
        "{\"name\": \"John\", \"age\": 30, \"isMarried\": false, \"hobbies\": "
        "[\"reading\", \"coding\"], \"address\": null}";
    JsonParser parser(jsonInput);

    try {
      JsonElement *root = parser.parse();
      printJsonElement(root);
      std::cout << std::endl;
      std::cout << root->toString() << std::endl;
      delete root;
    } catch (const std::exception &e) {
      std::cerr << "Parsing error: " << e.what() << std::endl;
    }
  }

  std::cout << "---------------------\n" << std::endl;

  {
    (void)argc;
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << argv[1] << "\n";
        return 1;
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContent = buffer.str();

    JsonParser parser(fileContent);

    try {
      JsonElement *root = parser.parse();
      printJsonElement(root);
      std::cout << std::endl;
      std::cout << root->toString() << std::endl;
      delete root;
    } catch (const std::exception &e) {
      std::cerr << "Parsing error: " << e.what() << std::endl;
    }
  }

  return 0;
}
