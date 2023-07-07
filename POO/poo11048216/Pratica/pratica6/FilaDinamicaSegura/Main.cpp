#include <iostream>
#include "Fila/Fila.h"

int main(){
    char op;
    int v;
    Fila fd;
    
    while(std::cin >> op){
        try{
            switch(op){
                case 'E':
                    std::cin >> v;
                    Item *atu;
                    atu = new Item();
                    atu->setValor(v);
                    fd.enfileirar(atu);
                    break;
                case 'D':
                    fd.desenfileirar();
                    break;
                case 'M':
                    fd.imprime();
                    break;
                default:
                    break;
            }
        }
        catch(FilaVaziaException fe){
            std::cout << fe.what() << std::endl;
        }
    }
    
    return 0;
}