/*
 * Set.h
 *
 *  Created on: 2014年10月17日
 *      Author: qmwx
 */

#ifndef SET_H_
#define SET_H_
#include <iostream>
#include <stdexcept>

template<typename T, size_t MAXSIZE = 10>
class Set{
public:
	typedef T* iterator;
	typedef const T* const_iterator;


	Set();
	void pushBack(const T& e);
	bool contains(const T& e)const;
	size_t getSize()const{
		return size;
	}
	const_iterator begin()const{
		return basePtr;
	}
	const_iterator end()const{
		return basePtr+size;
	}

	iterator begin(){
		return basePtr;
	}
	iterator end(){
		return basePtr+size;
	}
	void print(std::ostream&)const;
private:

	T* basePtr;
	size_t size;
};
template<typename T, size_t MAXSIZE>
std::ostream& operator<< (std::ostream&, Set<T, MAXSIZE> s);

template<typename T, size_t MAXSIZE>
Set<T, MAXSIZE>::Set(){
	basePtr = new T[MAXSIZE];
	size = 0;
}

template<typename T, size_t MAXSIZE>
void Set<T, MAXSIZE>::pushBack(const T& e){
	if(size >= MAXSIZE){
		throw std::out_of_range("size > MAXSIZE");
	}
	for(int i = 0; i < size; i++){
		if(basePtr[i] == e){
			return ;
		}
	}
	basePtr[size++] = e;
}

template<typename T, size_t MAXSIZE>
bool Set<T, MAXSIZE>::contains(const T& e)const{
	for(int i = 0; i < size; i++){
		if(basePtr[i] == e){
			return true;
		}
	}
	return false;
}

template<typename T, size_t MAXSIZE>
void Set<T, MAXSIZE>::print(std::ostream& os)const{
	for(int i = 0; i < size; i++){
		if(0 != i){
			os << ", ";
		}
		os << basePtr[i] ;
	}
	os << std::endl;
}

template<typename T, size_t MAXSIZE>
std::ostream& operator<< (std::ostream& os, Set<T,MAXSIZE> s){
	s.print(os);
	return os;
}


#endif /* SET_H_ */
