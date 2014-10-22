/*
 * MyString.cc
 *
 *  Created on: 2014年9月29日
 *      Author: qmwx
 */

#include "MyString.h"

//#include <stdio.h>
#include <string.h>
#include <iostream>
#include <istream>
#include <stdexcept>






void* operator new(size_t siz, double d){
	SimpleMem *sm = SimpleMem::getInstance(1024);
	void *p = sm->mallocMem(siz);
	if(p){
		printf("malloc  a new block of memory at 0x%p\n", p);
	}
	else{
		fprintf(stderr, "not enough memory");
		throw std::bad_alloc();
	}
	return p;

}

void* operator new[](size_t siz, double d){
	SimpleMem *sm = SimpleMem::getInstance(1024);
	void *p = sm->mallocMem(siz);
	if(p){
		printf("malloc [] a new block of memory at 0x%p\n", p);
	}
	else{
		fprintf(stderr, "not enough memory");
		throw std::bad_alloc();
	}
	return p;

}

void operator delete(void* p, double d){
	printf("free block at 0x%p\n", p);
	SimpleMem *sm = SimpleMem::getInstance(1024);
	sm->deleteMem(p);
}

void operator delete[](void* p, double d){
	printf("free block[] at 0x%p\n", p);
	SimpleMem *sm = SimpleMem::getInstance(1024);
	sm->deleteMem(p);
}



MyString::MyString(){
	this->cstr = new (0.0) char [1];
	*cstr = '\0';
}


MyString::MyString(const char* str){
	if(NULL == str){
		this->cstr = new (0.0) char [1];
		*cstr = '\0';
	}
	int len = strlen(str);
	cstr = new (0.0) char [len + 1];
	strncpy(cstr, str, len+1);
}

MyString::MyString(const MyString& str){
	int len = strlen(str.toCStr());
	cstr = new (0.0) char [len+1];
	strncpy(cstr, str.toCStr(), len+1);
}

MyString::MyString(const MyString& str, int beg, int end ){
	int slen = strlen(str.toCStr());
	if(beg < 0 || end > slen){
		throw std::out_of_range("11cstr");
	}
	if(end == -1){
		end = slen;
	}
	int len = end - beg;
	cstr = new (0.0) char [len + 1];
	const char *p = str.toCStr() + beg;
	strncpy(cstr, p, len);
	*(cstr + len) = '\0';
}

MyString::~MyString(){
	operator delete[]  (cstr, 0.0);
	cstr = NULL;
}

MyString MyString::operator= (const MyString &str){
	if(this == &str){
		return *this;
	}
	return operator=(str.toCStr());
}

MyString MyString::operator=(const char* str){
	int len = strlen(str);
	char *temp = new (0.0) char [len+1];
	strncpy(temp, str, len+1);
	delete[] cstr;
	cstr = temp;
	return *this;
}


MyString MyString::operator+(const MyString& str)const{
	MyString sum;
	char *s = new (0.0) char[strlen(cstr) + strlen(str.toCStr()) + 1];
	strncpy(s, cstr, strlen(cstr));
	strcat(s, str.toCStr());
	sum = s;
	return sum;
}

MyString& MyString::operator+= (const MyString& str){
	char *s = new (0.0) char[strlen(cstr) + strlen(str.toCStr()) + 1];
	strncpy(s, cstr, strlen(cstr));
	strcat(s, str.toCStr());
	operator delete[]  (cstr, 0.0);
	cstr = s;
	return *this;
}


MyString MyString::operator*(unsigned int times)const{
	if(0 == times){
		return MyString();
	}
	int len = strlen(cstr) * times;
	char *s = new (0.0) char [len+1];
	char *p = s;
	for(; times > 0; times--){
		strncpy(p, cstr, strlen(cstr));
		p += strlen(cstr);
	}
	*p = '\0';

	return MyString(s);
}

const char& MyString::operator[](int index)const{
	if(index < 0 || index > (int)strlen(cstr)-1){
		throw std::out_of_range("cstr");
	}
	return cstr[index];
}


char& MyString::operator[](int index){
	if(index < 0 || index > (int)strlen(cstr)-1){
		throw std::out_of_range("cstr");
	}
	return cstr[index];
}


MyString  MyString::subString(int beg, int end)const{

	if(beg < 0 || end > (int)strlen(cstr)){
		throw std::out_of_range("1cstr");
	}
	if(end == -1){
		end = strlen(cstr);
	}
	return MyString(*this, beg, end);
}

int MyString::searchChar(char ch)const{
	const char* p = cstr;
	while(*p){
		if(*p == ch){
			return (p - cstr);
		}
	}
	return -1;
}

int MyString::searchPattern(const char* pattern)const{
	char *ret = NULL;
	ret = strstr(cstr, pattern);
	if(NULL == ret){
		return -1;
	}
	return (ret-cstr);
}



std::istream& operator>> (std::istream& in, MyString& str){
	in >> str.cstr;
	return in;
}

std::ostream& operator<< (std::ostream& out, const MyString& str){
	out << str.cstr;
	return out;
}



int main()
{
#if 0
	MyString str;
	std::cin >> str;
	MyString str2(str);
	MyString sum = str + str2;
	std::cout << sum << std::endl;
	MyString ret = str * 5;
	std::cout << ret << std::endl;

	ret[10] = 'A';
	std::cout << ret << std::endl;

	MyString newRet = ret.subString(0, 12);
	std::cout << newRet << std::endl;

	int pos = ret.searchPattern("ming");
	std::cout << pos << std::endl;

	pos = ret.searchChar('k');
	std::cout << pos << std::endl;

	newRet += ret;
	std::cout << newRet << std::endl;
#endif
	SimpleMem *sm = SimpleMem::getInstance(1024);
	void* p1 = sm->mallocMem(100);
	void* p2 = sm->mallocMem(64);
	void*p3 = sm->mallocMem(32);

	sm->deleteMem(p2);

	sm->printUnusedList();
	sm->printUsedList();
	MyString ms("Hello,world!");
	MyString str1(ms);
	str1 += "keyming";
	std::cout << strlen((const char*)ms) << std::endl;


	sm->printUnusedList();
	sm->printUsedList();

	return 0;
}

