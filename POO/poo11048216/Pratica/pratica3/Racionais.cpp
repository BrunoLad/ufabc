#include <iostream>
#include <cmath>

int mdc(int, int);

class Racional{
    private:
        int numerador;
        int denominador;
    public:
        Racional(int, int);
        int getNumerador();
        void setNumerador(int);
        int getDenominador();
        void setDenominador(int);
        void negativo();
        void soma(Racional);
        void produto(Racional);
        void quociente(Racional);
        void simplifica();
};

Racional::Racional(int n, int d){
    this->setNumerador(n);
    this->setDenominador(d);
}

int Racional::getNumerador(){
    return this->numerador;
}

void Racional::setNumerador(int n){
    this->numerador = n;
}

int Racional::getDenominador(){
    return this->denominador;
}

void Racional::setDenominador(int d){
    this->denominador = d;
}

void Racional::negativo(){
    this->setNumerador(this->getNumerador()*(-1));
}

void Racional::soma(Racional q){
    if(this->getDenominador()==q.getDenominador()){
        this->setNumerador(this->getNumerador()+q.getNumerador());
    }else{
        int c = (this->getDenominador()*q.getDenominador())/mdc(this->getDenominador(), q.getDenominador());
        this->setNumerador((this->getNumerador()*(c/this->getDenominador())) + (q.getNumerador()*(c/q.getDenominador())));
        this->setDenominador(c);
    }
}

void Racional::produto(Racional q){
    this->setNumerador(this->getNumerador()*q.getNumerador());
    this->setDenominador(this->getDenominador()*q.getDenominador());
}

void Racional::quociente(Racional q){
    this->setNumerador(this->getNumerador()*q.getDenominador());
    this->setDenominador(this->getDenominador()*q.getNumerador());
}

void Racional::simplifica(){
    int a = this->getNumerador(), b = this->getDenominador();
    
    int fc;
    fc = std::abs(mdc(a,b));
    this->setNumerador(a/fc);
    this->setDenominador(b/fc);
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
    int n1, d1, n2, d2;
    char op;
    
    while(std::cin >> n1 >> d1 >> op >> n2 >> d2){
        Racional r1(n1,d1), r2(n2,d2);
        //verificar qual operação será realizada
        switch(op){
            case '+':
                r1.soma(r2);
                r1.simplifica();
                std::cout << r1.getNumerador() << " " << r1.getDenominador() << std::endl;
                //realiza a soma
                break;
            case '-':
                r2.negativo();
                r1.soma(r2);
                r1.simplifica();
                std::cout << r1.getNumerador() << " " << r1.getDenominador() << std::endl;
                //realiza subtração, ou soma pelo oposto
                break;
            case '*':
                r1.produto(r2);
                r1.simplifica();
                std::cout << r1.getNumerador() << " " << r1.getDenominador() << std::endl;
                //realiza a multiplicação
                break;
            case '/':
                r1.quociente(r2);
                r1.simplifica();
                std::cout << r1.getNumerador() << " " << r1.getDenominador() << std::endl;
                //realiza a divisão, ou multiplicação pelo inverso
                break;
            default:
                //para fins estéticos. O mesmo vale para o break em seguida
                break;
        }
    }
    return 0;
}