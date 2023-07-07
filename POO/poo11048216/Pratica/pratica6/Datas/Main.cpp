#include <iostream>
#include "Data/Data.h"

int main(){
    
    int n, d, m, a;
    
    std::cin >> n;
    
    for(int i=0; i<n; i++){
        
        std::cin >> d >> m >> a;
        
        try{ 
            Data d1(d,m,a);
            std::cout << "DATA VALIDA" << std::endl;
        }
        catch(DataInvalidaException di){
            std::cout << di.what() << std::endl;
        }
    }
    
    return 0;
}