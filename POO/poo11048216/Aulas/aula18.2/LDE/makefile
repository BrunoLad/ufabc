all:	Lista.exe

Lista.exe:	Item.o	Lista.o	Main.o	ListaExceptions.o
	g++	-o	Lista.exe	Item.o	Lista.o	Main.o	ListaExceptions.o
	
ListaExceptions.o:	ListaExceptions.cpp
	g++	-c	ListaExceptions.cpp

Item.o:	Item.cpp
	g++	-c	Item.cpp
	
Lista.o:	Lista.cpp
	g++	-c	Lista.cpp
	
Main.o:	Main.cpp
	g++	-c	Main.cpp