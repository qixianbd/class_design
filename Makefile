CXX= g++
CC= g++
CFLAGS=  -c -g -Wall 
CXXFLAGS= -c -g -Wall 
LANG=en_US

.PHONY:all
all: MyString.out iterator_pattern_list.out Set.out ListOfInt_Test.out Collection_Test.out

MyString.out:MyString.o
	g++ -o $@ $^

iterator_pattern_list.out:iterator_pattern_list.o
	g++ -o $@ $^

MyString.o: MyString.cc MyString.h
iterator_pattern_list.o:iterator_pattern_list.cc iterator_pattern_list.h

Set.out:Set.o
	g++ -o $@ $^

Set.o:Set.cc Set.h

ListOfInt_Test.out: ListOfInt_Test.o ListOfInt.o
	g++ -o $@ $^
ListOfInt.o: ListOfInt.cc ListOfInt.h
ListOfInt_Test.o: ListOfInt_Test.cc ListOfInt.h

Collection_Test.out:Collection_Test.o Collection.o
	g++ -o $@ $^
Collection.o:Collection.cc Collection.h
Collection_Test.o:Collection_Test.cc Collection.h

.PHONY:clean
clean: 
	-rm  -f *.o *.out