#include <iostream>
#include "Relogio.h"

Relogio::Relogio(){
    this->setHora(0);
    this->setMinuto(0);
    this->setSegundo(0);
}

Relogio::Relogio(int h, int m, int s){
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(s);
}

void Relogio::setHora(int h){
    this->hora = h;
}

int Relogio::getHora() const{
    return this->hora;
}

void Relogio::setMinuto(int m){
    this->minuto = m;
}

int Relogio::getMinuto() const{
    return this->minuto;
}

void Relogio::setSegundo(int s){
    this->segundo = s;
}

int Relogio::getSegundo() const{
    return this->segundo;
}

Relogio Relogio::operator ++(){
    this->setSegundo(this->getSegundo()+1);
    
    if(this->getSegundo()==60){
        this->setSegundo(0);
        this->incrementaMinuto();
    }
    
    return *this;
}

Relogio Relogio::operator ++(int){
    Relogio r = *this;
    
    ++(*this);
    
    return r;
}

void Relogio::incrementaHora(){
    this->setHora(this->getHora()+1);
    
    if(this->getHora()==24){
        this->setHora(0);
    }
}

void Relogio::incrementaMinuto(){
    this->setMinuto(this->getMinuto()+1);

    if(this->getMinuto()==60){
        this->setMinuto(0);
        this->incrementaHora();
    }
}

void Relogio::imprime() const{
    std::cout << this->getHora() << ":" << this->getMinuto() << ":" << this->getSegundo();
}