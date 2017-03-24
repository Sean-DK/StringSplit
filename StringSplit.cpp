//Sean Gaffney
//smgaffney@neo.rr.com

#include "StringSplit.hpp"
#include <iostream>

std::vector<std::string> stringsplit(const std::string& str, const std::string& delim) {  
  std::vector<std::string> result;
  if (delim == "" || str == "") return result;
  else if (delim.size() >= 1) {
    return stringsplit(result, str, delim);
  }
  else return result;
}

std::vector<std::string> stringsplit(std::vector<std::string>& result, const std::string& str, const std::string& delim) {
  int delimPos = 0;
  if (str == "") {
    return result;
  }
  else if (str.find(delim) > 0 && str.find(delim) < 32766) {
    std::string temp = "";
    delimPos = str.find(delim);
    for (int i = 0; i < delimPos; i++) {
      temp += str[i];
    }
    result.push_back(temp);
    temp = "";
    for (int i = delimPos + delim.size(); i < str.size(); i++) {
      temp += str[i];
    }
    return stringsplit(result, temp, delim);
  }
  else {
    result.push_back(str);
    return result;
  }
}
