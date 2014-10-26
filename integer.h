#ifndef INTEGER_H
#define INTEGER_H

#include "object.h"

/*
* Esta clase sirve para representar un n�mero entero.
* Es necesario "envolver" el entero dentro de una clase para poder insertarlo
* en nuestros TDA's pues los mismos aceptan elementos de tipo Object.
* Es por esa raz�n que Integer es descendiente de Object, para poder ser
* utilizado en nuestros TDA's
* Para que funcionen las operaciones (m�todos) de b�squeda, es necesario
* que est� correctamente implementado el m�todo equals de esta clase.
* Si se quiere tener un m�todo de impresi�n personalizado, se deber� tambi�n
* definir el m�todo print.
*/

class Integer : public Object{
    int value;
  public:
    Integer(int=0);
    virtual ~Integer();
    virtual void print()const;
    virtual bool equals(Object*)const;
    void setValue(int);
    int getValue()const;  
};

#endif
