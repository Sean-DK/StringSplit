//Sean Gaffney
//smgaffney@neo.rr.com

#include "StringSplit.hpp"
#include <fstream>
#include <ctime>

namespace {
  void testResult(int num, bool pass) {
    if (pass)
      std::printf("%d ", num);
    else
      std::printf("X ");
  }
}


int main() {
  std::printf("\nstringsplit(string, delimiter): ");

  //1. Uninitialized string
  {
    std::string test;
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(1, vec.empty());
  }
  
  //2. Empty string
  {
    std::string test = "";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(2, vec.empty());
  }
  
  //3. Uninitialized delimiter
  {
    std::string test = "one";
    std::string delim;
    std::vector<std::string> vec = stringsplit(test, delim);
    testResult(3, vec.empty());
  }

  //4. Empty delimiter
  {
    std::string test = "one";
    std::vector<std::string> vec = stringsplit(test, "");
    testResult(4, vec.empty());
  }

  //5. String with no delimiter present
  {
    std::string test = "one";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(5, vec[0] == "one" && vec.size() == 1);
  }
  
  //6. String with 1 delimiter present
  {
    std::string test = "one two";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(6, vec[0] == "one" && vec[1] == "two" && vec.size() == 2);
  }
  
  //7. String with >1 delimiter
  {
    std::string test = "one two three";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(7, vec[0] == "one" && vec[1] == "two" && vec[2] == "three" && vec.size() == 3);
  }
  
  //8. Delimiter >1 byte
  {
    std::string test = "onetwothree";
    std::vector<std::string> vec = stringsplit(test, "two");
    testResult(8, vec[0] == "one" && vec[1] == "three" && vec.size() == 2);
  }

  //9. Delimiter at beginning of string
  {
    std::string test = " one";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(9, vec[0] == "one" && vec.size() == 1);
  }

  //10. Delimiter at end of string
  {
    std::string test = "one ";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(10, vec[0] == "one" && vec.size() == 1);
  }
  
  //11. String == Delimiter
  {
    std::string test = " ";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(11, vec.empty());  
  }
  
  //12. Adjacent delimiters
  {
    std::string test = "one    two";
    std::vector<std::string> vec = stringsplit(test, " ");
    testResult(12, vec[0] == "one" && vec[1] == "two" && vec.size() == 2);
  }

//Run time checks
  {
    std::printf("\n\n\tRun time:\n");
    //1,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("1k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = stringsplit(test, " ");
      clock_t end = clock();
      std::printf("\t1,000 words: %f seconds\n", double((end - start)) / CLOCKS_PER_SEC);
    }
    
    //10,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("10k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = stringsplit(test, " ");
      clock_t end = clock();
      std::printf("\t10,000 words: %f seconds\n", double((end - start)) / CLOCKS_PER_SEC);
    }

    //100,000 words
    {
      std::ifstream file;
      std::string test, temp;
      file.open("100k.txt");
      while (std::getline(file, temp))
	test += temp;
      clock_t start = clock();
      std::vector<std::string> vec = stringsplit(test, " ");
      clock_t end = clock();
      std::printf("\t100,000 words: %f seconds\n", double((end - start)) / CLOCKS_PER_SEC);
    }
  }

  return 0;
}
