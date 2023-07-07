#include <iostream>

class DiaJuliano{
    private:
            int dia;
    public:
            DiaJuliano();
            DiaJuliano(int);
            void setDia(int);
            int getDia();
};

class DataGregoriana{
    private:
            int dia, mes, ano;
    public:
            DataGregoriana();
            DataGregoriana(int,int,int);
            DataGregoriana(DiaJuliano);
            void setDia(int);
            int getDia();
            void setMes(int);
            int getMes();
            void setAno(int);
            int getAno();
            operator DiaJuliano();
};

DiaJuliano::DiaJuliano(){
    
}

DiaJuliano::DiaJuliano(int dj){
    this->setDia(dj);
}

void DiaJuliano::setDia(int dj){
    this->dia = dj;
}

int DiaJuliano::getDia(){
    return this->dia;
}

DataGregoriana::DataGregoriana(){
    
}

DataGregoriana::DataGregoriana(int dg, int mg, int ag){
    this->setDia(dg);
    this->setMes(mg);
    this->setAno(ag);
}

DataGregoriana::DataGregoriana(DiaJuliano dj){
    int jd, q, z, w, x, a, b, c, d, e, f, dia, mes, ano;
    
    jd = dj.getDia();
    
    q = jd + 0.5;
    z = q;
    w = (z - 1867216.25)/36524.25;
    x = w/4;
    a = z+1+w-x;
    b = a+1524;
    c = (b-122.1)/365.25;
    d = 365.25*c;
    e = (b-d)/30.6001;
    f = 30.6001*e;
    dia = b-d-f+(q-z);
    mes = e<14?e-1:e-13;
    ano = mes<3?c-4715:c-4716;
    
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

void DataGregoriana::setDia(int d){
    this->dia = d;
}

int DataGregoriana::getDia(){
    return this->dia;
}

void DataGregoriana::setMes(int m){
    this->mes = m;
}

int DataGregoriana::getMes(){
    return this->mes;
}

void DataGregoriana::setAno(int a){
    this->ano = a;
}

int DataGregoriana::getAno(){
    return this->ano;
}

DataGregoriana::operator DiaJuliano(){
    int dia, mes, ano, a, b, c, d, e, dj;
    
    dia = this->getDia();
    mes = this->getMes();
    ano = this->getAno();
    
    if(mes < 3)
    {
        ano--;
        mes+=12;
    }
    
    a = ano/100;
    b = a/4;
    c = 2-a+b;
    d = 365.25*(ano+4716);
    e = 30.6001 * (mes+1);
    dj = d+e+dia+0.5+c-1524.5;
    
    return DiaJuliano(dj);
}

int main(){
    int dia, mes, ano;
    DiaJuliano dj;
    DataGregoriana dg;
    while(std::cin >> dia >> mes >> ano)
    {
        dg.setDia(dia);
        dg.setMes(mes);
        dg.setAno(ano);
        dj = dg;
        std::cout << dj.getDia() << std::endl;
    }
    return 0;
}