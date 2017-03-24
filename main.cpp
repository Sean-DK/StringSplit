//Sean Gaffney
//smgaffney@neo.rr.com

#include "StringSplit.hpp"
#include <iostream>

namespace {
  void testResult(int num, bool pass) {
    if (pass)
      std::cout << num << ". Passed\n";
    else
      std::cout << num << ". Failed\n";
  }
}


int main() {

  //1. Uninitialized string
  {
    std::string test;
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec.empty())
      testResult(1, true);
    else
      testResult(1, false);
  }

  //2. Empty string
  {
    std::string test = "";
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec.empty())
      testResult(2, true);
    else
      testResult(2, false);
  }

  //3. Uninitialized delimiter
  {
    std::string test = "one";
    std::string delim;
    std::vector<std::string> vec = stringsplit(test, delim);
    if (vec.empty())
      testResult(3, true);
    else
      testResult(3, false);
  }

  //4. Empty delimiter
  {
    std::string test = "one";
    std::vector<std::string> vec = stringsplit(test, "");
    if (vec.empty())
      testResult(4, true);
    else
      testResult(4, false);
  }

  //5. String with no delimiter present
  {
    std::string test = "one";
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec[0] == "one") {
      testResult(5, true);
    }
    else {
      testResult(5, false);
    }
  }
  
  //6. String with 1 delimiter present
  {
    std::string test = "one two";
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec[0] == "one" && vec[1] == "two") {
      testResult(6, true);
    }
    else {
      testResult(6, false);
    }
  }
  
  //7. String with >1 delimiter
  {
    std::string test = "one two three";
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec[0] == "one" && vec[1] == "two" && vec[2] == "three") {
      testResult(7, true);
    }
    else {
      testResult(7, false);
    }
  }
  
  //8. Delimiter >1 byte
  {
    std::string test = "onetwothree";
    std::vector<std::string> vec = stringsplit(test, "two");
    if (vec[0] == "one" && vec[1] == "three") {
      testResult(8, true);
    }
    else {
      testResult(8, false);
    }
  }

  return 0;
}
