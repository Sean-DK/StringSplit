//Sean Gaffney
//smgaffney@neo.rr.com

#include "StringSplit.hpp"
#include <iostream>

std::vector<std::string> stringsplit(const std::string& str, const std::string& delim) {  
  std::vector<std::string> result;
  if (delim == "" || str == "") return result;
  else if (delim.size() >= 1) return stringsplit(result, str, delim);
  else return result;
}

std::vector<std::string> stringsplit(std::vector<std::string>& result, const std::string& str, const std::string& delim) {
  if (str == "") return result;
  else if (str.find(delim) == 0) {
    std::string temp = "";
    for (int i = str.find(delim) + delim.size(); i < str.size(); temp += str[i++]);
    return stringsplit(result, temp, delim);
  }
  else if (str.find(delim) > 0 && str.find(delim) < 32767) {
    std::string temp = "";
    for (int i = 0; i < str.find(delim); temp += str[i++]);
    result.push_back(temp);
    temp = "";
    for (int i = str.find(delim) + delim.size(); i < str.size(); temp +=  str[i++]);
    return stringsplit(result, temp, delim);
  }
  else {
    result.push_back(str);
    return result;
  }
}

std::vector<std::string> itr_stringsplit(const std::string& s, const std::string& delim) {  
  std::vector<std::string> result;
  std::string str = s; //create a modifiable copy of the string
  do {
    if (delim == "" || str == "") return result; //if the string or delimiter are empty, return an empty vector
    else if (str.find(delim) == 0) str.erase(str.begin()); //if there is a delimiter at the beginning of the string, remove it
    else if (str.find(delim) > 0 && str.find(delim) < 32767) { //if there is a delimiter in the string
      result.push_back(str.substr(0, str.find(delim)));
      str.erase(str.begin(), str.begin() + str.find(delim) + delim.size());
    }
    else { //if there is no delimiter in the string
      result.push_back(str);
      return result;
    }
  } while(1);
}
