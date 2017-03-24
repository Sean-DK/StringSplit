//Sean Gaffney
//smgaffney@neo.rr.com

#include "StringSplit.hpp"
#include <iostream>

std::vector<std::string> stringsplit(const std::string& s, const std::string& delim) {  
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