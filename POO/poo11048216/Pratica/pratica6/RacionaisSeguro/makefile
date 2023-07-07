all: OperacaoRacionais.exe

OperacaoRacionais.exe: Racionais/Racionais.o Main.o RacionaisException/RacionaisException.o
	g++ -o OperacaoRacionais.exe Main.o Racionais/Racionais.o RacionaisException/RacionaisException.o
	
Main.o: Main.cpp
	g++ -c Main.cpp
	
Racionais.o: Racionais.cpp
	g++ -c Racionais/Racionais.cpp
	
RacionaisException.o: RacionaisException.cpp
	g++ -c RacionaisException/RacionaisException.cpp
	
clean:
	rm OperacaoRacionais.exe Racionais/Racionais.o \
		RacionaisException/RacionaisException.o Main.o