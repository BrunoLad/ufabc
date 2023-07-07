#include <iostream>
#include <cmath>

class Racional
{
    private:
            int numerador, denominador;
            
    public:
            Racional();
            Racional(int);
            Racional(int, int);
            void setNumerador(int);
            void setDenominador(int);
            int getNumerador();
            int getDenominador();
            Racional operator+(Racional);
            operator float();
            operator double();
            //void operator =(int);
};

Racional::Racional(){   }

Racional::Racional(int v)
{
    this->setNumerador(v);
    this->setDenominador(1);
}

Racional::Racional(int num, int den)
{
    this->setNumerador(num);
    this->setDenominador(den);
}

void Racional::setNumerador(int num)
{
    this->numerador = num;
}

void Racional::setDenominador(int den)
{
    this->denominador = den;
}

int Racional::getNumerador()
{
    return this->numerador;
}

int Racional::getDenominador()
{
    return this->denominador;    
}

Racional Racional::operator+(Racional q)
{
    Racional r;
    r.setNumerador(this->getNumerador()*q.getDenominador()+this->getDenominador()*q.getNumerador());
    r.setDenominador(this->getDenominador()*q.getDenominador());
    return r;
}

Racional::operator float()
{
    return this->getNumerador()/(float)this->getDenominador();
}

Racional::operator double()
{
    return this->getNumerador()/(double)this->getDenominador();
}
/*
void Racional::operator =(int v)
{
    this->setNumerador(v);
    this->setDenominador(1);
}
*/
int main()
{
    Racional a(2,3), b(5,7), r, ri;
    float f;
    double d;
    int valor = 7;
    r = a + b;
    std::cout << r.getNumerador() << "/" << r.getDenominador() << std::endl;
    f = r;
    d = r;
    std::cout << "f: " << f << std::endl;
    std::cout << "d: " << d << std::endl;
    ri = valor;
    std::cout << ri.getNumerador() << "/" << ri.getDenominador() << std::endl;
    return 0;
}