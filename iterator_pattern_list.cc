/*
 * iterator_pattern_list.cc
 *
 *  Created on: 2014年9月29日
 *      Author: qmwx
 */
#include <iostream>
#include "Student.h"
#include "iterator_pattern_list.h"

template<typename Item>
void process(Item& item){
	std::cout << item << "****" << std::endl;
}

int main(){
	List<int> iList;
	Iterator<int>* it = iList.createIterator();
	for(int i = 0; i < 10; i++){
		iList.push_back(i);
	}
	iList.printList();

	it->first();
	while(!it->isDone()){
		it->currentItem() = it->currentItem() * 2;
		std::cout << it->currentItem() << std::endl;
		it->next();
	}

	List<Student> sList;
	for(int i = 0; i < 10; i++){
		Student stu(i, "ming", i-2, i*2);
		sList.push_back(stu);
	}
	sList.printList();
	std::cout << "********************" << std::endl;
	Iterator<Student>* sit = sList.createIterator();
	sit->first();
	Iterator<Student>* cp = sit;
	while(!sit->isDone()){
		std::cout << sit->currentItem() << std::endl;
		sit->next();
	}
	//traverseCollection(*cp, *sit, process);
}




