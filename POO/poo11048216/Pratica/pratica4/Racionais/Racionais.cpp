#include <iostream>
#include <cmath>

int mdc(int, int);

class Racional{
    private:
            int numerador;
            int denominador;
    public:
            Racional();
            Racional(int,int);
            void setNumerador(int);
            int getNumerador();
            void setDenominador(int);
            int getDenominador();
            void simplifica();
            Racional operator + (Racional);
            Racional operator - (Racional);
            Racional operator * (Racional);
            Racional operator / (Racional);
};

Racional::Racional(){
    
}

Racional::Racional(int n, int d){
    this->setNumerador(n);
    this->setDenominador(d);
}

void Racional::setNumerador(int n){
    this->numerador = n;
}

int Racional::getNumerador(){
    return this->numerador;
}

void Racional::setDenominador(int d){
    this->denominador = d;
}

int Racional::getDenominador(){
    return this->denominador;
}

void Racional::simplifica(){
    int a = this->getNumerador(), b = this->getDenominador();
    
    int fc;
    fc = std::abs(mdc(a,b));// mas aqui eu achei o mdc não o mmc
    this->setNumerador(a/fc);
    this->setDenominador(b/fc);
}

Racional Racional::operator + (Racional r){
    Racional res;
    
    res.setNumerador((this->getNumerador()*r.getDenominador())+(this->getDenominador()*r.getNumerador())); 
    res.setDenominador(this->getDenominador()*r.getDenominador()); 
    res.simplifica(); //dá a fração não simplificada, depois simplifica e tem o resultado da soma corretamente
    
    return res;
}

Racional Racional::operator - (Racional r){
    Racional res;
    
    res.setNumerador((this->getNumerador()*r.getDenominador())-(this->getDenominador()*r.getNumerador()));
    res.setDenominador(this->getDenominador()*r.getDenominador());
    res.simplifica();
    
    return res;
}

Racional Racional::operator * (Racional r){
    Racional res;
    
    res.setNumerador(this->getNumerador()*r.getNumerador());
    res.setDenominador(this->getDenominador()*r.getDenominador());
    res.simplifica();
    
    return res;
}

Racional Racional::operator / (Racional r){
    Racional res;
    
    res.setNumerador(this->getNumerador()*r.getDenominador());
    res.setDenominador(this->getDenominador()*r.getNumerador());
    res.simplifica();
    
    return res;
}

int mdc(int a, int b){
    int r;
    if(a>b){
        while(b!=0){
           r=a%b;
           a=b;
           b=r;
        }
        return a;
    }else{
        while(a!=0){
           r=b%a;
           b=a;
           a=r;
        }
        return b;
    }
}

int main(){
    
    int n1,d1,n2,d2;
    char op;
    
    while(std::cin >> n1 >> d1 >> op >> n2 >> d2){
        Racional r1(n1,d1), r2(n2,d2), r;
        switch(op){
            case '+':
                r = r1 + r2;
                break;
            case '-':
                r = r1 - r2;
                break;
            case '*':
                r = r1 * r2;
                break;
            case '/':
                r = r1 / r2;
                break;
            default:
                break;
        }
        std::cout << r.getNumerador() << " " << r.getDenominador() << std::endl;
    }
    
    return 0;
}