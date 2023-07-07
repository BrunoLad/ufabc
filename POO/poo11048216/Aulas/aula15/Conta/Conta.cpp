#ifndef CONTA_H
#include "Conta.h"
#define CONTA_H
#endif

Conta::Conta()
{   }

Conta::Conta(std::string cpf, std::string nome)
{
    this->setNumero(Conta::geraNumero(10));
    this->setCpf(cpf);
    this->setTitular(nome);
    this->setSaldo(0);
    this->setBloqueada(false);
}

void Conta::setNumero(std::string num)
{
    this->numero = num;
}

void Conta::setTitular(std::string t)
{
    this->titular = t;
}

void Conta::setCpf(std::string cpf)
{
    this->cpf = cpf;
}

void Conta::setBloqueada(bool b)
{
    this->bloqueada = b;
}

void Conta::setSaldo(float s)
{
    this->saldo = s;
}

std::string Conta::getNumero()
{
    return this->numero;
}

std::string Conta::getTitular()
{
    return this->titular;
}

std::string Conta::getCpf()
{
    return this->cpf;
}

bool Conta::isBloqueada()
{
    return this->bloqueada;
}

float Conta::getSaldo()
{
    return this->saldo;
}

bool Conta::saque(float valor)
{
    if(this->getSaldo() >= valor && !this->isBloqueada())
    {
        this->setSaldo(this->getSaldo()-valor);
        return true;
    }
    return false;
}

bool Conta::deposito(float valor)
{
    if(!this->isBloqueada())
    {
        this->setSaldo(this->getSaldo()+valor);
        return true;
    }
    return false;
}

void Conta::extrato()
{
    std::cout << "============== EXTRATO ============== " << std::endl;
    std::cout << "NUMERO ..: " << this->getNumero() << std::endl;
    std::cout << "CPF .....: " << this->getCpf() << std::endl;
    std::cout << "TITULAR .: " << this->getTitular() << std::endl;
    std::cout << "SALDO ...: " << this->getSaldo() << std::endl;
    std::cout << "===================================== " << std::endl;
}

std::string Conta::geraNumero(int n)
{
    std::string num;
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        num += (rand()%10)+'0';
    }
    return num;
}