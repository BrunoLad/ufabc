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
            int getDia();
            int getMes();
            int getAno();
            void printData();
            void printData(std::string);
            void printData(std::string, char);
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

void Data::printData()
{
    this->printData("DDMMAA", '/');
}

void Data::printData(std::string formato)
{
    this->printData(formato, '/');
}

void Data::printData(std::string formato, char separador)
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
    Data dtAniversario(20,1,1995), natal;
    Data *dtInd;
    
    dtInd = new Data;
    
    dtAniversario.printData();
    natal.printData("AAMMDD");
    dtInd->printData("AADDMM", '|');
    
    return 0;
}