//Sean Gaffney
//smgaffney@neo.rr.com

#include "RecursiveStringSplit.hpp"

std::vector<std::string> rec_stringsplit(const std::string& str, const std::string& delim) {  
  std::vector<std::string> result;
  if (delim == "" || str == "") return result;
  else if (delim.size() >= 1) return rec_stringsplit(result, str, delim);
  else return result;
}

std::vector<std::string> rec_stringsplit(std::vector<std::string>& result, const std::string& str, const std::string& delim) {
  if (str == "") return result;
  else if (str.find(delim) == 0) {
    std::string temp = "";
    for (int i = str.find(delim) + delim.size(); i < str.size(); temp += str[i++]);
    return rec_stringsplit(result, temp, delim);
  }
  else if (str.find(delim) > 0 && str.find(delim) < 32767) {
    std::string temp = "";
    for (int i = 0; i < str.find(delim); temp += str[i++]);
    result.push_back(temp);
    temp = "";
    for (int i = str.find(delim) + delim.size(); i < str.size(); temp +=  str[i++]);
    return rec_stringsplit(result, temp, delim);
  }
  else {
    result.push_back(str);
    return result;
  }
}