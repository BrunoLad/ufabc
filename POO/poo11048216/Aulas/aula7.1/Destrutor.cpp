#include <iostream>

class Destrutor
{
    private:
            int att;
            char att2;
    public:
            ~Destrutor();
};

Destrutor::~Destrutor()
{
    std::cout << "Estou no Destrutor. Tchau!" << std::endl;
}

int main()
{
    Destrutor obj, *obj2;
    std::cout << "Oi. O programa comecou!" << std::endl;
    std::cout << "Vou instanciar obj2:" << std::endl;
    obj2 = new Destrutor();
    std::cout << "Vou deletar obj2:" << std::endl;
    delete obj2;
    std::cout << "Vou instanciar obj2:" << std::endl;
    obj2 = new Destrutor();
    std::cout << "Vou deletar obj2:" << std::endl;
    delete obj2;
    std::cout << "Nao gostei! Vou embora" << std::endl;
    return 0;
}