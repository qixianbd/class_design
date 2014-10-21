/*
 * MemPool.h
 *
 *  Created on: 2014年10月19日
 *      Author: qmwx
 */

#ifndef MEMPOOL_H_
#define MEMPOOL_H_

struct BitMapMem{
	void* bitPtr;
	size_t blockNum;
	size_t blockSize;
	void* blockArrayPtr;
};


class MemPool{
private:
	void* basePtr;
	size_t totalMemSize;
	enum UNITSIZE{KUNIT = 1024, MUNIT = 1024*1024};
	enum MEMSIZE{SMALLSIZE = 64*KUNIT, MIDSIZE = 16*MUNIT, BIGSIZE = 512*MUNIT};
public:
	MemPool(size_t n = MIDSIZE);
	void* newMem(size_t size);
	void* deleteMem(void* p, size_t size);
	virtual ~MemPool();
};




#endif /* MEMPOOL_H_ */
