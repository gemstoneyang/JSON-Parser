#pragma once
#ifndef __JSONPARSER_HPP__
#define __JSONPARSER_HPP__

#include "../Element/JsonElements.hpp"
#include "../Lexer/JsonLexer.hpp"

class JsonParser {
 private:
  JsonLexer lexer;
  JsonToken currentToken;

 public:
  JsonParser(const std::string& input);

  JsonElement* parse(void);

 private:
  void advance(void);
  void expect(TokenType type);
  void expect(TokenType type1, TokenType type2);

  JsonElement* parseValue(void);
  JsonObject* parseObject(void);
  JsonArray* parseArray(void);
  JsonString* parseString(void);
  JsonNumber* parseNumber(void);
  JsonBoolean* parseBoolean(void);
  JsonNull* parseNull(void);
};

#endif