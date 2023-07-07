#include <iostream>
#include "DataPrecisa.h"

DataPrecisa::DataPrecisa(){
    
}

DataPrecisa::DataPrecisa(int a, int m, int d, int h, int min, int s, bool am){
    this->setAno(a);
    this->setMes(m);
    this->setDia(d);
    this->setHora(h);
    this->setMinuto(min);
    this->setSegundo(s);
    this->setAM(am);
}

DataPrecisa::DataPrecisa(Data dt) : Data(dt.getAno(), dt.getMes(), dt.getDia()){
    this->setHora(0);
    this->setMes(0);
    this->setDia(0);
}

DataPrecisa::DataPrecisa(Data dt, Watch wa) : 
                Data(dt.getAno(), dt.getMes(), dt.getDia()),
                Watch(wa.getHora(), wa.getMinuto(), wa.getSegundo(), wa.isAM())
{
    
}

DataPrecisa DataPrecisa::operator ++(){
    int href = this->getHora();
    this->Watch::operator ++();
    
    if(href==11 && this->getHora()==12 && this->isAM()){
        this->Data::operator ++();
    }
    
    return *this;
}

DataPrecisa DataPrecisa::operator ++(int){
    DataPrecisa dtp(this->getAno(), this->getMes(), this->getDia(), this->getHora(), this->getMinuto(), this->getSegundo(), this->isAM());
    
    ++(*this);
    
    return dtp;
}

void DataPrecisa::imprime() const{
    this->Data::imprime();
    this->Watch::imprime();
    std::cout << std::endl;
}