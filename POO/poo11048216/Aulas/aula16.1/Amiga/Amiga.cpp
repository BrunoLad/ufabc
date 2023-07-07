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
            
            friend int qtdHoras(Tempo*);
};

int qtdHoras(Tempo *t)
{
    int i;
    for(i=0; t->segundos >= 3600; i++, t->segundos-=3600);
    return i;
}

int main()
{
    Tempo *temp;
    int h, m, s, qtH;
    std::cin >> h >> m >> s;
    temp = new Tempo(h, m, s);
    std::cout << "Antes: " << temp->getSegundos() << std::endl;
    qtH = qtdHoras(temp);
    std::cout << "Depois: " << temp->getSegundos() << std::endl;
    std::cout << "qtH: " << qtH << std::endl;
    return 0;
}