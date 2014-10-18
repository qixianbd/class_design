/*
 * iterator_pattern_list.h
 *
 *  Created on: 2014年9月29日
 *      Author: qmwx
 */

#ifndef ITERATOR_PATTERN_LIST_H_
#define ITERATOR_PATTERN_LIST_H_
#include <stdexcept>

template<typename Item> class Iterator;
template<typename Item> class ListIterator;


template<typename Item>
class AbstractList{
public:
	virtual Iterator<Item>* createIterator()const = 0;
};


template<typename Item>
class List:public AbstractList<Item>{
private:
	struct Node{
		Item value;
		Node *prev;
		Node *next;
		Node(Item i, Node* p, Node *n): value(i), prev(p), next(n){

		}
	};
	Node* head;
	Node* tail;
	mutable Node* currentPtr;
	long len;
	mutable long currentPos;
public:
	List(){
		head = NULL;
		tail = NULL;
		len = 0;
		currentPtr = NULL;
		currentPos = -1;
	}
	long count()const{
		return len;
	}

	void push_back(Item node);
	void push_front(Item node);
	Item& getBack();
	Item& getFront();

	Item& getItem(long index)const;
	Iterator<Item>* createIterator()const{
		return new ListIterator<Item>(this);
	}
	void printList()const;

};



template<class Item>
class Iterator{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone()const = 0;
	virtual Item& currentItem()const = 0;
	//virtual Item& operator!= ()const = 0;
	//virtual ~Iterator() = 0;
protected:
	Iterator(){

	}
};

template<typename Item>
void traverseCollection(const Iterator<Item>& beg, const Iterator<Item>& end, void (*process)(Item& item)){
	Iterator<Item>& pos = const_cast<Iterator<Item>& > (beg);
	while(!pos.isDone() && pos != end){
		process(pos.currentItem());
		pos.next();
	}
}

template<class Item>
class ListIterator : public Iterator<Item>{
public:
	ListIterator(const List<Item>* aList);
	virtual void first();
	virtual void next();
	virtual bool isDone()const;
	virtual Item& currentItem()const;
//	virtual Item& operator!= (){
//
//	}

private:
	const List<Item>* _list;
	long _current;
};


template<typename Item>
void List<Item>::push_back(Item node){
	if(len == 0){
		Node *p = new Node(node, NULL, NULL);
		head = p;
		tail = p;
		len++;
		currentPos = 0;
		currentPtr = head;
	}
	else{
		Node *p = new Node(node, tail, NULL);
		tail->next = p;
		tail = p;
		len++;
	}
	return ;
}

template<typename Item>
void List<Item>::push_front(Item node){
	if(len == 0){
		Node *p = new Node(node, NULL, NULL);
		head = p;
		tail = p;
		len++;
		currentPos = 0;
		currentPtr = head;
	}
	else{
		Node *p = new Node(node, NULL, head);
		head->prev = p;
		head = p;
		len++;
	}
	return ;
}

template<typename Item>
Item& List<Item>::getBack(){
	if(len <= 0){
		throw std::out_of_range("The len of the list is zero");
	}
	return tail->value;
}

template<typename Item>
Item& List<Item>::getFront(){
	if(len <= 0){
		throw std::out_of_range("The len of the list is zero");
	}
	return head->value;
}

template<typename Item>
Item& List<Item>::getItem(long index)const{
	if(index < 0 || index >= len){
		throw std::out_of_range("index out of range");
	}
	if(index == currentPos){
		return currentPtr->value;
	}
	else if(index < currentPos){
		while(currentPos > index){
			currentPtr = currentPtr->prev;
			currentPos--;
		}
		return currentPtr->value;
	}
	else{
		while(currentPos < index){
			currentPtr = currentPtr->next;
			currentPos++;
		}
		return currentPtr->value;
	}
}

template<typename Item>
void List<Item>::printList()const{
	for(int i = 0; i < len; i++){

		Item o = getItem(i);
		std::cout << o <<std::endl;
	}
}



template<class Item>
ListIterator<Item>::ListIterator(const List<Item>* aList):_list(aList), _current(0){

}

template<class Item>
void ListIterator<Item>::first(){
	_current = 0;
}

template<class Item>
void ListIterator<Item>::next(){
	_current++;
}

template <class Item>
bool ListIterator<Item>::isDone()const{
	return _current >= _list->count();
}

template<class Item>
Item& ListIterator<Item>::currentItem()const{
	if(isDone()){
		throw std::out_of_range("iterator");
	}
	return _list->getItem(_current);
}





#endif /* ITERATOR_PATTERN_LIST_H_ */
