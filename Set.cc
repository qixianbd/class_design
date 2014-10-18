/*
 * Set.cc
 *
 *  Created on: 2014年10月17日
 *      Author: qmwx
 */
#include <iostream>
#include "Set.h"

int main()
{
	Set<int, 10> s;
	for(int i = 0; i < 10; i++){
		s.pushBack(i);
	}
	s.print(std::cout);

	Set<double, 20> sd;
	for(int i = 0; i < 20; i++){
		sd.pushBack(i/3.0);
	}
	sd.print(std::cout);
	std::cout << sd << s << std::endl;

	Set<double, 20>::iterator pos;
	for(pos = sd.begin(); pos != sd.end(); pos++){
		std::cout << *pos << "  " << std::endl;
	}
	return 0;
}



