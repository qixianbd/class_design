/*
 * MyString.h
 *
 *  Created on: 2014年9月29日
 *      Author: qmwx
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include <new>




inline void* operator new(size_t siz){
	void *p = malloc(siz);
	if(p){
		printf("malloc  a new block of memory at 0x%p\n", p);
	}
	else{
		fprintf(stderr, "not enough memory");
		throw std::bad_alloc();
	}
	return p;

}

inline void* operator new[](size_t siz){
	void *p = malloc(siz);
	if(p){
		printf("malloc [] a new block of memory at 0x%p\n", p);
	}
	else{
		fprintf(stderr, "not enough memory");
		throw std::bad_alloc();
	}
	return p;

}

inline void operator delete(void* p){
	printf("free block at 0x%p\n", p);
	free(p);
}

inline void operator delete[](void* p){
	printf("free block[] at 0x%p\n", p);
	free(p);
}


class MyString{
public:
	MyString();
	MyString(const char* cstr);
	MyString(const MyString& str);
	MyString(const MyString& str, int beg, int end = -1);

	MyString operator=(const MyString& str);
	MyString operator=(const char* str);
	MyString operator+(const MyString& str)const;
	MyString operator*(unsigned int times)const;
	MyString& operator+= (const MyString& str);
	const char& operator[](int index)const;
	char& operator[](int index);

	MyString subString(int beg, int end = -1)const;
	int searchPattern(const char* pattern)const;
	int searchChar(char ch)const;

	const char* toCStr()const{
		return cstr;
	}

	operator const char*()const{
		return cstr;
	}


	virtual ~MyString(){
		delete[] cstr;
		cstr = NULL;
	}

	friend std::istream& operator>> (std::istream& in, MyString& str);
	friend std::ostream& operator<< (std::ostream& out, const MyString& str);

private:
	char* cstr;
};




#endif /* MYSTRING_H_ */
