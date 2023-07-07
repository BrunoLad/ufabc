#include <iostream>
#include <cstdlib>

void printvetor (int*, int);

int main()
{
    int v[10], i;
    srand(time(NULL));
    
    for (i=0; i<10; i++) {
        v[i] = rand()%100;
    }
    
    printvetor(v, 10);
    
    return 0;
}


void printvetor(int *vet, int tamanho){
    
    int i;
    
    for(i=0; i<tamanho; i++)
    {
        std::cout << vet[i] << (i < (tamanho-1) ?' ':'\n');
    }
}