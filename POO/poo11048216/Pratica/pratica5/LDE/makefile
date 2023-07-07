all: LDE.exe

LDE.exe: Main.o ./Lista/Lista.o ./Item/Item.o
	g++ -o LDE.exe Main.o ./Lista/Lista.o ./Item/Item.o
	
Main.o: Main.cpp
	g++ -c Main.cpp

Lista.o: Lista.cpp
	g++ -c ./Lista/Lista.cpp
	
Item.o: Item.cpp
	g++ -c ./Item/Item.cpp
	
clean:
	rm LDE.exe Main.o ./Lista/Lista.o \
		./Item/Item.o