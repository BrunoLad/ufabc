all: PilhaEstatica.exe

PilhaEstatica.exe: Main.o Pilha/Pilha.o PilhaExceptions/PilhaExceptions.o
	g++ -o PilhaEstatica.exe Main.o Pilha/Pilha.o PilhaExceptions/PilhaExceptions.o
	
Main.o: Main.cpp
	g++ -c Main.cpp

Pilha.o: Pilha.cpp
	g++ -c Pilha/Pilha.cpp
	
PilhaExceptions.o: PilhaExceptions.cpp
	g++ -c PilhaExceptions/PilhaExceptions.cpp
	
clean:
	rm PilhaEstatica.exe Pilha/Pilha.o \
		PilhaExceptions/PilhaExceptions.o Main.o