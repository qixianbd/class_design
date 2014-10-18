/*
 * ListOfInt.h
 *
 *  Created on: 2014年10月18日
 *      Author: qmwx
 */

#ifndef LISTOFINT_H_
#define LISTOFINT_H_
#include <iostream>


class ListOfInt{
private:
	typedef int Type;
	struct Node{
		Type value;
		Node* prev;
		Node* next;
		Node():value(0), prev(NULL), next(NULL){

		}
		Node(int v):value(v), prev(NULL), next(NULL){

		}
	};
public:

	typedef Type value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type& pointer;
	typedef const value_type* const_pointer;
	typedef Node* link_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;


	struct iterator;
	typedef ListOfInt::iterator iterator;
	struct const_iterator;
	typedef ListOfInt::const_iterator const_iterator;

private:
	size_t len;
	link_type head;
	link_type tail;
protected:
	void copyOneValue(const ListOfInt& li);
	void finalizeList();
	void insert(link_type p, value_type v);
public:
	ListOfInt();
	ListOfInt(const ListOfInt& li);
	ListOfInt(int n);
	ListOfInt(int n, const_reference elem);
	ListOfInt(const_pointer beg, const_pointer end);
	ListOfInt(const_iterator beg, const_iterator end);

	ListOfInt& operator=(const ListOfInt& li);
	void swap(ListOfInt& li);

	void pushBack(value_type v);
	void pushFront(value_type v);
	reference front();
	const_reference front()const;
	reference back();
	const_reference back()const;

	iterator insert(iterator pos, const_reference elem);
	iterator insert(iterator pos, const_iterator beg, const_iterator end);
	iterator insert(iterator pos, const_pointer beg, const_pointer end);


	void print(std::ostream& = std::cout)const;
	bool empty();
	size_t size()const;
	~ListOfInt();

public:
	struct iterator{
	private:
		Node* curr;
		iterator(Node* n);
	public:
		iterator();
		iterator(const iterator& it);
		iterator& operator=(const iterator& it);
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);
		bool operator!=(const iterator& it)const;
		bool operator==(const iterator& it)const;
		int& operator*();
		friend class ListOfInt;
	};

	struct const_iterator{
	private:
		const Node* curr;
		const_iterator(const Node* n);
	public:
		const_iterator();
		const_iterator(const const_iterator& it);
		const_iterator(const iterator& it);
		const_iterator& operator=(const const_iterator& it);
		const_iterator operator++();
		const_iterator operator++(int);
		const_iterator operator--();
		const_iterator operator--(int);
		bool operator!=(const const_iterator& it)const;
		bool operator!=(const iterator& it)const;
		bool operator==(const const_iterator& it)const;
		bool operator==(const iterator& it)const;
		const value_type& operator*()const;
		friend class ListOfInt;
	};

	iterator begin();
	iterator end();
	const_iterator begin()const;
	const_iterator end()const;
};





#endif /* LISTOFINT_H_ */
