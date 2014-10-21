/*
 * simpleMem.h
 *
 *  Created on: 2014年10月21日
 *      Author: qmwx
 */

#ifndef SIMPLEMEM_H_
#define SIMPLEMEM_H_
#include <iostream>
#include <map>
#include <list>


class SimpleMem{
private:
	struct MemoryBlock{
		void* blockPtr;
		size_t blockSize;
		MemoryBlock(){

		}
		MemoryBlock(void* p, size_t n):blockPtr(p), blockSize(n){

		}
		void print(){
			std::cout << "ptr = " << blockPtr << ", size = " << blockSize << "\n";
		}
	};

	void *base;
	size_t maxsize;
	std::list<MemoryBlock*> usedList;
	std::list<MemoryBlock*> unusedList;

	void init();
	SimpleMem(size_t n);
	static SimpleMem* instance;

	enum TOTAL_MEM_SIZE{SMALL_SIZE = 64* 1024, MID_SIZE = 1024*1024, BIG_SIZE = 64*1024*1024};
	enum LIST_TYPE{USEDLIST = 0, UNUSEDLIST = 1};
private:
	SimpleMem operator=(const SimpleMem&);
	SimpleMem(const SimpleMem&);
protected:
	size_t getBlockSize(void* p);
	void arrangeMem(void* p);

	void printList(LIST_TYPE ltype);
public:
	static SimpleMem* getInstance(size_t n);
	void* mallocMem(size_t siz);
	void deleteMem(void *p);

	void printUnusedList();
	void printUsedList();
};



#endif /* SIMPLEMEM_H_ */
