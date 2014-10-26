#include "object.h"
#include <iostream>
using std::cout;
using std::endl;
// Constructor por Defecto de Object
Object::Object(){
}
// Destructor de Object, necesario colocarlo para "definir" que los
// destructores de esta "Familia" de clases ser�n virtuales
Object::~Object(){
}
// M�todo de Impresi�n por defecto.
void Object::print()const{
    cout << "Object@" << this << endl;
}
// M�todo de Comparaci�n por defecto, s�lo compara las Direcciones.
bool Object::equals(Object* other)const{
    return this == other;
}


