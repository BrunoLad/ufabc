#include <iostream>
#include "Lista/Lista.h"

int main(){
    
    char op;
    int v;
    LDE dylist;
    Item *pit;
    
    while(std::cin >> op){
        switch(op){
            case 'I':
                std::cin >> v;
                pit = new Item(v);
                dylist.inclusao(pit);
                break;
            case 'R':
                std::cin >> v;
                dylist.exclusao(v);
                break;
            case 'B':
                std::cin >> v;
                if(dylist.busca(v)){
                    std::cout << "SIM" << std::endl;
                }else{
                    std::cout << "NAO" << std::endl;
                }
                break;
            case 'L':
                dylist.imprime();
                break;
            default:
                break;
        }
    }
    
    return 0;
}