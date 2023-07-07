FilaD.exe: Main.o ./Fila/Fila.o ./Item/Item.o
	g++ -o FilaD.exe Main.o ./Fila/Fila.o ./Item/Item.o
	
Fila.o: Fila.cpp
	g++ -c ./Fila/Fila.cpp
	
Main.o: Main.cpp
	g++ -c Main.cpp

Item.o: Item.cpp
	g++ -c ./Item/Item.cpp
	
clean:
	rm FilaD.exe Main.o ./Fila/Fila.o \
		./Item/Item.o