#pragma once
#include "tdalist.h"
#include <cstddef>

class LinkedList:public TDAList{
	class Node{
		public:
			Object* data;
			Node* next;
			Node(Object*, Node* =NULL);			
			~Node();
	};
	Node* head;
  public:
	LinkedList();
	virtual ~LinkedList();
	virtual bool insert(Object*, int);
    	virtual int indexOf(Object*)const;
    	virtual Object* get(unsigned)const;
    	virtual Object* remove(unsigned);
    	//virtual int prev(int) const;
    	//virtual int next(int) const ;
    	virtual void reset() ;
    	virtual Object* first()const ;
    	virtual Object* last()const ;
    	virtual void print()const ;
    	virtual bool isEmpty()const;
    	virtual bool isFull()const ;
    	virtual int getCapacity()const;
    	int getSize()const;
	
};
