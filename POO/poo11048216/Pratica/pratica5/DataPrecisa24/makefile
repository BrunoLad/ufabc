all: Calendario.exe

Calendario.exe: Main.o Relogio/Relogio.o Data/Data.o DataPrecisa/DataPrecisa.o
	g++ -o Calendario.exe Main.o Relogio/Relogio.o Data/Data.o DataPrecisa/DataPrecisa.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Relogio.o: Relogio.cpp
	g++ -c Relogio/Relogio.cpp
	
Data.o: Data.cpp
	g++ -c Data/Data.cpp
	
DataPrecisa.o: DataPrecisa.cpp
	g++ -c DataPrecisa/DataPrecisa.cpp
	
clean:
	rm Calendario.exe Main.o Relogio/Relogio.o \
		Data/Data.o DataPrecisa/DataPrecisa.o