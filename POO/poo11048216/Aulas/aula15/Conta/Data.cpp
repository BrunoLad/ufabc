#ifndef DATA_H
#include "Data.h"
#define DATA_H
#endif

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