#include <iostream>
#include <cstdlib>

void printvetor(int*, int);

int main()
{
    int n, *vet;
    
    std::cin >> n;
    vet = new int[n];
    
    srand(time(NULL));
    
    for(int i=0; i<n; i++)
    {
        vet[i] = rand()%10;
    }
    
    printvetor(vet, n);
    
    return 0;
}

void printvetor (int *v, int n){
    
    int i;
    for(i=0; i<n; i++)
    {
        std::cout << v[i] << (i<n-1?' ':'\n');
    }
    
}