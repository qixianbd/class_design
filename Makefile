CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 
LANG=en_US

.PHONY:all
all: MyString iterator_pattern_list Set ListOfInt_Test

MyString:MyString.o
	g++ -o $@ $^

iterator_pattern_list:iterator_pattern_list.o
	g++ -o $@ $^

MyString.o: MyString.cc MyString.h
iterator_pattern_list.o:iterator_pattern_list.cc iterator_pattern_list.h

Set:Set.o
	g++ -o $@ $^

Set.o:Set.cc Set.h

ListOfInt_Test: ListOfInt_Test.o ListOfInt.o
	g++ -o $@ $^
ListOfInt.o: ListOfInt.cc ListOfInt.h
ListOfInt_Test.o: ListOfInt_Test.cc ListOfInt.h



.PHONY:clean
clean: 
	-rm  -f *.o 