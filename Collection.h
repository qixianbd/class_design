/*
 * Collection.h
 *
 *  Created on: 2014年10月19日
 *      Author: qmwx
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_
#include <iostream>

class Collection{
public:
	static Collection* getInstance();
	virtual void assign(int* beg, int *end) = 0;
	virtual int front()const = 0;
	virtual int back()const = 0;
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual void put(int elem) = 0;
	virtual bool contains(int elem)const = 0;
	virtual ~Collection() = 0;
	virtual void print(std::ostream& os = std::cout)const = 0;
};

class List:public Collection{

};

class Array:public Collection{
private:
	int *base;
	int len;
	int maxsize;
	enum{DEFAULT_SIZE = 4};
private:
	Array(const Array&);
	Array& operator=(const Array&);
protected:
	void initArray(){
		maxsize = DEFAULT_SIZE;
		base = new int[maxsize];
		len = 0;
	}
	void finalizeMem(){
		delete[] base;
	}
	void increaseSize(){
		int *newBase = new int[maxsize*2];
		memcpy(newBase, base, maxsize*sizeof(int));
		finalizeMem();
		base = newBase;
		maxsize*=2;
	}
	int* getBase()const{
		return base;
	}

	int getMaxSize()const{
		return maxsize;
	}
public:
	Array():base(NULL), len(0), maxsize(DEFAULT_SIZE){
		initArray();
	}
	Array(int* beg, int* end):base(NULL), len(0), maxsize(DEFAULT_SIZE){
		initArray();
		for(int* pos = beg; pos != end; pos++){
			put(*pos);
		}
	}
	Array(int n):base(NULL), len(0), maxsize(n){
		initArray();
	}
	int front()const{
		return base[0];
	}
	int back()const{
		return base[len-1];
	}
	bool empty()const{
		return len == 0;
	}
	int size()const{
		return len;
	}
	virtual void assign(int* beg, int *end){
		finalizeMem();
		initArray();
		for(int* pos = beg; pos != end; pos++){
			put(*pos);
		}
	}
	virtual bool contains(int elem)const{
		for(int i = 0; i < len; i++){
			if(elem == base[i]){
				return true;
			}
		}
		return false;
	}
	virtual void put(int elem){
		if(len >= maxsize){
			increaseSize();
		}
		base[len++] = elem;
	}
	void print(std::ostream& os = std::cout)const{
		for(int i = 0; i < len; i++){
			os << base[i] << " ";
		}
		os << "\n";
	}
	virtual ~Array(){
		finalizeMem();
	}
};

class SortArray:public Array{
private:
	unsigned char sortOrder;
	enum {INCORDER = 0, DECORDER = 1};
private:
	SortArray(const SortArray&);
	SortArray& operator=(const SortArray&);
protected:
	void sort();
public:
	SortArray():Array(), sortOrder(INCORDER){
		sort();
	}
	SortArray(int* beg, int* end):Array(beg, end), sortOrder(INCORDER){
		sort();
	}
	SortArray(int n, unsigned char order = INCORDER):Array(n), sortOrder(order){
		sort();
	}
	void assign(int* beg, int* end){
		Array::assign(beg, end);
		sort();
	}
	bool contains(int elem)const;
	void put(int elem);
	int diffCount()const;
	int maxNum()const;
};


#endif /* COLLECTION_H_ */
