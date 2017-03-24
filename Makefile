# Makefile for StringSplit
#
# To build:
#   make
#
# To clean build:
#   make clean

all : StringSplit

# main program
StringSplit : StringSplit.o main.o
	g++ -std=c++11 main.o StringSplit.o -o StringSplit

StringSplit.o : StringSplit.cpp StringSplit.hpp
	g++ -std=c++11 -c StringSplit.cpp

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

clean :
	rm -f StringSplit.o StringSplit main.o

test : StringSplit
	./StringSplit
