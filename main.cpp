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
	bool flag = true;
	while (flag){
		int menu;
		cout <<"1)Prueba Insert"<<endl
			<<"2)Prueba clear"<<endl
			<<"3)Prueba first"<<endl
			<<"4)Prueba last"<<endl
			<<"5)Prueba indexOf"<<endl
			<<"6)Prueba remove"<<endl
			<<"7)Prueba get"<<endl
			<<"8)Salir"<<endl
			<<"Ingrese su opcion: ";
		cin >> menu;
		clock_t s2,e2;
		if(menu != 8)
			cout<<setw(6)<<"I"<<setw(10)<<"FsArray"<<"\t"<<setw(10)<<"Linked"<<"\t"<<setw(10)<<"Cursor"<<endl;		
		switch(menu){
			case 1:
				for(int i = 0; i<5000; i++){
					//insert
					start = clock();
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
					cursor->reset();
				}
				break;
			case 2:
				for(int i = 0; i<5000; i++){
					//Reset
					start =clock();		
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
					cout <<setw(10)<<end-(e2-s2)-start<<endl;
				}
				break;
			case 3:
				for(int i = 0; i<5000; i++){
					//First
					fsarray->insert(new Integer(1), fsarray->getSize());
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
					cout <<setw(10)<<end-start<<endl;
				}	
				break;
			case 4:
				for(int j = 0; j<100; j++){
					fsarray->insert(new Integer(1), fsarray->getSize());
					linked->insert(new Integer(1), linked->getSize());
					cursor->insert(new Integer(1), cursor->getSize());
				}
				for(int i = 0; i<5000; i++){
					//last

					start = clock();
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
					cout <<setw(10)<<end-start<<endl;
				}
				break;
			case 5:
				for(int j = 0; j<100; j++){
					fsarray->insert(new Integer(1), fsarray->getSize());
					linked->insert(new Integer(1), linked->getSize());
					cursor->insert(new Integer(1), cursor->getSize());
				}
				fsarray->insert(new Integer(2), 50);
				linked->insert(new Integer(2), 50);
				cursor->insert(new Integer(2), 50);
				for(int i = 0; i<5000; i++){
					//indexof
					Object* integer = new Integer(2);
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
					delete integer;
				}
				break;
			case 6:
				for(int j = 0; j<4999; j++){
					fsarray->insert(new Integer(1), fsarray->getSize());
					linked->insert(new Integer(1), linked->getSize());
					cursor->insert(new Integer(1), cursor->getSize());
				}
				for(int i = 0; i<5000; i++){
					//remove


					start =clock();		
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
					cout <<setw(10)<<end-(e2-s2)-start<<endl;
				}
				break;
			case 7:
				//get
				for(int j = 0; j<5000; j++){
					fsarray->insert(new Integer(1), fsarray->getSize());
					linked->insert(new Integer(1), linked->getSize());
					cursor->insert(new Integer(1), cursor->getSize());

				}
				for(int i = 0; i<5000; i++){
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
				}
				break;
			case 8:
				flag = false;
		}
			
	}
	delete fsarray;
	delete linked;
	delete cursor;

	return 0;
}
