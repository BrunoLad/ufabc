#include <iostream>
#include "Pilha/Pilha.h"

int main(){
    char op;
    Pilha pd;
    int v;
    
    while(std::cin >> op){
        try{
            switch(op){
                case 'E':
                    std::cin >> v;
                    Item *iadd;
                    iadd = new Item(v);
                    pd.empilhar(iadd);
                    break;
                case 'D':
                    pd.desempilhar();
                    break;
                case 'M':
                    pd.imprime();
                    break;
                default:
                    break;
            }
        }
        catch(PilhaVaziaException pe){
            std::cout << pe.what() << std::endl;
        }
    }
    
    return 0;
}