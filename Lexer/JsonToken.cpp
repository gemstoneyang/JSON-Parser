#include "JsonToken.hpp"

JsonToken::JsonToken(void){};

JsonToken::JsonToken(TokenType type, std::string value)
    : type(type), value(value) {}
