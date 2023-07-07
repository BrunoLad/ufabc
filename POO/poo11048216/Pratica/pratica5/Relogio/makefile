all: Relogio.exe

Relogio.exe: Main.o Relogio/Relogio.o
	g++ -o Relogio.exe Main.o Relogio/Relogio.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Relogio.o: Relogio.cpp
	g++ -c Relogio/Relogio.cpp
	
clean:
	rm Relogio.exe Main.o /
		Relogio/Relogio.o