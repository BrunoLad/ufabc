all: Calendario12.exe

Calendario12.exe: Main.o Data/Data.o Watch/Watch.o DataPrecisa/DataPrecisa.o
	g++ -o Calendario12.exe Main.o Data/Data.o Watch/Watch.o DataPrecisa/DataPrecisa.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Data.o: Data.cpp
	g++ -c Data/Data.cpp
	
Watch.o: Watch.cpp
	g++ -c Watch/Watch.cpp
	
DataPrecisa.o: DataPrecisa.cpp
	g++ -c DataPrecisa/DataPrecisa.cpp
	
clean:
	rm Calendario12.exe DataPrecisa/DataPrecisa.o \
		Watch/Watch.o Data/Data.o Main.o