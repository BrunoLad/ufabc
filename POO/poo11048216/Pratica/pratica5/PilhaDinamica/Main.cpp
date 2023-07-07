#include <iostream>
#include "Pilha/Pilha.h"

int main(){
    
    char op;
    int v;
    Item *it;
    Pilha p;
    
    while(std::cin >> op){
        
        switch(op){
            case 'E':
                std::cin >> v;
                it = new Item(v);
                p.empilhar(it);
                break;
            case 'D':
                p.desempilhar();
                break;
            case 'M':
                p.printStack();
                break;
            default:
                break;
        }
    }
        
    return 0;
}