#include "object.h"
#include "tdalist.h"
#include "DoubleFSCursor.h"
#include <iostream>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::cout;

DoubleFSCursor::DoubleFSCursor(int tam):capacity(tam){
	cursor = new CursorRow*[tam];
	head = -1;
}

DoubleFSCursor::~DoubleFSCursor(){
	for(int i = 0; i<size; i++){
		delete cursor[i]->data;
		delete cursor[i];
	}
	delete[] cursor;
}

bool DoubleFSCursor::insert(Object* e, int p){
	if(p>size || p<0){
		return false;
		
	}
	if(isFull()){
		return false;
	}
	CursorRow* neo = static_cast<CursorRow*>(malloc(sizeof(CursorRow)));
	neo->data=e;
	neo->prev = -1;
	neo->next = -1;
	int disponible = -1;
	if(size==0){
		cursor[0] = neo;
		head = 0;
		size++;
		return true;
	}
	for(int i =0; i<capacity; i++){
		if(cursor[i] == NULL){
			disponible = i;
			break;
		}
	}
	if(disponible == -1){
		return false;
		
	}
	if(p==0 && size!=0){
		neo->next = head;
		cursor[head]->prev = disponible;
		cursor[disponible] = neo;
		head = disponible;
	}else if (size!=0){
		int tmp = head;
		for(int i = 0; i<(p-1); i++){
			tmp = cursor[tmp]->next;
		}
		neo->prev = tmp;
		neo->next = cursor[tmp]->next;
		cursor[tmp]->next = disponible;
		cursor[disponible] = neo;
	}
	size ++;
	return true;
}
int DoubleFSCursor::indexOf(Object* e)const{
	int pos = -1;
	int tmp = head;
	for(int i = 0;i<size; i++){
		if(cursor[tmp]->data->equals(e)){
			pos = tmp;
			break;
		}
		tmp = cursor[tmp]->next;
	}
	return pos;
}
Object* DoubleFSCursor::get(unsigned pos)const{
	if(pos<0 || pos>=size)
		return NULL;
	int tmp = head;
	Object* data = NULL;
	for(int i = 0; i<size; i++){
		if(tmp == pos){
			data = cursor[tmp]->data;
			break;
		}
		tmp = cursor[tmp]->next;
	}
	return data;
}
Object* DoubleFSCursor::remove(unsigned pos){
	if (pos<0 || pos>=size)
		return NULL;
	Object* objeto;
	if(pos == 0){
		int tmp = head;
		objeto = cursor[tmp]->data;
		head = cursor[tmp]->next;
		cursor[tmp]->data = NULL;
		delete cursor[tmp];
		cursor[tmp] = NULL;
		
	}else if(pos == (size-1)){
		int tmp = head;
		for(int i = 0; i<(pos-1);i++){
			tmp = cursor[tmp]->next;
		}
		int tmp2 = cursor[tmp]->next;
		cursor[tmp]->next = -1;
		objeto = cursor[tmp2]->data;
		cursor[tmp2]->data = NULL;
		delete cursor[tmp2];
	}else{
		int tmp = head;
		for(int i = 0; i<(pos-1);i++){
			tmp = cursor[tmp]->next;
		}
		int tmp2 = cursor[tmp]->next;
		cursor[tmp]->next = cursor[tmp2]->next;
		objeto = cursor[tmp2]->data;
		if(cursor[tmp2]->next != -1)
			cursor[cursor[tmp2]->next]->prev = tmp;
		cursor[tmp2]->data = NULL;
		delete cursor[tmp2];
	}
	size--;
	return objeto;
}
/*int FSArrayList::prev(int pos) const{
}
int FSArrayList::next(int pos) const{
}*/
void DoubleFSCursor::reset(){
	int tmp = head; 
	for(int i = 0; i<size; i++){
		delete cursor[tmp]->data;
		delete cursor[tmp];
		tmp = cursor[tmp]->next;
	}
	size = 0;
}
Object* DoubleFSCursor::first()const {
	if(isEmpty())
		return NULL;
	return cursor[head]->data;
}
Object* DoubleFSCursor::last()const{
	if(isEmpty())
		return NULL;
	int tmp = head;
	for(int i = 0; i<(size-1); i++)
		tmp = cursor[tmp]->next;	 
	return cursor[tmp]->data;
}
void DoubleFSCursor::print()const {
	int tmp = head; 
	for(int i = 0; i<size; i++){	
		if(tmp < 0)
			break;	
		cout << "Posicion "<<i<<" ";
		((cursor[tmp])->data)->print();		
		tmp = cursor[tmp]->next;
	}
}
bool DoubleFSCursor::isEmpty()const{
	if(size == 0)
		return true;
	return false;
}
bool DoubleFSCursor::isFull()const{
	if(size == capacity)
		return true;
	return false;
}
int DoubleFSCursor::getCapacity()const{
	return capacity;
}
