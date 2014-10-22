/*
 * simpleMem_Test.cc
 *
 *  Created on: 2014年10月22日
 *      Author: qmwx
 */
#include <iostream>
#include "simpleMem.h"


int main()
{
	SimpleMem *sm = SimpleMem::getInstance(1024);
	void* p1 = sm->mallocMem(100);
	void* p2 = sm->mallocMem(64);
	void*p3 = sm->mallocMem(32);

	sm->deleteMem(p2);

	sm->printUnusedList();
	sm->printUsedList();

	void*ptrArr [1024];
	for(int i = 0; i < 1024; i++){
		ptrArr[i] = sm->mallocMem(i*2);
	}
	for(int i = 0; i < 1024; i+= 2){
		sm->deleteMem(ptrArr[i]);
	}

	void* ptr[100];
	for(int i = 0; i < 100; i++){
		ptr[i] = sm->mallocMem(i);
	}

	sm->printUnusedList();
	sm->printUsedList();

	return 0;
}


