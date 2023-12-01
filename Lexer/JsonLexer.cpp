#include "JsonLexer.hpp"

JsonLexer::JsonLexer(const std::string& input) : input(input), position(0) {
  currentChar = input[position];
}

JsonToken JsonLexer::nextToken() {
  while (currentChar != '\0') {
    if (isspace(currentChar)) {
      skipWhitespace();
      continue;
    }

    switch (currentChar) {
      case '{':
        advance();
        return JsonToken(OBJECT_START);
      case '}':
        advance();
        return JsonToken(OBJECT_END);
      case '[':
        advance();
        return JsonToken(ARRAY_START);
      case ']':
        advance();
        return JsonToken(ARRAY_END);
      case ',':
        advance();
        return JsonToken(COMMA);
      case ':':
        advance();
        return JsonToken(COLON);
      case '\"':
        return stringToken();  // 문자열 토큰 처리
      default:
        if (isdigit(currentChar) || currentChar == '-') {
          return numberToken();  // 숫자 토큰 처리
        } else if (isalpha(currentChar)) {
          // 부울 값 또는 null 처리
          return keywordToken();
        }
        throw std::runtime_error("Unexpected character in JSON input");
    }
  }

  return JsonToken(END_OF_FILE);  // 파일의 끝
}

void JsonLexer::advance(void) {
  if (position < input.length()) {
    currentChar = input[++position];
  } else {
    currentChar = '\0';  // 입력의 끝
  }
}

void JsonLexer::skipWhitespace(void) {
  while (currentChar != '\0' && isspace(currentChar)) {
    advance();
  }
}

JsonToken JsonLexer::stringToken() {
  // 시작 따옴표를 건너뛰기
  advance();

  std::string result;
  while (currentChar != '\0' && currentChar != '\"') {
    if (currentChar == '\\') {
      // 이스케이프 문자 처리
      advance();
      switch (currentChar) {
        case '\"':
          result += '\"';
          break;
        case '\\':
          result += '\\';
          break;
        case '/':
          result += '/';
          break;
        case 'b':
          result += '\b';
          break;
        case 'f':
          result += '\f';
          break;
        case 'n':
          result += '\n';
          break;
        case 'r':
          result += '\r';
          break;
        case 't':
          result += '\t';
          break;
        default:
          throw std::runtime_error("Unexpected escape character");
      }
    } else {
      result += currentChar;
    }
    advance();
  }

  // 종료 따옴표를 건너뛰기
  if (currentChar == '\"') {
    advance();
    return JsonToken(STRING, result);
  }

  throw std::runtime_error("Unterminated string literal in JSON input");
}

JsonToken JsonLexer::numberToken() {
  std::string numberStr;

  // 음수 처리
  if (currentChar == '-') {
    numberStr += currentChar;
    advance();
  }

  // 숫자 처리 (정수 부분)
  while (isdigit(currentChar)) {
    numberStr += currentChar;
    advance();
  }

  // 소수점 처리
  if (currentChar == '.') {
    numberStr += '.';
    advance();
    while (isdigit(currentChar)) {
      numberStr += currentChar;
      advance();
    }
  }

  // 지수 처리
  if (currentChar == 'e' || currentChar == 'E') {
    numberStr += currentChar;
    advance();
    if (currentChar == '+' || currentChar == '-') {
      numberStr += currentChar;
      advance();
    }
    while (isdigit(currentChar)) {
      numberStr += currentChar;
      advance();
    }
  }

  // 숫자 문자열을 JsonToken으로 변환
  return JsonToken(NUMBER, numberStr);
}

JsonToken JsonLexer::keywordToken(void) {
  std::string word;

  while (isalpha(currentChar)) {
    word += currentChar;
    advance();
  }

  if (word == "true") {
    return JsonToken(BOOLEAN_TRUE);
  } else if (word == "false") {
    return JsonToken(BOOLEAN_FALSE);
  } else if (word == "null") {
    return JsonToken(NULL_VALUE);
  }

  throw std::runtime_error("Invalid keyword: " + word);
}
