#include <iostream>
#include "Pilha/Pilha.h"

int main(){
    char op;
    int v, t;
    
    std::cin >> t;
    
    Pilha pe(t);
    
    while(std::cin >> op){
        try{
            switch(op){
                case 'E':
                    std::cin >> v;
                    pe.empilhar(v);
                    break;
                case 'D':
                    pe.desempilhar();
                    break;
                case 'T':
                    pe.printTopDown();
                    break;
                case 'B':
                    pe.printBottomUp();
                    break;
                default:
                    break;
            }
        }
        catch(PilhaVaziaException pv){
            std::cout << pv.what() << std::endl;
        }
        catch(PilhaCheiaException pc){
            std::cout << pc.what() << std::endl;
        }
    }
    
    return 0;
}