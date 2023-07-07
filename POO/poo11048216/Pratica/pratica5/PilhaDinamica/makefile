all: PilhaDinamica.exe

PilhaDinamica.exe: Main.o ./Item/Item.o ./Pilha/Pilha.o
	g++ -o PilhaDinamica.exe Main.o ./Item/Item.o ./Pilha/Pilha.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Item.o: Item.cpp
	g++ -c ./Item/Item.cpp
	
Pilha.o: Pilha.cpp
	g++ -c ./Pilha/Pilha.cpp
	
clean:
	rm PilhaDinamica.exe Main.o \
		./Item/Item.o ./Pilha/Pilha.o