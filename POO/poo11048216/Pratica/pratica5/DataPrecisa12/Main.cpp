#include <iostream>
#include "DataPrecisa/DataPrecisa.h"

int main(){
    int a, me, d, h, m, s;
    std::string seq, am;
    
    std::cin >> d >> me >> a >> h >> m >> s >> am;
    
    bool tempo = (am=="AM") ? true : false;
    
    DataPrecisa dtp(a, me, d, h, m, s, tempo);
    
    std::cin >> seq;
    
    for(int i=0; i<seq.length(); i++){
        ++dtp;
    }
    
    dtp.imprime();
    
    return 0;
}
/*o erro provavelmente está na mudança na hora de incrementar a data depois do incremento da hora corretamente,
pois tanto o Watch passou, quanto o data precisa no formato de 24 horas, então o algoritmo destes dois estão coerentes*/