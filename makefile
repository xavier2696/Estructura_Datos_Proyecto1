exe: main.o FSArrayList.o DoubleFSCursor.o LinkedList.o integer.o object.o tdalist.o 
	g++ main.o FSArrayList.o DoubleFSCursor.o LinkedList.o integer.o object.o tdalist.o -o exe
main.o: main.cpp
	g++ main.cpp -c
FSArrayList.o: FSArrayList.cpp FSArrayList.h tdalist.h object.h
	g++ FSArrayList.cpp -c
DoubleFSCursor.o: DoubleFSCursor.cpp DoubleFSCursor.h tdalist.h object.h
	g++ DoubleFSCursor.cpp -c
LinkedList.o: LinkedList.cpp LinkedList.h tdalist.h object.h
	g++ LinkedList.cpp -c
tdalist.o: tdalist.cpp tdalist.h object.h
	g++ tdalist.cpp -c
integer.o: integer.cpp integer.h object.h
	g++ integer.cpp -c
object.o: object.cpp object.h
	g++ object.cpp -c

