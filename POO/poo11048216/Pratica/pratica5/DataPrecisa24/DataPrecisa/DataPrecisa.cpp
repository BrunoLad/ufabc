#include <iostream>
#include "DataPrecisa.h"

DataPrecisa::DataPrecisa(){
    
}

DataPrecisa::DataPrecisa(int a, int m, int d, int h, int min, int s){
    this->setAno(a);
    this->setMes(m);
    this->setDia(d);
    this->setHora(h);
    this->setMinuto(min);
    this->setSegundo(s);
}

DataPrecisa::DataPrecisa(Data dt) : Data(dt.getAno(), dt.getMes(), dt.getDia()){
    this->setHora(0);
    this->setMes(0);
    this->setDia(0);
}

DataPrecisa::DataPrecisa(Data dt, Relogio re) : 
                Data(dt.getAno(), dt.getMes(), dt.getDia()),
                Relogio(re.getHora(), re.getMinuto(), re.getSegundo())
{
    
}

DataPrecisa DataPrecisa::operator ++(){
    int href = this->getHora();
    this->Relogio::operator ++();
    
    if(href==23 && this->getHora()==0){
        this->Data::operator ++();
    }
    
    return *this;
}

DataPrecisa DataPrecisa::operator ++(int){
    DataPrecisa dtp(this->getAno(), this->getMes(), this->getDia(), this->getHora(), this->getMinuto(), this->getSegundo());
    
    ++(*this);
    
    return dtp;
}

void DataPrecisa::imprime() const{
    this->Data::imprime();
    this->Relogio::imprime();
    std::cout << std::endl;
}