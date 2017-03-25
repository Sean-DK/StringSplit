# StringSplit

### StringSplit.cpp & StringSplit.hpp
  Include a single function, stringsplit(), that takes 2 strings as arguments. The first is the string that you want to split, the second is the delimiter you want to split with. This function returns a vector of strings, where each string is a substring of the original string broken at the delimiter.
    
    Example:
      stringsplit("one two three", " ") will return the vector {"one", "two", "three"}
  
  It's also possible for the delimiter to be more than a single character
    
    Example:
      stringsplit("onetwothree", "two") will return the vector {"one", "three"}
      
### RecursiveStringSplit.ccp & RecursiveStringSplit.hpp
  This was my original implementation of the function, however the time complexity is nasty bad. It would take upwards 10 minutes to go through 100,000 words, whereas the new version takes ~5 seconds to do the same amount. Rather than just throwing away this implementation I figured I would keep it as a separate file.
  
### main.cpp & 100k.txt & 10k.txt & 1k.txt
  These files make up a test suite for the function. Main.cpp goes through 10 test cases for the function to ensure that it is able to handle all the different scenarios of splitting a string. The text files are used as a test of the time complexity. 100k.txt contains exactly 100,000 words, 10k has 10,000, and 1k has 1,000.
  
## Why

I'm currently a student in my 3rd year of computer science and I've found that a lot of my projects require parsing and splitting strings in some way using C++. Since I couldn't find a good way to do this (I'm not a huge fan of how strtok() works), I decided to create my own function for fun and practice.
