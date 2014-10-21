/*
 * MemPool.cc
 *
 *  Created on: 2014年10月19日
 *      Author: qmwx
 */
#include <iostream>
#include "MemPool.h"

MemPool::MemPool(size_t n) {
	if(n <= MemPool::MIDSIZE){
		totalMemSize = MemPool::MIDSIZE;
	}
	else
}

void* MemPool::newMem(size_t size) {
}

void* MemPool::deleteMem(void* p, size_t size) {
}

MemPool::~MemPool() {
}
