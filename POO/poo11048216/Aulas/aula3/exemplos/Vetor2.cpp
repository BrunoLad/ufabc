#include <iostream>

void printvetor(int*, int);

int main()
{
    int vetor[] = {1,2,3,4,5,6,7,8,9,10};
    
    std::cout << "vetor[0]: " << vetor[0] << std::endl;
    std::cout << "vetor: " << vetor << std::endl;
    std::cout << "vetor: " << *vetor << std::endl;
    
    printvetor(vetor, 10);
    
    return 0;
}

void printvetor(int *v, int n)
{
    int i;
    
    for(i=0; i<10; i++)
    {
       std::cout << v+i << " : " << *(v+i) << std::endl;
    }
    
    std::cout << std::endl;
}