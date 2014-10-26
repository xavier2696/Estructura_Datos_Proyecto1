#pragma once
#include "object.h"

class Node{
  public:
	Object* data;
	Node*   next;
	Node(Object*, Node* = NULL);
	~Node();
};


