#include <iostream>

class Tempo
{
    private:
            int segundos;
    public:
            Tempo()
            {   }
            
            Tempo(int h, int m, int s)
            {
                this->segundos = h*3600+m*60+s;
            }
            
            int getSegundos()
            {
                return this->segundos;
            }
            
            friend int qtdHoras(Tempo *);
};

int qtdHoras(Tempo *t)
{
    int i;
    for(i=0; t->segundos>=3600; i++, t->segundos -= 3600);
    return i;
}

int main()
{
    Tempo *t;
    int h, m, s;
    std::cin >> h >> m >> s;
    t = new Tempo(h, m, s);
    
    std::cout << "ANTES: " << t->getSegundos() << std::endl;
    std::cout << qtdHoras(t) << std::endl;
    std::cout << "DEPOIS: " << t->getSegundos() << std::endl;
    
    return 0;
}