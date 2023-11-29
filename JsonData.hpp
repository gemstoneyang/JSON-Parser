#pragma once
#ifndef __JSONDATA_HPP__
#define __JSONDATA_HPP__

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

enum JsonType { STRING, NUMBER, OBJECT, ARRAY, BOOLEAN, NULLTYPE };

class JsonData {
 public:
  JsonData(const std::string& str);
  JsonData(double num);
  JsonData(const std::vector<std::pair<std::string, JsonData> >& obj);
  JsonData(const std::vector<JsonData>& arr);
  JsonData(bool b);
  JsonData();

  JsonType getType() const;
  std::string getString() const;
  double getNumber() const;
  const std::vector<JsonData>& getArray() const;
  const std::vector<std::pair<std::string, JsonData> >& getObject() const;
  bool getBoolean() const;

 private:
  JsonType _type;
  std::string _str;
  double _num;
  std::vector<JsonData> _arr;
  std::vector<std::pair<std::string, JsonData> > _obj;
  bool _b;
};

#endif