#include <iostream>

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
            int getDia() const;
            int getMes() const;
            int getAno() const;
            void printData() const;
            void printData(std::string) const;
            void printData(std::string, char) const;
};

Data::Data()
{
    int x;
    std::cout << "Informe o dia: ";
    std::cin >> x;
    this->setDia(x);
    std::cout << "Informe o mes: ";
    std::cin >> x;
    this->setMes(x);
    std::cout << "Informe o ano: ";
    std::cin >> x;
    this->setAno(x);
}

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

int Data::getDia() const
{
    return this->dia;
}

int Data::getMes() const
{
    return this->mes;
}

int Data::getAno() const
{
    return this->ano;
}

void Data::printData() const
{
    this->printData("DDMMAA", '/');
}

void Data::printData(std::string formato) const
{
    this->printData(formato, '/');
}

void Data::printData(std::string formato, char separador) const
{
    if(formato.substr(0,2).compare("AA") == 0 && formato.substr(2,2).compare("MM") == 0 && formato.substr(4).compare("DD") == 0)
    {
        std::cout << this->getAno() << separador << this->getMes() << separador << this->getDia() << std::endl;
    }
    else if(formato.substr(0,2).compare("AA") == 0 && formato.substr(2,2).compare("DD") == 0 && formato.substr(4).compare("MM") == 0)
    {
        std::cout << this->getAno() << separador << this->getDia() << separador << this->getMes() << std::endl;
    }
    else
    {
        std::cout << this->getDia() << separador << this->getMes() << separador << this->getAno() << std::endl;
    }
}

int main()
{
    const Data natal(25, 12, 2017);
    natal.printData("AAMMDD", '.');
    
    return 0;
}