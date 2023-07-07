Agencia.exe:	Main.o	Conta.o	ContaPoupanca.o	Data.o	ContaInvestimento.o
	g++ -o	Agencia.exe	Main.o	Conta.o	ContaPoupanca.o	Data.o	ContaInvestimento.o

Main.o:	Main.cpp
	g++	-c	Main.cpp

ContaPoupanca.o:	ContaPoupanca.cpp
	g++	-c	ContaPoupanca.cpp

ContaInvestimento.o:	ContaInvestimento.cpp
	g++	-c	ContaInvestimento.cpp

Data.o:	Data.cpp
	g++	-c	Data.cpp
	
Conta.o:	Conta.cpp
	g++	-c	Conta.cpp
	
clean:
	rm Agencia.exe Conta.o ContaPoupanca.o Data.o ContaInvestimento.o \
		Main.o