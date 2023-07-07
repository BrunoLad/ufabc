#include <iostream>

class Construtor
{
    private:
            int att;
            char att2;
    public:
            Construtor();
};

Construtor::Construtor()
{
    std::cout << "Oi! Estou no construtor" << std::endl;
}

int main()
{
    Construtor obj1, *obj2, obj3;
    std::cout << "vou instanciar obj2:" << std::endl;
    obj2 = new Construtor();
    std::cout << "vou deletar obj2:" << std::endl;
    delete obj2;
    std::cout << "vou instanciar obj2 de novo:" << std::endl;
    obj2 = new Construtor();
    std::cout << "vou deletar obj2 de novo:" << std::endl;
    delete obj2;
    return 0;
}