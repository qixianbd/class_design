/*
 * ListOfInt_Test.cc
 *
 *  Created on: 2014年10月18日
 *      Author: qmwx
 */
#include <iostream>
#include <assert.h>
#include "ListOfInt.h"

//#define UNITTEST

#ifdef UNITTEST

 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

 static int tests_run = 0;
 ListOfInt li;

 static void init(){
		for(int i =0; i < 10; i++){
			li.pushBack(i);
		}
		li.print(std::cout);
 }

 static char* test_pushBack(){
	 return 0;
 }

 static char* test_back(){
	 return 0;
 }

 static char * all_tests() {
	 init();
     mu_run_test(test_pushBack);
     mu_run_test(test_back);
     return 0;
 }

 int main(int argc, char **argv) {
     char *result = all_tests();
     if (result != 0) {
         std::cout << result << std::endl;
     }
     else {
         std::cout << "ALL TESTS PASSED\n" << std::endl;
     }
     std::cout << "Tests run: " << tests_run << "\n" << std::endl;

     return result != 0;
 }


#endif

template<typename T>
const T& mymax(const T& a, const T& b){
	if(a < b){
		return b;
	}
	else{
		return a;
	}
}


int main(){
	ListOfInt li;
	for(int i =0; i < 10; i++){
		li.pushBack(i);
	}
	li.print(std::cout);
	for(ListOfInt::const_iterator it = li.begin(); it != li.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	li.print(std::cout);


	int arr[] = {4, 5, 6, 7, 9};
	ListOfInt li2(arr, arr+4);
	li2.print(std::cout);
	li2.insert(li2.begin(), arr, arr+4);
	li2.print(std::cout);

	li2.insert(li2.begin(), li.begin(), li.end());
	li2.print(std::cout);
	li2.pushFront(1001);
	assert(1001 == li2.front());
	li2.pushBack(999);
	assert(999 == li2.back());

	ListOfInt li3;
	assert(true == li3.empty());
	assert(0 == li3.size());
	li3.insert(li3.begin(), 888);
	assert(888 == li3.front() && 888 == li3.back());
	assert(false == li3.empty() && li3.size() == 1);
	li3.insert(ListOfInt::iterator(), 777);
	assert(888 == li3.front());
	assert(777 == li3.back());
	assert(false == li3.empty() && li3.size() == 2);
	li3.insert(li3.end(), 666);
	assert(888 == li3.front());
	assert(777 == li3.back());
	assert(false == li3.empty() && li3.size() == 3);
	li3.print(std::cout);

	ListOfInt li4;
	li4 = li3;
	li4.print();

	ListOfInt li5(10);
	li5.print();

	ListOfInt li6(3, 101);
	li6.print();

	ListOfInt li7(li3.begin(), li3.end());
	li7.print();
	li7.swap(li3);
	std::cout << "Section 1" << std::endl;
	li7.print();
	li3.print();


	std::cout << mymax(5, 6) << std::endl;
	std::cout << "All The Test Past" << std::endl;
	return 0;
}



