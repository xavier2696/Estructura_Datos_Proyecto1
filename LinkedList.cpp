#include "object.h"
#include "tdalist.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::cout;

LinkedList::Node::Node(Object* Data, Node* Next){
	data = Data;
	next = Next;
}

LinkedList::Node::~Node(){
	if(data)
		delete data;
	if(next)
		delete next;
}
LinkedList::LinkedList(){
	head = NULL;
}

LinkedList::~LinkedList(){
	if(head)
		delete head;
}

bool LinkedList::insert(Object* e, int p){
	if(p>size || p<0)
		return false;
	Node* neo = new Node(e);
	if(!neo)
		return false;
	if(size==0)
		head = neo;
	else if(p==0){
		neo->next = head;
		head = neo;
	}else{
		Node* tmp = head;
		for(int i = 0; i<(p-1); i++)
			tmp = tmp->next;
		neo->next = tmp->next;
		tmp->next = neo;
	}
	size++;
	return true;
}
int LinkedList::indexOf(Object* e)const{
	int pos = -1;
	Node* tmp = head;
	for(int i = 0;i<size; i++){
		if(tmp->data->equals(e)){
			pos = i;
			break;
		}
		tmp = tmp->next;
	}
	return pos;
}
Object* LinkedList::get(unsigned pos)const{
	if(pos<0 || pos>=size)
		return NULL;
	Node* tmp = head;
	for(int i = 0; i<pos; i++)
		tmp = tmp->next;
	return tmp->data;
}
Object* LinkedList::remove(unsigned pos){
	if (pos<0 || pos>=size || !head)
		return NULL;
	Object* data;
	if(pos == 0){
		Node* tmp = head;
		data = tmp->data;
		tmp->data = NULL;
		head = tmp->next;
		tmp->next = NULL;
		delete tmp;
		size--;
		return data;
	}else{
		Node* tmp = head;
		for(int i =0; i<(pos-1); i++)
			tmp = tmp->next;
		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		data = tmp2->data;
		tmp2->data = NULL;
		tmp2->next = NULL;
		delete tmp2;
		size--;
		return data;
		tmp2->next = NULL;
	}
}
/*int FSArrayList::prev(int pos) const{
}
int FSArrayList::next(int pos) const{
}*/
void LinkedList::reset(){
	delete head;
	size = 0;
}
Object* LinkedList::first()const {
	if(isEmpty())
		return NULL;	
	return head->data;
}
Object* LinkedList::last()const{
	if(isEmpty())
		return NULL;
	Node* tmp = head;
	for(int i = 0; i<(size-1); i++)
		tmp = tmp->next;	
	return tmp->data;
}
void LinkedList::print()const {
	Node* tmp = head;
	for(int i = 0; i<size; i++){
		cout << "Posicion "<<i;
		tmp->data->print();
		tmp = tmp->next;
	}
}
bool LinkedList::isEmpty()const{
	if(size == 0)
		return true;
	return false;
}
bool LinkedList::isFull()const{
	return false;
}
int LinkedList::getCapacity()const{
	return -1;
}
