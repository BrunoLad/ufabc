all: Watch.exe

Watch.exe: Main.o Watch/Watch.o
	g++ -o Watch.exe Main.o Watch/Watch.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Watch.o: Watch.cpp
	g++ -c Watch/Watch.cpp
	
clean:
	rm Watch.exe Main.o Watch/Watch.o