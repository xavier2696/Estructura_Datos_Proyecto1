#include "object.h"
#include "tdalist.h"
#include "FSArrayList.h"
#include <iostream>
#include <cstdlib>

using std::cerr;
using std::endl;
using std::cout;

FSArrayList::FSArrayList(int c):capacity (c){
	data = new Object*[capacity];
	if(!data){
		cerr<<"no hay memoria"<<endl;
		exit(1);
	}
}

FSArrayList::~FSArrayList(){
	for(int i = 0; i<size; i++)
		delete data[i];
	delete data;
}

bool FSArrayList::insert(Object* e, int p){
	if(p>size || p<0)
		return false;
	if(isFull())
		return false;
	if(p==size){
		data[p] = e;
	}else{
		for(int i = size; i>p; i--){
			data[i] = data[i-1];
		}
		data[p] = e;
	}
	size++;
	return true;
}
int FSArrayList::indexOf(Object* e)const{
	int pos = -1;
	for(int i = 0;i<size; i++){
		if(data[i]->equals(e)){
			pos = i;
			break;
		}
	}
	return pos;
}
Object* FSArrayList::get(unsigned pos)const{
	if(pos<0 || pos>=size)
		return NULL;
	return data[pos];
}
Object* FSArrayList::remove(unsigned pos){
	if (pos<0 || pos>=size)
		return NULL;
	Object* objeto = data[pos];
	//delete data[pos];
	for(int i = pos;i <(size-1); i++){
		data[i+1] = data[i];
	}
	size--;
	return objeto;
}
/*int FSArrayList::prev(int pos) const{
}
int FSArrayList::next(int pos) const{
}*/
void FSArrayList::reset(){
	for(int i = 0; i<size; i++)
		delete data[i];
	size = 0;
}
Object* FSArrayList::first()const {
	if(isEmpty())
		return NULL;
	return data[0];
}
Object* FSArrayList::last()const{
	if(isEmpty())
		return NULL;
	return data[size-1];
}
void FSArrayList::print()const {
	for(int i = 0; i<size; i++){
		cout << "Posicion "<<i;
		data[i]->print();
	}
}
bool FSArrayList::isEmpty()const{
	if(size == 0)
		return true;
	return false;
}
bool FSArrayList::isFull()const{
	if(size == capacity)
		return true;
	return false;
}
int FSArrayList::getCapacity()const{
	return capacity;
}
