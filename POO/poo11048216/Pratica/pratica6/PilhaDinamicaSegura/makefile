all: PilhaDinamica.exe

PilhaDinamica.exe: Main.o PilhaExceptions/PilhaExceptions.o Pilha/Pilha.o Item/Item.o
	g++ -o PilhaDinamica.exe Main.o PilhaExceptions/PilhaExceptions.o Pilha/Pilha.o Item/Item.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
PilhaExceptions.o: PilhaExceptions.cpp
	g++ -c PilhaExceptions/PilhaExceptions.cpp
	
Pilha.o: Pilha.cpp
	g++ -c Pilha/Pilha.cpp
	
Item.o: Item.cpp
	g++ -c Item/Item.cpp
	
clean:
	rm PilhaDinamica.exe PilhaExceptions/PilhaExceptions.o \
		Pilha/Pilha.o Item/Item.o Main.o