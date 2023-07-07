#include <iostream>
#include <cstdlib>
#include <cstring>

struct tInteiro{
    std::string valor;
};

struct tInteiro inteiro(std::string);
struct tInteiro soma(struct tInteiro, struct tInteiro);
struct tInteiro sub(struct tInteiro, struct tInteiro);
struct tInteiro mult(struct tInteiro, struct tInteiro);

int main(){
    
    while(std::cin)
    {
        std::string N1, N2;
        char op;
        struct tInteiro bign1, bign2, res;
        
        std::cin >> N1 >> op >> N2;
        
        N1[N1.length()] = '\0';
        N2[N2.length()] = '\0';
        
        
        
        bign1 = inteiro(N1);
        bign2 = inteiro(N2);
        
        if(op=='+'){
            res = soma(bign1,bign2);
        }else{
            if(op=='-'){
                
            }else{
                
            }
        }
        
        std::cout << res.valor <<std::endl;
        
    }
    
    
    return 0;
}

struct tInteiro inteiro(std::string s){
    struct tInteiro bn;
    
    bn.valor = s;
    
    return bn;
}

struct tInteiro soma(struct tInteiro a, struct tInteiro b){
    struct tInteiro s;
    
    s.valor = a.valor + b.valor;
    
    return s;
}