#include <iostream>
#include <cmath>

class Ponto
{
    private:
            float x, y;
    public:
            Ponto();
            Ponto(float, float);
            void setX(float);
            void setY(float);
            float getX();
            float getY();
            Ponto operator++();
            Ponto operator++(int);
};

Ponto::Ponto()
{   }

Ponto::Ponto(float x, float y)
{
    this->setX(x);
    this->setY(y);
}

void Ponto::setX(float vx)
{
    this->x = vx;
}

void Ponto::setY(float vy)
{
    this->y = vy;
}

float Ponto::getX()
{
    return this->x;
}

float Ponto::getY()
{
    return this->x;
}

Ponto Ponto::operator++()
{
    this->setX(this->getX()+1);
    this->setY(this->getY()+1);
    return *this;
}

Ponto Ponto::operator++(int)
{
    Ponto r(this->getX(), this->getY());
    this->setX(this->getX()+1);
    this->setY(this->getY()+1);
    return r;
}

int main()
{
    Ponto p1(1,1), p2(1,1), pr1, pr2;
    
    pr1 = ++p1;
    std::cout << "("<< p1.getX() << "," << p1.getY() << ")\n";
    std::cout << "("<< pr1.getX() << "," << pr1.getY() << ")\n";
    
    pr2 = p2++;
    std::cout << "("<< p2.getX() << "," << p2.getY() << ")\n";
    std::cout << "("<< pr2.getX() << "," << pr2.getY() << ")\n";
    
    return 0;
}