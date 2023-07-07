#include <iostream>
#include "DataPrecisa/DataPrecisa.h"

int main(){
    
    int a, me, d, h, m, s;
    std::string seq;
    
    std::cin >> d >> me >> a >> h >> m >> s;
    
    DataPrecisa dtp(a, me, d, h, m, s);
    
    std::cin >> seq;
    
    for(int i=0; i<seq.length(); i++){
        ++dtp;
    }
    
    dtp.imprime();
    
    return 0;
}