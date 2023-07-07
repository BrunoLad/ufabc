#ifndef CONTAINVESTIMENTO_H
#include "ContaInvestimento.h"
#define CONTAINVESTIMENTO_H
#endif

ContaInvestimento::ContaInvestimento()
{   }

ContaInvestimento::ContaInvestimento(std::string cpf, std::string nome, float txR, float txA):Conta(cpf, nome)
{
    this->setTaxaRendimento(txR);
    this->setTaxaAdministracao(txA);
}

void ContaInvestimento::setTaxaRendimento(float txR)
{
    this->taxaRendimento = txR;
}

void ContaInvestimento::setTaxaAdministracao(float txA)
{
    this->taxaAdministracao = txA;
}

float ContaInvestimento::getTaxaRendimento()
{
    return this->taxaRendimento;
}

float ContaInvestimento::getTaxaAdministracao()
{
    return this->taxaAdministracao;
}

void ContaInvestimento::correcao()
{
    if(!this->isBloqueada())
    {
        this->setSaldo(this->getSaldo() * (1.0 + (this->getTaxaRendimento()/100.0)));
    }
}

void ContaInvestimento::extrato()
{
    Conta::extrato();
    std::cout << "TAXA DE RENDIMENTO ....: " << this->getTaxaRendimento() << "\%a.m" << std::endl;
    std::cout << "TAXA DE ADMINISTRACAO .: " << this->getTaxaAdministracao() << "\%a.m" << std::endl;
    std::cout << "===================================== " << std::endl;
}