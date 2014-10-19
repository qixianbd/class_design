class_design
============

The design and implementation of some typical class in cpp. The important is the interface of the class. 

The class---->

(1) iterator_pattern_list.h: define the class AbstractList, List, Iterator, ListIterator.
--> It's a failed trying to simulate and implement the std::list. (ie, it try to give a template implementation.)


(2) MyString.h: define the class MyString.
-->This is a class trying to analog the standard class string in std::string. 


(3) Person.h Student.h:  define the class Person and Student.
-->This is a very simple class I used to test the use of class inheritation. 

(4)Set.h: define the class Set. 
--> A very simple implementation of set. 

(5)ListOfInt.h: define the class ListOfInt.
-->This is a list container which its value is int. 

(6) Collection.h: define the pure class Collection, and class Array, List, SortArray.
-->  The inheritation relationship is SortArray < Array < Collection, List < Collection. 

