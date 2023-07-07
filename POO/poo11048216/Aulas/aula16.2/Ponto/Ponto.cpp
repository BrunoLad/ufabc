#include <iostream>

class Ponto
{
    private:
            int x, y;
    public:
            Ponto()
            {   }
            
            Ponto(int x, int y)
            {
                this->setX(x);
                this->setY(y);
            }
            
            void setX(int x)
            {
                this->x = x;
            }
            
            void setY(int y)
            {
                this->y = y;
            }
            
            int getX()
            {
                return this->x;
            }
            
            int getY()
            {
                return this->y;
            }
            
            Ponto operator+(Ponto p)
            {
                Ponto pr;
                pr.setX(this->getX()+p.getX());
                pr.setY(this->getY()+p.getY());
                return pr;
            }
            
            Ponto operator+(int v)
            {
                Ponto pr;
                pr.setX(this->getX()+v);
                pr.setY(this->getY()+v);
                return pr;
            }
            
            friend Ponto operator+(int, Ponto);
};

Ponto operator+(int v, Ponto p)
{
    Ponto pr;
    pr.setX(p.getX()+v);
    pr.setY(p.getY()+v);
    return pr;
}

int main()
{
    Ponto pa(10, 2), pb(8, 5), pr;
    
    pr = pa + pb;
    std::cout << "PR: (" << pr.getX() << "," << pr.getY() << ")" << std::endl;
    
    pr = pa + 5;
    std::cout << "PR: (" << pr.getX() << "," << pr.getY() << ")" << std::endl;
    
    pr = 5 + pa;
    std::cout << "PR: (" << pr.getX() << "," << pr.getY() << ")" << std::endl;
    
    return 0;
}