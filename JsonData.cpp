#include "JsonData.hpp"

// Constructor
JsonData::JsonData(const std::string& str) : _type(STRING), _str(str) {}

JsonData::JsonData(double num) : _type(NUMBER), _num(num) {}

JsonData::JsonData(const std::vector<std::pair<std::string, JsonData> >& obj)
    : _type(OBJECT), _obj(obj) {}

JsonData::JsonData(const std::vector<JsonData>& arr)
    : _type(ARRAY), _arr(arr) {}

JsonData::JsonData(bool b) : _type(BOOLEAN), _b(b) {}

JsonData::JsonData() : _type(NULLTYPE) {}

// Method
JsonType JsonData::getType() const { return _type; }

std::string JsonData::getString() const {
  if (_type != STRING) throw std::runtime_error("Type is not STRING.");
  return _str;
}

double JsonData::getNumber() const {
  if (_type != NUMBER) throw std::runtime_error("Type is not NUMBER.");
  return _num;
}

const std::vector<JsonData>& JsonData::getArray() const {
  if (_type != ARRAY) throw std::runtime_error("Type is not ARRAY.");
  return _arr;
}

const std::vector<std::pair<std::string, JsonData> >& JsonData::getObject()
    const {
  if (_type != OBJECT) throw std::runtime_error("Type is not OBJECT.");
  return _obj;
}

bool JsonData::getBoolean() const {
  if (_type != BOOLEAN) throw std::runtime_error("Type is not BOOLEAN.");
  return _b;
}
