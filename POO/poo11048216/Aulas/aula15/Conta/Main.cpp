#ifndef DATA_H
#include "Data.h"
#define DATA_H
#endif
#ifndef CONTA_H
#include "Conta.h"
#define CONTA_H
#endif
#ifndef CONTAPOUPANCA_H
#include "ContaPoupanca.h"
#define CONTAPOUPANCA_H
#endif
#ifndef CONTAINVESTIMENTO_H
#include "ContaInvestimento.h"
#define CONTAINVESTIMENTO_H
#endif

int main()
{
    //Conta cta("226332158800", "Monael");
    Conta *agencia[10];
    int i;
    
    for(i=0; i<10; i++)
    {
        if(i%2==0)
        {
            agencia[i] = new ContaPoupanca("22615847800", "Fulano", 13, 07, 2017, 10);
        }
        else
        {
            agencia[i] = new ContaInvestimento("65832115892", "Filinto", 10, 2);
        }
        agencia[i]->deposito(100);
    }
    
    for(i=0; i<10; i++)
    {
        agencia[i]->correcao();
    }
    
    for(i=0; i<10; i++)
    {
        agencia[i]->extrato();
    }
    return 0;
}

/*
int main()
{
    ContaInvestimento cta("22963571800", "Monael", 10, 2);
    cta.extrato();
    cta.deposito(100);
    cta.extrato();
    cta.correcao();
    cta.extrato();
    return 0;
}
*/