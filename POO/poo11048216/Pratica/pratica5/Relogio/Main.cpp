#include <iostream>
#include "Relogio/Relogio.h"

int main(){
    
    std::string s;
    /*int h, m, seg; necessário para a questão Relógio 3
    std:: cin >> h >> m >> seg;
    Relogio r(h,m,seg); idem*/
    Relogio r;
    
    while(std::cin >> s){
        if(s=="tic"){
            ++r;
        }else{
            if(s=="tac"){
               r.incrementaMinuto(); 
            }else{
                r.incrementaHora();
            }
        }
    }
    
    r.imprime();
    
    return 0;
}