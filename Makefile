CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 
LANG=en_US

.PHONY:all
all: MyString

MyString:MyString.o
	g++ -o $@ $^

MyString.o: MyString.cc MyString.h

.PHONY:clean
clean: 
	-rm  -f *.o 