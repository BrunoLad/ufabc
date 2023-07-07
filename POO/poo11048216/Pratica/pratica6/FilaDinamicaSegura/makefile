all: FilaDinamica.exe

FilaDinamica.exe: Main.o Fila/Fila.o Item/Item.o FilaException/FilaException.o
	g++ -o FilaDinamica.exe Main.o Fila/Fila.o Item/Item.o FilaException/FilaException.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Fila.o: Fila.cpp
	g++ -c Fila/Fila.cpp
	
Item.o: Item.cpp
	g++ -c Item/Item.cpp
	
FilaException.o: FilaException.cpp
	g++ -c FilaException/FilaException.cpp
	
clean:
	rm FilaDinamica.exe FilaException/FilaException.o \
		Main.o Fila/Fila.o Item/Item.o