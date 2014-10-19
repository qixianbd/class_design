/*
 * Collection.cc
 *
 *  Created on: 2014年10月19日
 *      Author: qmwx
 */
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Collection.h"


Collection::~Collection(){

}

Collection* Collection::getInstance(){
	return new Array();
}

static bool sortCmp(int a, int b){
	return a > b;
}

void SortArray::sort(){
	if(sortOrder == INCORDER){
		std::sort(getBase(), getBase()+size());
	}
	else{
		std::sort(getBase(), getBase()+size(), sortCmp);
	}
	return ;
}

bool SortArray::contains(int elem) const {
	bool ret = false;
	if(sortOrder == INCORDER){
		ret = std::binary_search(getBase(), getBase()+size(), elem);
	}
	else{
		ret =  std::binary_search(getBase(), getBase()+size(), elem, sortCmp);
	}
	return ret;
}

void SortArray::put(int elem) {
	Array::put(elem);
	sort();
}

int SortArray::diffCount() const {
}

int SortArray::maxNum() const {
	if(size() <= 0){
		throw std::out_of_range("the size of the Array is 0!\n");
	}
	if(INCORDER == sortOrder){
		return back();
	}
	else{
		return front();
	}

}
