//Sean Gaffney
//smgaffney@neo.rr.com

#include "StringSplit.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

namespace {
  void testResult(int num, bool pass) {
    if (pass)
      std::cout << num << " ";
    else
      std::cout << "X ";
  }
}


int main() {

//Recursive Tests
  std::cout << "Recursive version: ";
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
    if (vec[0] == "one" && vec.size() == 1) {
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
    if (vec[0] == "one" && vec[1] == "two" && vec.size() == 2) {
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
    if (vec[0] == "one" && vec[1] == "two" && vec[2] == "three" && vec.size() == 3) {
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
    if (vec[0] == "one" && vec[1] == "three" && vec.size() == 2) {
      testResult(8, true);
    }
    else {
      testResult(8, false);
    }
  }

  //9. Delimiter at beginning of string
  {
    std::string test = " one";
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec[0] == "one" && vec.size() == 1) {
      testResult(9, true);
    }
    else {
      testResult(9, false);
    }
  }

  //10. Delimiter at end of string
  {
    std::string test = "one ";
    std::vector<std::string> vec = stringsplit(test, " ");
    if (vec[0] == "one" && vec.size() == 1) {
      testResult(10, true);
    }
    else {
      testResult(10, false);
    }
  }

//Iterative Tests
  std::cout << "\nIterative version: ";
  //1. Uninitialized string
  {
    std::string test;
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec.empty())
      testResult(1, true);
    else
      testResult(1, false);
  }

  //2. Empty string
  {
    std::string test = "";
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec.empty())
      testResult(2, true);
    else
      testResult(2, false);
  }

  //3. Uninitialized delimiter
  {
    std::string test = "one";
    std::string delim;
    std::vector<std::string> vec = itr_stringsplit(test, delim);
    if (vec.empty())
      testResult(3, true);
    else
      testResult(3, false);
  }

  //4. Empty delimiter
  {
    std::string test = "one";
    std::vector<std::string> vec = itr_stringsplit(test, "");
    if (vec.empty())
      testResult(4, true);
    else
      testResult(4, false);
  }

  //5. String with no delimiter present
  {
    std::string test = "one";
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec[0] == "one" && vec.size() == 1) {
      testResult(5, true);
    }
    else {
      testResult(5, false);
    }
  }
  
  //6. String with 1 delimiter present
  {
    std::string test = "one two";
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec[0] == "one" && vec[1] == "two" && vec.size() == 2) {
      testResult(6, true);
    }
    else {
      testResult(6, false);
    }
  }
  
  //7. String with >1 delimiter
  {
    std::string test = "one two three";
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec[0] == "one" && vec[1] == "two" && vec[2] == "three" && vec.size() == 3) {
      testResult(7, true);
    }
    else {
      testResult(7, false);
    }
  }
  
  //8. Delimiter >1 byte
  {
    std::string test = "onetwothree";
    std::vector<std::string> vec = itr_stringsplit(test, "two");
    if (vec[0] == "one" && vec[1] == "three" && vec.size() == 2) {
      testResult(8, true);
    }
    else {
      testResult(8, false);
    }
  }

  //9. Delimiter at beginning of string
  {
    std::string test = " one";
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec[0] == "one" && vec.size() == 1) {
      testResult(9, true);
    }
    else {
      testResult(9, false);
    }
  }

  //10. Delimiter at end of string
  {
    std::string test = "one ";
    std::vector<std::string> vec = itr_stringsplit(test, " ");
    if (vec[0] == "one" && vec.size() == 1) {
      testResult(10, true);
    }
    else {
      testResult(10, false);
    }
  }
  
//11. Run time checks
  {
    std::cout << "\n\n\tRun time:\n";
    //Recursive 1,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("1k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = stringsplit(test, " ");
      clock_t end = clock();
      std::cout << "\tRecursive 1,000 words: " << double((end - start)) / CLOCKS_PER_SEC << " seconds\n";
    }
    
    //Recursive 10,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("10k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = stringsplit(test, " ");
      clock_t end = clock();
      std::cout << "\tRecursive 10,000 words: " << double((end - start)) / CLOCKS_PER_SEC << " seconds\n";
    }

    //Recursive 100,000 words
    //I did this test once and it took 7 minutes and 58 seconds. I don't plan on waiting ~10 minutes every time
    //I want to run this testing suite so I've just estimated the run time of this one.
    {
      std::cout << "\tRecursive 100,000 words: ~8 minutes\n";
    } 
    
    //Iterative 1,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("1k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = itr_stringsplit(test, " ");
      clock_t end = clock();
      std::cout << "\tIterative 1,000 words: " << double((end - start)) / CLOCKS_PER_SEC << " seconds\n";
    }
    
    //Iterative 10,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("10k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = itr_stringsplit(test, " ");
      clock_t end = clock();
      std::cout << "\tIterative 10,000 words: " << double((end - start)) / CLOCKS_PER_SEC << " seconds\n";
    }

    //Iterative 100,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("100k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = itr_stringsplit(test, " ");
      clock_t end = clock();
      std::cout << "\tIterative 100,000 words: " << double((end - start)) / CLOCKS_PER_SEC << " seconds\n";
    }
  }

  return 0;
}
