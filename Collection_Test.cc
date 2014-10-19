/*
 * Collection_Test.cc
 *
 *  Created on: 2014年10月19日
 *      Author: qmwx
 */
#include <iostream>
#include "Collection.h"
#include "assert.h"


int main()
{
	Collection *c = Collection::getInstance();
	for(int i = 0; i < 3; i++){
		c->put(i*3);
	}
	c->print();

	assert(0 == c->front() );
	assert(6 == c->back());
	assert(3 == c->size() && false == c->empty());

	int a[] = {3, 6, 1, 2, 5, 9, 7};
	SortArray sa(a, a+sizeof(a)/sizeof(a[0]));
	sa.put(4);
	sa.print();

	Array ar(a, a+sizeof(a)/sizeof(a[0]));
	ar.put(4);
	ar.print();

	Collection* p = new SortArray();
	p->assign(a, a+sizeof(a)/sizeof(a[0]));
	p->print();


	std::cout << "All Test have past." << std::endl;
	return 0;
}



