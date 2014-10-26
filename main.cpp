#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tdalist.h"
#include "FSArrayList.h"
#include "LinkedList.h"
#include "DoubleFSCursor.h"
#include "integer.h"
#include <iomanip>

using namespace std;





int main(int argc, char *argv[])
{
	clock_t start, end;
	srand(time(0));	
	TDAList* fsarray = new FSArrayList(5000);
	TDAList* linked = new LinkedList();
	TDAList* cursor = new DoubleFSCursor(5000);
	
	for(int j = 0; j<5000; j++){
			fsarray->insert(new Integer(1), fsarray->getSize());
			linked->insert(new Integer(1), linked->getSize());
			cursor->insert(new Integer(1), cursor->getSize());
		}
	
	for(int i = 0; i<5000; i++){
		clock_t s2,e2;
		//get
		start = clock();
		for(int j= 0; j<=i; j++){
			fsarray->get(rand()%(fsarray->getSize()));
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			linked->get(rand()%(linked->getSize()));
		}
		end = clock();
		cout <<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			cursor->get(rand()%(cursor->getSize()));
		}
		end = clock();
		cout <<setw(10)<<end-start<<endl;
		
		//remove
		
		
		/*start =clock();		
		for(int j = 0; j<=i; j++){
			s2 = clock();
			fsarray->insert(new Integer(1), fsarray->getSize());
			e2 = clock();	
			fsarray->remove(rand()%(fsarray->getSize()));
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-(e2-s2)-start<<"\t";
		
		start = clock();
		for(int j = 0; j<=i; j++){
			s2 = clock();
			linked->insert(new Integer(1), linked->getSize());
			e2 = clock();
			linked->remove(rand()%(linked->getSize()));
		}
		end = clock();
		cout <<setw(10)<<end-(e2-s2)-start<<"\t";
		
		start = clock();
		for(int j = 0; j<=i; j++){
			s2 = clock(); 
			cursor->insert(new Integer(1), cursor->getSize());
			e2 = clock();
			cursor->remove(rand()%(cursor->getSize()));
		}
		end = clock();
		cout <<setw(10)<<end-(e2-s2)-start<<endl;*/
	
		//indexof
		/*Object* integer = new Integer(2);
		start = clock();
		for(int j= 0; j<=i; j++){
			fsarray->indexOf(integer);
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			linked->indexOf(integer);
		}
		end = clock();
		cout <<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			cursor->indexOf(integer);
		}
		end = clock();
		cout <<setw(10)<<end-start<<endl;
		delete integer;*/
		
		//last
		
		/*start = clock();
		for(int j= 0; j<=i; j++){
			fsarray->last();
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			linked->last();
		}
		end = clock();
		cout <<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			cursor->last();
		}
		end = clock();
		cout <<setw(10)<<end-start<<endl;*/
		
		//First
		/*fsarray->insert(new Integer(1), fsarray->getSize());
		linked->insert(new Integer(1), linked->getSize());
		cursor->insert(new Integer(1), cursor->getSize());
		
		start = clock();
		for(int j= 0; j<=i; j++){
			fsarray->first();
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			linked->first();
		}
		end = clock();
		cout <<setw(10)<<end-start<<"\t";
		
		start = clock();
		for(int j= 0; j<=i; j++){
			cursor->first();
		}
		end = clock();
		cout <<setw(10)<<end-start<<endl;*/
		
		//Reset
		/*start =clock();		
		for(int j = 0; j<=i; j++){
			s2 = clock();
			fsarray->insert(new Integer(1), fsarray->getSize());
			fsarray->insert(new Integer(1), fsarray->getSize());
			fsarray->insert(new Integer(1), fsarray->getSize());
			e2 = clock();	
			fsarray->reset();
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-(e2-s2)-start<<"\t";
		
		start = clock();
		for(int j = 0; j<=i; j++){
			s2 = clock();
			linked->insert(new Integer(1), linked->getSize());
			linked->insert(new Integer(1), linked->getSize());
			linked->insert(new Integer(1), linked->getSize());
			e2 = clock();
			linked->reset();
		}
		end = clock();
		cout <<setw(10)<<end-(e2-s2)-start<<"\t";
		
		start = clock();
		for(int j = 0; j<=i; j++){
			s2 = clock(); 
			cursor->insert(new Integer(1), cursor->getSize());
			cursor->insert(new Integer(1), cursor->getSize());
			cursor->insert(new Integer(1), cursor->getSize());
			e2 = clock();
			cursor->reset();
		}
		end = clock();
		cout <<setw(10)<<end-(e2-s2)-start<<endl;*/
		
		//insert
		/*start = clock();
		for(int j = 0; j<=i; j++){
			int num = rand()%5000;			
			int pos = rand()%(fsarray->getSize()+1);
			fsarray->insert(new Integer(num),pos);
		}
		end = clock();
		cout <<setw(6)<<i<<" "<<setw(10)<<end-start<<"\t";
		fsarray->reset();

		start = clock();
		for(int j = 0; j<=i; j++){
			int num = rand()%5000;			
			int pos = rand()%(linked->getSize()+1);
			linked->insert(new Integer(num),pos);
		}
		end = clock();
		cout <<setw(10)<<end-start<<"\t";
		linked->reset();

		start = clock();
		for(int j = 0; j<=i; j++){
			int num = rand()%5000;			
			int pos = rand()%(cursor->getSize()+1);
			cursor->insert(new Integer(num),pos);
		}
		end = clock();
		cout <<setw(10)<<end-start<<endl;
		cursor->reset();*/
	}
    // En el caso de que quisieramos utilizar otra implementación
    // SÓLO se tendría que cambiar esta línea.
	/*int tamano;
	cout<<"Ingrese el tamaño de la lista: ";
	cin>>tamano;
    TDAList* lista = new LinkedList();
    Integer* intTemp;
    int val, pos;
    bool flag = true;
    while (flag)
    {
        switch(menu())
        {
           case 1:
               cout << "Valor a Insertar: " ;
               cin >> val;
               cout << "Posicion a Insertar: ";
               cin >> pos;
               if (lista->insert(new Integer(val), pos))
                  cout << "Exito en la Insercion" << endl;
               else
                  cout << "Fracaso en la Insercion" << endl;
               break;
           case 2:
               cout << "Posicion de la que quiere Borrar: ";
               cin >> pos;
               if (lista->remove(pos) != NULL)
                  cout << "Exito en el Borrado" << endl;
               else
                  cout << "Fracaso en el Borrado" << endl;
               break;
           case 3:
               lista->print();
               break;
           case 4:
               cout << "Valor del Elemento a Buscar: ";
               cin >> val;
               intTemp = new Integer(val);
               pos = lista->indexOf(intTemp);
               delete intTemp;
               cout << "El Elemento esta en la posicion = " << pos << endl;
               break;
           case 9:
               flag = false;
        }
    }
    delete lista;*/
    delete fsarray;
    delete linked;
    delete cursor;

    return 0;
}
