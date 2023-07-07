#include <iostream>

class Complexo{
    private:
        int real;
        int imaginaria;
    public:
        Complexo(int,int);
        int getReal();
        void setReal(int);
        int getImaginaria();
        void setImaginaria(int);
        void soma(Complexo);
        void sub(Complexo);
        void mult(Complexo);
        void divi(Complexo);
};

Complexo::Complexo(int r, int i){
    this->setReal(r);
    this->setImaginaria(i);
}

int Complexo::getReal(){
    return this->real;
}

void Complexo::setReal(int r){
    this->real = r;
}

int Complexo::getImaginaria(){
    return this->imaginaria;
}

void Complexo::setImaginaria(int i){
    this->imaginaria = i;
}

void Complexo::soma(Complexo c){
    
}

void Complexo::sub(Complexo c){
    
}

void Complexo::mult(Complexo c){
    
}

void Complexo::divi(Complexo c){
    
}

int main(){
    int r1, r2;
    std::string im1, im2;
    char op;
    
    while(std::cin >> r1 >> im1 >> op >> r2 >> im2){
        switch(op){
            case '+':
                //fazer a soma entre os complexos
                break;
            case '-':
                //chamar o método sub
                break;
            case '*':
                //chamar o método mult
                break;
            case '/':
                //chamar o método divi
                break;
            default:
                //novamente fins estéticos
                break;
        }
    }
    
    
    
    return 0;
}