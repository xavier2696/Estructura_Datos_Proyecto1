#include "integer.h"
#include "object.h"
#include <iostream>
using namespace std;
// Constructor por Defecto / Especial de la Clase
// Tambi�n se puede considerar constructor de conversi�n
Integer::Integer(int aValue){
    value = aValue;
}
// Destructor de la Clase
Integer::~Integer(){
}
// Redefinici�n del m�todo Object::print para tener una impresi�n
// personalizada
void Integer::print()const{
    cout << "Integer = " << value << endl;
}
// Redefinici�n del m�todo Object::equals para poder comparar dos Integers
bool Integer::equals(Object* other)const{
    // Se revisa que el par�mentro no sea NULL
    if (other == NULL)
        return false;
    // Se verifica que el par�metro sea de tipo Integer
    if (dynamic_cast<Integer*>(other) == NULL) // No son del mismo tipo
        return false; // Retornar false en el caso de que sea de otro tipo
    // Se convierte el par�metro a Integer para tener acceso a value
    Integer* tempInteger = dynamic_cast<Integer*>(other);
    // Se comparan los valores para verificar igualdad
    return tempInteger->getValue() == value;
}
// M�todo Mutador de Integer (Value)
void Integer::setValue(int aValue){
    value = aValue;
}
// M�todo Accesor de Integer (Value)
int Integer::getValue()const{
    return value;
}  

