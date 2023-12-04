#include "JsonParser.hpp"

JsonParser::JsonParser(const std::string& input) : lexer(input) {
  advance();  // 초기 토큰을 로드
}

JsonElement* JsonParser::parse(void) { return parseValue(); }

void JsonParser::advance(void) { currentToken = lexer.nextToken(); }

void JsonParser::expect(TokenType type) {
  if (currentToken.type != type) {
    throw std::runtime_error("Unexpected token type");
  }
}

void JsonParser::expect(TokenType type1, TokenType type2) {
  if (currentToken.type != type1 and currentToken.type != type2) {
    throw std::runtime_error("Unexpected token type");
  }
}

JsonElement* JsonParser::parseValue(void) {
  switch (currentToken.type) {
    case OBJECT_START:
      return parseObject();
    case ARRAY_START:
      return parseArray();
    case STRING:
      return parseString();
    case NUMBER:
      return parseNumber();
    case BOOLEAN_TRUE:
    case BOOLEAN_FALSE:
      return parseBoolean();
    case NULL_VALUE:
      return parseNull();
    default:
      throw std::runtime_error("Unexpected token in JSON input");
  }
}

JsonObject* JsonParser::parseObject(void) {
  expect(OBJECT_START);
  advance();

  JsonObject* object = new JsonObject();
  while (currentToken.type != OBJECT_END) {
    expect(STRING);
    std::string key = currentToken.value;
    advance();

    expect(COLON);
    advance();

    JsonElement* value = parseValue();
    object->add(key, value);

    if (currentToken.type != OBJECT_END) {
      expect(COMMA);
      advance();
    }
  }

  expect(OBJECT_END);
  advance();
  return object;
}

JsonArray* JsonParser::parseArray(void) {
  expect(ARRAY_START);
  advance();

  JsonArray* array = new JsonArray();
  while (currentToken.type != ARRAY_END) {
    JsonElement* element = parseValue();
    array->add(element);

    if (currentToken.type != ARRAY_END) {
      expect(COMMA);
      advance();
    }
  }

  expect(ARRAY_END);
  advance();

  return array;
}

JsonString* JsonParser::parseString(void) {
  expect(STRING);

  std::string str = currentToken.value;
  advance();

  return new JsonString(str);
}

JsonNumber* JsonParser::parseNumber(void) {
  expect(NUMBER);

  std::string numberStr = currentToken.value;
  advance();

  double numberValue = std::stod(numberStr);

  return new JsonNumber(numberValue);
}

JsonBoolean* JsonParser::parseBoolean(void) {
  expect(BOOLEAN_TRUE, BOOLEAN_FALSE);

  bool value = (currentToken.type == BOOLEAN_TRUE);
  advance();

  return new JsonBoolean(value);
}

JsonNull* JsonParser::parseNull(void) {
  expect(NULL_VALUE);
  advance();

  return new JsonNull();
}