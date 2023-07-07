#include <iostream>
#include "Watch.h"

Watch::Watch(){
    this->setHora(12);
    this->setMinuto(0);
    this->setSegundo(0);
    this->setAM(true);
}

Watch::Watch(int h, int m, int seg, std::string s){
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(seg);
    if(s=="AM"){
        this->setAM(true);
    }else{
        this->setAM(false);
    }
}

void Watch::setAM(bool h){
    this->AM = h;
}

bool Watch::isAM() const{
    return this->AM;
}

void Watch::setHora(int h){
    this->hora = h;
}

int Watch::getHora() const{
    return this->hora;
}

void Watch::setMinuto(int m){
    this->minuto = m;
}

int Watch::getMinuto() const{
    return this->minuto;
}

void Watch::setSegundo(int s){
    this->segundo = s;
}

int Watch::getSegundo() const{
    return this->segundo;
}

Watch Watch::operator ++(){
    this->setSegundo(this->getSegundo()+1);
    
    if(this->getSegundo()>=60){
        this->setSegundo(0);
        this->incrementaMinuto();
    }
    
    return *this;
}

Watch Watch::operator ++(int){
    Watch r = *this;
    
    ++(*this);
    
    return r;
}

void Watch::incrementaMinuto(){
    this->setMinuto(this->getMinuto()+1);
    
    if(this->getMinuto()>=60){
        this->setMinuto(0);
        this->incrementaHora();
    }
}

void Watch::incrementaHora(){
    this->setHora(this->getHora()+1);
    
    if(this->getHora()==13){
        this->setHora(1);
    }else{
        if(this->getHora()==12){
            if(this->isAM()){
                this->setAM(false);
            }else{
                this->setAM(true);
            }
        }
    }
}

void Watch::imprime() const{
    if(this->isAM()){
        std::cout << this->getHora() << ":" << this->getMinuto() << ":" << this->getSegundo() << " AM" << std::endl;
    }else{
        std::cout << this->getHora() << ":" << this->getMinuto() << ":" << this->getSegundo() << " PM" << std::endl;
    }
}