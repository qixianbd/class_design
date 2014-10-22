/*
 * simpleMem.cc
 *
 *  Created on: 2014年10月21日
 *      Author: qmwx
 */
#include <map>
#include <list>
#include "simpleMem.h"

SimpleMem* SimpleMem::instance = NULL;

bool memBlockCmp(const SimpleMem::MemoryBlock* a, const SimpleMem::MemoryBlock* b){
	return a->blockSize <  b->blockSize || (a->blockSize ==  b->blockSize && a->blockPtr < b->blockPtr);
}

SimpleMem::SimpleMem(size_t n): base(NULL), maxsize(n){
	init();
}
void SimpleMem::init(){
	static void* memBase = operator new(100*MID_SIZE);
	std::cout << "***memBase size = " << sizeof(memBase) << std::endl;
	maxsize = 100*MID_SIZE;
	base = memBase;

	MemoryBlock *mb = new MemoryBlock(base,maxsize);
	unusedList.push_back(mb);
}

//size_t SimpleMem::getBlockSize(void* p) {
//}

void SimpleMem::arrangeMem(void* p) {

	return ;
}

SimpleMem* SimpleMem::getInstance(size_t n) {
	if(instance == NULL){
		instance = new SimpleMem(n);
	}
	return instance;
}

void* SimpleMem::mallocMem(size_t siz) {
	for(std::list<MemoryBlock*>::iterator it = unusedList.begin(); it != unusedList.end(); it++){
		if((*it)->blockSize == siz){
			void *ret = (*it)->blockPtr;
			usedList.push_back(*it);
			unusedList.erase(it);
			return ret;
		}
		else if((*it)->blockSize > siz){
			void* ret = (*it)->blockPtr;
			MemoryBlock *used = new MemoryBlock((*it)->blockPtr, siz);
			usedList.push_back(used);
			unsigned char* blockPtr = (unsigned char*)((*it)->blockPtr);
			blockPtr += siz;
			(*it)->blockPtr = blockPtr;
			(*it)->blockSize -= siz;

			unusedList.sort(memBlockCmp);
			usedList.sort(memBlockCmp);
			return ret;
		}
	}
	return NULL;
}
void SimpleMem::printList(LIST_TYPE ltype){
	std::list<MemoryBlock*> *plist;
	if(ltype == UNUSEDLIST){
		plist = &unusedList;
	}
	else{
		plist = &usedList;
	}
	for(std::list<MemoryBlock*>::iterator it = plist->begin(); it != plist->end(); it++){
		(*it)->print();
	}
	std::cout << "\n";
}
void SimpleMem::printUnusedList(){
	std::cout << "The unused list as follows:" << std::endl;
	printList(UNUSEDLIST);
}

void SimpleMem::printUsedList(){
	std::cout << "The used list as follows:" << std::endl;
	printList(USEDLIST);
}

void SimpleMem::deleteMem(void* p) {
	for(std::list<MemoryBlock*>::iterator it = usedList.begin(); it != unusedList.end(); it++){
		MemoryBlock *mb = *it;

		if(mb->blockPtr == p){
			unusedList.push_back(mb);
			usedList.erase(it);

			arrangeMem(p);
			unusedList.sort(memBlockCmp);
			usedList.sort(memBlockCmp);
			return ;
		}
	}
}


