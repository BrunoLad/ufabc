#include <iostream>
#include "Watch/Watch.h"

int main(){
    
    std::string s;
    //o p também
    /*int h, m, seg;
    std::cin >> h >> m >> seg >> p;
    Watch *w;
    w = new Watch(h,m,seg,p);*/
    Watch w;
    
    while(std::cin >> s){
        if(s=="tic"){
            ++w;
        }else{
            if(s=="tac"){
               w.incrementaMinuto(); 
            }else{
                w.incrementaHora();
            }
        }
    }
    w.imprime();
    
    return 0;
}