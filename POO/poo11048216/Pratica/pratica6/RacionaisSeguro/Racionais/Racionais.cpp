#include <iostream>
#include <cmath>
#include "Racionais.h"

Racionais::Racionais(){
    
}

Racionais::Racionais(int n, int d) throw(DenominadorZeroException){
    if(d==0){
        throw DenominadorZeroException();
    }else{
        this->setNumerador(n);
        this->setDenominador(d);
    }
}

void Racionais::setNumerador(int n){
    this->numerador = n;
}

int Racionais::getNumerador(){
    return this->numerador;
}

void Racionais::setDenominador(int d){
    this->denominador = d;
}

int Racionais::getDenominador(){
    return this->denominador;
}

void Racionais::oposto(){
    this->setNumerador(this->getNumerador()*(-1));
}

void Racionais::inverso(){
    int aux = this->getDenominador();
    this->setDenominador(this->getNumerador());
    this->setNumerador(aux);
}

void Racionais::simplifica(){
    int a = std::abs(this->getDenominador());
    int b = std::abs(this->getNumerador());
    int r;
    
    if(a>b){
        while(b!=0){
            r= a % b;
            a = b;
            b = r;
        }
        this->setNumerador(this->getNumerador()/a);
        this->setDenominador(this->getDenominador()/a);
    }else{
        if(b>a){
            while(a!=0){
                r= b % a;
                b = a;
                a = r;
            }
            this->setNumerador(this->getNumerador()/b);
            this->setDenominador(this->getDenominador()/b);
        }else{
            this->setDenominador(1);
            this->setNumerador(1);
        }
    }
}

Racionais Racionais::operator + (Racionais aux){
    Racionais ref;
    int p = this->getDenominador() * aux.getDenominador();
    
    ref.setDenominador(p);
    ref.setNumerador((aux.getDenominador()*this->getNumerador())+(this->getDenominador()*aux.getNumerador()));
    ref.simplifica();
    
    return ref;
}

Racionais Racionais::operator * (Racionais aux){
    Racionais *ref;
    
    int den = aux.getDenominador() * this->getDenominador();
    int num = aux.getNumerador() * this->getNumerador();
    
    ref = new Racionais(num,den);
    ref->simplifica();
    
    return (*ref);
}

void Racionais::imprime(){
    std::cout << this->getNumerador() << " " << this->getDenominador() << std::endl;
}