#ifndef DATA_H
#include "Data.h"
#define DATA_H
#endif
#ifndef CONTA_H
#include "Conta.h"
#define CONTA_H
#endif

/*
#ifndef __CONTA_H__
    #include "Conta.h"
#endif
*/

class ContaPoupanca: public Conta
{
    private:
            Data aniversario;
            float txRef;
    public:
            ContaPoupanca(std::string, std::string, int, int, int, float);
            ContaPoupanca(std::string, std::string, Data, float);
            void setAniversario(Data);
            void setTxRef(float);
            Data getAniversario();
            float getTxRef();
            void correcao();
            void extrato();
};