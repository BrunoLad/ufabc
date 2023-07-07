#include <iostream>
#include "Data.h"

Data::Data(){
    
}

Data::Data(int a, int m, int d){
    this->setAno(a);
    this->setMes(m);
    this->setDia(d);
}

void Data::setAno(int a){
    this->ano = a;
}

int Data::getAno() const{
    return this->ano;
}

void Data::setMes(int m){
    this->mes = m;
}

int Data::getMes() const{
    return this->mes;
}

void Data::setDia(int d){
    this->dia = d;
}

int Data::getDia() const{
    return this->dia;
}

Data Data::operator ++(){
    this->setDia(this->getDia()+1);
    
    int mes = this->getMes();
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        if(this->getDia()==32){
            this->setDia(1);
            this->setMes(this->getMes()+1);
            if(mes==12){
                this->setMes(1);
                this->setAno(this->getAno()+1);
            }
        }
    }else{
        if(mes==4 || mes==6 || mes==9 || mes==11){
            if(this->getDia()==31){
                this->setDia(1);
                this->setMes(this->getMes()+1);
            }
        }else{
            bool bs = this->isBissexto(this->getAno());
            if(bs){
                if(this->getDia()==30){
                    this->setDia(1);
                    this->setMes(3);
                }
            }else{
                if(this->getDia()==29){
                    this->setDia(1);
                    this->setMes(3);
                }
            }
        }
    }
    
    return *this;
}

Data Data::operator ++(int){
    Data d(this->getAno(), this->getMes(), this->getDia());
    
    ++(*this);
    
    return d;
}

void Data::imprime() const{
    std::cout << this->getDia() << "/" << this->getMes() << "/" << this->getAno() << " ";
}

bool Data::isBissexto(int a){
    if(a%4==0){
        return true;
    }else{
        return false;
    }
}