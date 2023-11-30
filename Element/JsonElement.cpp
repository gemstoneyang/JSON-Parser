#include "JsonElement.hpp"

JsonElement::JsonElement(JsonElementType type) : type(type) {}

JsonElement::~JsonElement() {}

JsonElementType JsonElement::getType() const { return type; }
