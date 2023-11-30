#include "JsonElement.hpp"

JsonElement::JsonElement(JsonElementType type) : type(type) {}

JsonElement::~JsonElement(void) {}

JsonElementType JsonElement::getType(void) const { return type; }
