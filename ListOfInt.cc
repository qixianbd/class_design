/*
 * ListOfInt.cc
 *
 *  Created on: 2014年10月18日
 *      Author: qmwx
 */
#include <iostream>
#include <assert.h>
#include "ListOfInt.h"

template<typename TF>
void myswap(TF& a, TF& b){
	TF c = a;
	a = b;
	b = c;
}

ListOfInt::iterator::iterator() {
	curr = NULL;
}

ListOfInt::iterator::iterator(const iterator& it) {
	curr = it.curr;
}

ListOfInt::iterator::iterator(Node* n) {
	curr = n;
}

ListOfInt::iterator& ListOfInt::iterator::operator= (const iterator& it) {
	curr = it.curr;
	return *this;
}

ListOfInt::iterator ListOfInt::iterator::operator++() {
	curr = curr->next;
	return *this;
}

ListOfInt::iterator ListOfInt::iterator::operator++(int i) {
	Node *pos = curr;
	curr = curr->next;
	return ListOfInt::iterator(pos);
}

ListOfInt::iterator ListOfInt::iterator::operator --() {
	curr = curr->prev;
	return *this;
}

ListOfInt::iterator ListOfInt::iterator::operator --(int i) {
	Node *pos = curr;
	curr = curr->prev;
	return ListOfInt::iterator(pos);
}

bool ListOfInt::iterator::operator!=(const iterator& it)const {
	return curr != it.curr;
}

bool ListOfInt::iterator::operator==(const iterator& it)const {
	return curr == it.curr;
}

int& ListOfInt::iterator::operator *() {
	return curr->value;
}

ListOfInt::iterator ListOfInt::begin() {
	Node *pos = head;
	return ListOfInt::iterator(pos);
}

ListOfInt::iterator ListOfInt::end() {
	Node *pos = tail;
	return ListOfInt::iterator(pos);
}

ListOfInt::ListOfInt():len(0), head(NULL), tail(NULL){
}

void ListOfInt::pushBack(ListOfInt::value_type v) {
	Node *p = new Node(v);
	if(len == 0){
		head = p;
		tail = p;
		len++;
		return ;
	}
	else{
		p->next = NULL;
		p->prev = tail;
		tail->next = p;
		tail = p;
		len++;
		return ;
	}

}

void ListOfInt::pushFront(ListOfInt::value_type v) {
	Node *p = new Node(v);
	if(len == 0){
		head = p;
		tail = p;
		len++;
		return ;
	}
	else{
		p->next = head;
		p->prev = NULL;
		head->prev = p;
		head = p;
		len++;
		return ;
	}
}

void ListOfInt::print(std::ostream& os)const {
#if 0
	Node *pos = head;
	for(int i = 0; i < len; i++){
		os << pos->value << " ";
		pos = pos->next;
	}
	os << "\n";
	return ;
#else
	ListOfInt::const_iterator it = begin();
	for(int i = 0; i < len; i++, ++it){
		os << *it << " ";
	}
	os << "\n";
	return ;
#endif
}

bool ListOfInt::empty() {
	return len == 0;
}

size_t ListOfInt::size()const {
	return len;
}



ListOfInt::const_iterator::const_iterator(const Node* n):curr(n){
}

ListOfInt::const_iterator::const_iterator():curr(NULL) {
}

ListOfInt::const_iterator::const_iterator(const const_iterator& it) {
	curr = it.curr;
}

ListOfInt::const_iterator::const_iterator(const iterator& it) {
	curr = it.curr;
}

ListOfInt::const_iterator& ListOfInt::const_iterator::operator =(
		const const_iterator& it) {
	curr = it.curr;
	return *this;
}

ListOfInt::const_iterator ListOfInt::const_iterator::operator ++() {
	curr = curr->next;
	return *this;
}

ListOfInt::const_iterator ListOfInt::const_iterator::operator ++(int int1) {
	const Node* pos = curr;
	curr = curr->next;
	return ListOfInt::const_iterator(pos);
}

ListOfInt::const_iterator ListOfInt::const_iterator::operator --() {
	curr = curr->prev;
	return *this;
}

ListOfInt::const_iterator ListOfInt::const_iterator::operator --(int int1) {
	const Node *pos = curr;
	curr = curr->next;
	return ListOfInt::const_iterator(pos);
}

bool ListOfInt::const_iterator::operator !=(const const_iterator& it) const {
	return curr != it.curr;
}

bool ListOfInt::const_iterator::operator !=(const iterator& it) const {
	return curr != it.curr;
}

bool ListOfInt::const_iterator::operator ==(const const_iterator& it) const {
	return curr == it.curr;
}

bool ListOfInt::const_iterator::operator ==(const iterator& it) const {
	return curr == it.curr;
}

const ListOfInt::value_type& ListOfInt::const_iterator::operator *() const {
	return curr->value;
}

ListOfInt::const_iterator ListOfInt::begin() const {
	return ListOfInt::const_iterator(head);
}

ListOfInt::ListOfInt(const ListOfInt& li):len(0), head(NULL), tail(NULL)  {
	copyOneValue(li);
}

ListOfInt::ListOfInt(int n):len(0), head(NULL), tail(NULL) {
	for(int i = 0; i < n; i++){
		ListOfInt::value_type v;
		pushBack(v);
	}
}

ListOfInt::ListOfInt(int n, const_reference elem):len(0), head(NULL), tail(NULL){
	for(int i = 0; i < n; i++){
		ListOfInt::value_type v(elem);
		pushBack(v);
	}
}

ListOfInt::ListOfInt(const_pointer beg, const_pointer end):len(0), head(NULL), tail(NULL){
	for(const_pointer pos = beg; pos != end; pos++){
		ListOfInt::value_type v(*pos);
		pushBack(v);
	}
}

ListOfInt::ListOfInt(const_iterator beg, const_iterator end):len(0), head(NULL), tail(NULL){
	for(const_iterator pos = beg; pos != end; pos++){
		ListOfInt::value_type v(*pos);
		pushBack(v);
	}
}

ListOfInt& ListOfInt::operator=(const ListOfInt& li) {
	if(this == &li){
		return *this;
	}
	finalizeList();
	copyOneValue(li);
	return *this;
}

void ListOfInt::swap(ListOfInt& li) {
	myswap<size_t> (len, li.len);
	myswap<ListOfInt::link_type> (head, li.head);
	myswap<ListOfInt::link_type> (tail, li.tail);
}

ListOfInt::reference ListOfInt::front() {
	return *begin();
}

ListOfInt::const_reference ListOfInt::front() const {
	return *begin();
}

ListOfInt::reference ListOfInt::back() {
	return *end();
}

ListOfInt::const_reference ListOfInt::back() const {
	return *end();
}

ListOfInt::iterator ListOfInt::insert(iterator pos, const_reference elem) {
#if 0
	if(pos == end()){
		pushBack(elem);
		return pos;
	}
	else if(pos == begin()){
		pushFront(elem);
		return pos;
	}
	else{
		ListOfInt::Node* p = new ListOfInt::Node(elem);
		p->next = pos.curr;
		p->prev = pos.curr->prev;
		pos.curr->prev->next = p;
		pos.curr->prev = p;
		len++;
		return pos;
	}
#else
	ListOfInt::link_type p = pos.curr;
	insert(p, elem);
	return 0;
#endif
}

ListOfInt::iterator ListOfInt::insert(iterator pos, const_iterator beg,
		const_iterator end) {
	ListOfInt::link_type p = pos.curr;
	for(const_iterator it = beg; it != end; it++){
		insert(pos.curr, *it);
	}
	return pos;
}

ListOfInt::iterator ListOfInt::insert(iterator pos, const_pointer beg,
		const_pointer end) {
	ListOfInt::link_type p = pos.curr;
	for(const_pointer it = beg; it != end; it++){
		insert(pos.curr, *it);
	}
	return pos;
}

ListOfInt::~ListOfInt() {
	finalizeList();
}

void ListOfInt::finalizeList(){
	link_type pos = head;
	for(int i = 0; i < len; i++){
		link_type temp = pos->next;
		delete pos;
		pos = temp;
	}
}

void ListOfInt::copyOneValue(const ListOfInt& li) {
	len = 0;
	head = tail = NULL;
	const_iterator it = li.begin();
	for(int i = 0; i < li.len; i++, it++){
		pushBack(*it);
	}
	assert( len == li.len);
}

void ListOfInt::insert(ListOfInt::link_type p, ListOfInt::value_type v) {
	if(NULL == p){
		pushBack(v);
		return;
	}
	if(p == head){
		pushFront(v);
		return ;
	}
	else{
		ListOfInt::Node *value = new ListOfInt::Node(v);
		value->next = p;
		value->prev = p->prev;
		p->prev->next = value;
		p->prev = value;
		len++;
	}
}

ListOfInt::const_iterator ListOfInt::end() const {
	return ListOfInt::const_iterator(tail);
}



