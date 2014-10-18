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
}



