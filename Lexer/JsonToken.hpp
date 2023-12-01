#pragma once
#ifndef __JSONTOKEN_HPP__
#define __JSONTOKEN_HPP__

enum TokenType {
  OBJECT_START,   // {
  OBJECT_END,     // }
  ARRAY_START,    // [
  ARRAY_END,      // ]
  COMMA,          // ,
  COLON,          // :
  STRING,         // 문자열
  NUMBER,         // 숫자
  BOOLEAN_TRUE,   // true
  BOOLEAN_FALSE,  // false
  NULL_VALUE,     // null
  END_OF_FILE,    // 끝
  INVALID         // 유효하지 않은 토큰
};

#include <string>

class JsonToken {
 public:
  TokenType type;
  std::string value;

  JsonToken(void);
  JsonToken(TokenType type, std::string value = "");
};

#endif