#ifndef CONTA_H
#include "Conta.h"
#define CONTA_H
#endif

class ContaInvestimento : public Conta
{
    private:
            float taxaRendimento;
            float taxaAdministracao;
    public:
            ContaInvestimento();
            ContaInvestimento(std::string, std::string, float, float);
            void setTaxaRendimento(float);
            void setTaxaAdministracao(float);
            float getTaxaRendimento();
            float getTaxaAdministracao();
            void correcao();
            void extrato();
};