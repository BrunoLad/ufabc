all: Datas.exe

Datas.exe: Data/Data.o Main.o DataExceptions/DataExceptions.o
	g++ -o Datas.exe Main.o Data/Data.o DataExceptions/DataExceptions.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Data.o: Data.cpp
	g++ -c Data/Data.cpp
	
DataExceptions.o: DataExceptions.cpp
	g++ -c DataExceptions/DataExceptions.cpp
	
clean:
	rm Datas.exe DataExceptions/DataExceptions.o \
		Main.o Data/Data.o