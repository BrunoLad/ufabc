#include <iostream>

class Data
{
    private:
            int dia, mes, ano;
    public:
            Data(int, int, int);
            void setDia(int);
            void setMes(int);
            void setAno(int);
            int getDia();
            int getMes();
            int getAno();
};

Data::Data(int dia, int mes, int ano)
{
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

void Data::setDia(int dia)
{
    this->dia = dia;
}

void Data::setMes(int mes)
{
    this->mes = mes;
}

void Data::setAno(int ano)
{
    this->ano = ano;
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

int main()
{
    Data dtAniversario(20, 1, 1995), independencia(7,9,1822), *republica;
    
    republica = new Data(15, 11, 1889);
    
    std::cout << "Aniversario: " << dtAniversario.getDia() << "/" << dtAniversario.getMes() << "/" << dtAniversario.getAno() << std::endl;
    std::cout << "Independencia: " << independencia.getDia() << "/" << independencia.getMes() << "/" << independencia.getAno() << std::endl;
    std::cout << "Republica: " << republica->getDia() << "/" << republica->getMes() << "/" << republica->getAno() << std::endl;
    return 0;
}