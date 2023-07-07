#include <iostream>
#include <cmath>

int main(){
    
    int v, *c, ref=100;
    
    c = new int[7];
    
    std::cin >> v;
    
    std::cout << "R$" << v << ".00" << std::endl;
    
    c[0] = v/100;
    v = v - (c[0]*100);
    
    c[1] = v/50;
    v = v - (c[1]*50);
    
    c[2] = v/20;
    v = v - (c[2]*20);
    
    c[3] = v/10;
    v = v - (c[3]*10);
    
    c[4] = v/5;
    v = v - (c[4]*5);
    
    c[5] = v/2;
    v = v - (c[5]*2);
    
    c[6] = v;
    
    for(int i=0; i<7; i++){
        if(*(c+i)>0){
            std::cout << *(c+i) << " nota(s) de R$" << ref << ".00" << std::endl;
        }
        
        if(ref==50){
            ref = 20;
        }else{
            ref = floor(ref/2);
        }
    }
    
    delete c;
    
    return 0;
}