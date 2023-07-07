#include <iostream>

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
};

class Bola
{
    private:
            Ponto posicao;
            float diametro, peso;
    public:
            static float gravidade;
            Bola();
            Bola(float, float);
            Bola(Ponto, float, float);
            void setPosicao(Ponto);
            void setDiametro(float);
            void setPeso(float);
            Ponto getPosicao();
            float getDiametro();
            float getPeso();
            float getGravidade();
};

float Bola::gravidade = 10;

Bola::Bola()
{   }

Bola::Bola(float d, float p)
{
    this->setDiametro(d);
    this->setPeso(p);
}

Bola::Bola(Ponto pt, float d, float p)
{
    this->setPosicao(pt);
    this->setDiametro(d);
    this->setPeso(p);
}

void Bola::setPosicao(Ponto p)
{
    this->posicao = p;
}

void Bola::setDiametro(float d)
{
    this->diametro = d;
}

void Bola::setPeso(float p)
{
    this->peso = p;
}

Ponto Bola::getPosicao()
{
    return this->posicao;
}

float Bola::getDiametro()
{
    return this->diametro;
}

float Bola::getPeso()
{
    return this->peso;
}

float Bola::getGravidade()
{
    return this->gravidade;
}

Ponto::Ponto()
{   }

Ponto::Ponto(float x, float y)
{
    this->setX(x);
    this->setY(y);
}

void Ponto::setX(float x)
{
    this->x = x;
}

void Ponto::setY(float y)
{
    this->y = y;
}

float Ponto::getX()
{
    return this->x;
}

float Ponto::getY()
{
    return this->y;
}

int main()
{
    Bola jabulani(Ponto(78.4, 98.4), 50.5, 5.3);
    Bola brazuca(Ponto(85.5, 95.4), 51.9, 4.9);
    
    std::cout << "Jabulani" << std::endl;
    std::cout << "jabulani.gravidade: " << jabulani.getGravidade() << std::endl;
    
    std::cout << "Brazuca" << std::endl;
    std::cout << "brazuca.gravidade: " << brazuca.getGravidade() << std::endl;
    
    jabulani.gravidade = 15;
    
    std::cout << "Jabulani" << std::endl;
    std::cout << "jabulani.gravidade: " << jabulani.getGravidade() << std::endl;
    
    std::cout << "Brazuca" << std::endl;
    std::cout << "brazuca.gravidade: " << brazuca.getGravidade() << std::endl;
    
    brazuca.gravidade = 20;
    
    std::cout << "Jabulani" << std::endl;
    std::cout << "jabulani.gravidade: " << jabulani.getGravidade() << std::endl;
    
    std::cout << "Brazuca" << std::endl;
    std::cout << "brazuca.gravidade: " << brazuca.getGravidade() << std::endl;
    return 0;
}