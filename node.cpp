#include "object.h"
#include "node.h"
#include <iostream>
Node::Node(Object* data, Node* next):data(data), next(next){}
Node::~Node(){
	if (data)
		delete data;
}
