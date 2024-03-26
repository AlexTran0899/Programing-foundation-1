output: main.o Animal.o AnimalDB.o
	g++ main.o Animal.o AnimalDB.o -o output.exe

main.o: main.cpp
	g++ -c main.cpp

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp

AnimalDB.o: AnimalDB.cpp AnimalDB.h
	g++ -c AnimalDB.cpp

clean:
	rm *.o output.exe
