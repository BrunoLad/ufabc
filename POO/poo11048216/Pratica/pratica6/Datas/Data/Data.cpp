#include "Data.h"

Data::Data(){
    
}

Data::Data(int d, int m, int a) throw(DataInvalidaException){
    if(m<1 || m>12){
        throw DataInvalidaException();
    }else{
        if(d>31 || d<1){
            throw DataInvalidaException();
        }else{
            if((m==4 || m==6 || m==9 || m==11) && d>30){
                throw DataInvalidaException();
            }else{
                if(m==2 && isBissexto() && d>29){
                    throw DataInvalidaException();
                }else{
                    if(m==2 && !isBissexto() && d>28){
                        throw DataInvalidaException();
                    }else{
                        this->setDia(d);
                        this->setMes(m);
                        this->setAno(a);
                    }
                }
            }
        }
    }
}

void Data::setDia(int d){
    this->dia = d;
}

int Data::getDia() const{
    return this->dia;
}

void Data::setMes(int m){
    this->mes = m;
}

int Data::getMes() const{
    return this->mes;
}

void Data::setAno(int a){
    this->ano = a;
}

int Data::getAno() const{
    return this->ano;
}

bool Data::isBissexto(){
    if(!this->getAno()%4){
        return true;
    }else{
        return false;
    }
}