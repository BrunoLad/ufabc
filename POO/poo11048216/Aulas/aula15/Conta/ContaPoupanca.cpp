#ifndef CONTAPOUPANCA_H
#include "ContaPoupanca.h"
#define CONTAPOUPANCA_H
#endif

ContaPoupanca::ContaPoupanca(std::string cpf, std::string nome, int d, int m, int a, float tx):Conta(cpf, nome)
{
    this->setAniversario(Data(d, m, a));
    this->setTxRef(tx);
}
ContaPoupanca::ContaPoupanca(std::string cpf, std::string nome , Data dt, float tx):Conta(cpf, nome)
{
    this->setAniversario(dt);
    this->setTxRef(tx);
}

void ContaPoupanca::setAniversario(Data dt)
{
    this->aniversario = dt;
}

void ContaPoupanca::setTxRef(float tx)
{
    this->txRef = tx;
}

Data ContaPoupanca::getAniversario()
{
    return this->aniversario;
}

float ContaPoupanca::getTxRef()
{
    return this->txRef;
}

void ContaPoupanca::correcao()
{
    if(!this->isBloqueada())
    {
        this->setSaldo(this->getSaldo() * (1.02f));
    }
}

void ContaPoupanca::extrato()
{
    Conta::extrato();
    std::cout << "ANIVERSARIO : " << this->getAniversario().getDia() << std::endl;
    std::cout << "===================================== " << std::endl;
}