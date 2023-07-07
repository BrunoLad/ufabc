#include <iostream>

class ClasseA
{
    public:
            int a;
            ClasseA()
            {
                std::cout << "Estou no construtor A." << std::endl;
            }
};

class ClasseB : virtual public ClasseA
{
    public:
            int b;
            ClasseB()
            {
                std::cout << "Estou no construtor B." << std::endl;
            }
};

class ClasseC : virtual public ClasseA
{
    public:
            int c;
            ClasseC()
            {
                std::cout << "Estou no construtor C." << std::endl;
            }
};

class ClasseD : public ClasseB, public ClasseC
{
    public:
            int d;
            ClasseD()
            {
                std::cout << "Estou no construtor D." << std::endl;
            }
};

int main()
{
    ClasseD obj;
    obj.a = 10;
    return 0;
}