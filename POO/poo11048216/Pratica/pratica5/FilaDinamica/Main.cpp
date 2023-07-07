#include <iostream>
#include "Fila/Fila.h"

int main(){
    
    FilaDinamica fd;
    char op;
    int v;
    
    while(std::cin >> op){
        switch(op){
            case 'E':
                std::cin >> v;
                Item *itenzin;//só criei o ponteiro, mas não instanciei
                itenzin = new Item();//agora o objeto foi instanciado e consequentemente é possível acessar os atributos e utilizar os métodos
                itenzin->setValor(v);
                fd.enfileirar(itenzin);
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
    

    
    return 0;
}