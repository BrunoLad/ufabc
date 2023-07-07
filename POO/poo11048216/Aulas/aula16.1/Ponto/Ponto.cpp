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
                this->x = x;
                this->y = y;
            }
            
            Ponto operator+(Ponto p)
            {
                Ponto pr;
                pr.x = this->x + p.x;
                pr.y = this->y + p.y;
                return pr;
            }
            
            Ponto operator+(int v)
            {
                Ponto pr;
                pr.x = this->x + v;
                pr.y = this->y + v;
                return pr;
            }
            
            int getX()
            {
                return this->x;
            }
            
            int getY()
            {
                return this->y;
            }
            
            friend Ponto operator+(int, Ponto);
};

Ponto operator+(int v, Ponto p)
{
    Ponto pr;
    pr.x = p.getX() + v;
    pr.y = p.getY() + v;
    return pr;
}

int main()
{
    Ponto pa(10, 2), pb(5, 3), pr;
    pr = pa + pb;
    std::cout << "PR:(" << pr.getX() << ", " << pr.getY() << ")\n";
    pr = pa + 5;
    std::cout << "PR:(" << pr.getX() << ", " << pr.getY() << ")\n";
    pr = 5 + pa;
    std::cout << "PR:(" << pr.getX() << ", " << pr.getY() << ")\n";
    return 0;
}