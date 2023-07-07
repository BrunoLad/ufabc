#include <iostream>
#include <cstdlib>

class Conta
{
    private:
            std::string numero;
            std::string titular;
            std::string cpf;
            bool bloqueada;
            float saldo;
    public:
            Conta();
            Conta(std::string, std::string);
            void setNumero(std::string);
            void setTitular(std::string);
            void setCpf(std::string);
            void setBloqueada(bool);
            void setSaldo(float);
            std::string getNumero();
            std::string getTitular();
            std::string getCpf();
            bool isBloqueada();
            float getSaldo();
            bool saque(float);
            bool deposito(float);
            virtual void extrato();
            virtual void correcao() = 0;
            static std::string geraNumero(int);
};