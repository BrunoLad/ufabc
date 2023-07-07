#include <iostream>
#include "Racionais/Racionais.h"

int main(){
    
    int n1, d1, n2, d2;
    char op;
    
    while(std::cin >> n1 >> d1 >> op >> n2 >> d2){
        try{
            Racionais r1(n1,d1), r2(n2,d2), res;
            switch(op){
                case '+':
                    res = r1+r2;
                    res.imprime();
                    break;
                case '-':
                    r2.oposto();
                    res = r1 + r2;
                    res.imprime();
                    break;
                case '*':
                    res = r1 * r2;
                    res.imprime();
                    break;
                case '/':
                    r2.inverso();
                    res = r1 * r2;
                    res.imprime();
                    break;
                default:
                    break;
            }
        }
        catch(DenominadorZeroException de){
            std::cout << de.what() << std::endl;
        }
    }
    
    return 0;
}