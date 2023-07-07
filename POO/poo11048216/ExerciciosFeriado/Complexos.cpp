#include <iostream>
#include <cstring>
#include <cstdlib>

struct tComplex{
    int real;
    int imaginaria;
};

struct tComplex complexo(int, int);
struct tComplex soma(struct tComplex, struct tComplex);
struct tComplex sub(struct tComplex, struct tComplex);
struct tComplex mult(struct tComplex, struct tComplex);
struct tComplex divi(struct tComplex, struct tComplex);

int main(){
    
    while(std::cin){
        std::string im1,im2;
        int r1,r2, comp1, comp2;
        char op;
        struct tComplex c1,c2, res;
        
        std::cin >> r1 >> im1 >> op >> r2 >> im2;
        
        im1[im1.length()-1] = ' ';//removendo o i da string
        im2[im2.length()-1] = ' ';
        
        comp1 = atoi(im1.c_str());//faltou tratar quando a string for só i ou -i
        comp2 = atoi(im2.c_str());
        
        c1 = complexo(r1,comp1);//setando o numero complexo
        c2 = complexo(r2,comp2);
        
        if(op=='+'){
            res = soma(c1,c2);
        }else{
            if(op=='-'){
                res = sub(c1,c2);
            }else{
                if(op=='*'){
                    res=mult(c1,c2);
                }else{
                    res=divi(c1,c2);
                }
            }
        }
        
        std::cout << res.real << " " << res.imaginaria << "i" << std::endl;//faltou adicionar o + na frente quando for positivo a parte imaginária
        
        
    }
    
    return 0;
}

struct tComplex complexo(int r, int im){
    struct tComplex c;
    
    c.real=r;
    c.imaginaria=im;
    
    return c;
}

struct tComplex soma(struct tComplex c1, struct tComplex c2){
    struct tComplex res;
    
    res.real = c1.real + c2.real;
    res.imaginaria = c1.imaginaria + c2.imaginaria;
    
    return res;
}

struct tComplex sub(struct tComplex c1, struct tComplex c2){
    struct tComplex d;
    
    d.real = c1.real - c2.real;
    d.imaginaria = c1.imaginaria - c2.imaginaria;
    
    return d;
}

struct tComplex mult(struct tComplex c1, struct tComplex c2){
    struct tComplex p;
    
    p.real = (c1.real*c2.real) - (c1.imaginaria*c2.imaginaria);
    p.imaginaria = (c1.real*c2.imaginaria) + (c1.imaginaria*c2.real);
    
    
    return p;
}

struct tComplex divi(struct tComplex c1, struct tComplex c2){
    struct tComplex d, aux;
    
    aux = c2;
    aux.imaginaria = -aux.imaginaria;
    
    c2 = mult(c2, aux);
    c1 = mult(c1, aux);
    
    d.real=(c1.real)/(c2.real+c2.imaginaria);//preciso representar na forma fracionaria?
    d.imaginaria=(c1.imaginaria)/(c2.real+c2.imaginaria);
    
    
    return d;
}