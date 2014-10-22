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
#include "simpleMem.h"


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


	virtual ~MyString();

	friend std::istream& operator>> (std::istream& in, MyString& str);
	friend std::ostream& operator<< (std::ostream& out, const MyString& str);

private:
	char* cstr;
};




#endif /* MYSTRING_H_ */
