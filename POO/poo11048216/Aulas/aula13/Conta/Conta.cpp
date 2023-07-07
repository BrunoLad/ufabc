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
            void extrato();
            static std::string geraNumero(int);
};

class Data
{
    private:
            int dia, mes, ano;
    public:
            Data();
            Data(int, int, int);
            void setDia(int);
            void setMes(int);
            void setAno(int);
            int getDia();
            int getMes();
            int getAno();
};

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
            void extrato();
};

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

void ContaPoupanca::extrato()
{
    Conta::extrato();
    std::cout << "ANIVERSARIO : " << this->getAniversario().getDia() << std::endl;
    std::cout << "===================================== " << std::endl;
}

Data::Data()
{   }

Data::Data(int d, int m, int a)
{
    this->setDia(d);
    this->setMes(m);
    this->setAno(a);
}

void Data::setDia(int d)
{
    this->dia = d;
}

void Data::setMes(int m)
{
    this->mes = m;
}

void Data::setAno(int a)
{
    this->ano = a;
}

int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}
            
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

int main()
{
    ContaPoupanca cta("22698532800", "Monael", Data(20, 5, 2000), 10.0);
    cta.extrato();
    cta.deposito(999999);
    cta.extrato();
    return 0;
}