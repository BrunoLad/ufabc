#include <iostream>
#include <cmath>

struct tRacional{
    int numerador;
    int denominador;
};

struct tRacional racional(int, int);

struct tRacional negativo(struct tRacional);

struct tRacional soma(struct tRacional, struct tRacional);

struct tRacional mult(struct tRacional, struct tRacional);

struct tRacional divi(struct tRacional, struct tRacional);

struct tRacional reduz(struct tRacional);

int fatorComum(int, int);

int main(){
    
    int n1, n2, d1, d2;
    char operacao;
    
    while(std::cin){
        std::cin >> n1 >> d1 >> operacao >> n2 >> d2;
        struct tRacional racional1, racional2, resultado;
        
        racional1 = racional(n1,d1);
        racional2 = racional(n2,d2);
        
        
        if(operacao=='+'){
            resultado = soma(racional1, racional2);
            resultado = reduz(resultado);
        }else{
            if(operacao=='-'){
                racional2 = negativo(racional2);
                resultado = soma(racional1,racional2);
                resultado = reduz(resultado);
            }else{
                if(operacao=='*'){
                    resultado = mult(racional1,racional2);
                    resultado = reduz(resultado);
                }else{
                    resultado = divi(racional1, racional2);
                    resultado = reduz(resultado);
                }
            }
        }
        
        std::cout << resultado.numerador << " " << resultado.denominador << std::endl;
    }
    
    return 0;
}

struct tRacional reduz(struct tRacional rac){
    int c;
    
    if(std::abs(rac.numerador)!=1 && rac.denominador!=1){
        c = fatorComum(std::abs(rac.numerador), rac.denominador);
        rac.numerador/=c;
        rac.denominador/=c;
    }
    return rac;
    
}

struct tRacional mult(struct tRacional racional1, struct tRacional racional2){
    struct tRacional rac;
    
    rac.numerador = racional1.numerador*racional2.numerador;
    rac.denominador = racional1.denominador*racional2.denominador;
    
    return rac;
    
}

struct tRacional divi(struct tRacional racional1, struct tRacional racional2){
    struct tRacional rac;
    
    rac.numerador = racional1.numerador*racional2.denominador;
    rac.denominador = racional1.denominador*racional2.numerador;
    
    return rac;
}

struct tRacional racional(int n, int d){
    struct tRacional rac;
    
    rac.numerador = n;
    rac.denominador = d;
    
    return rac;
}

int fatorComum(int n1, int n2){
    /*int c;
    int i=1;
    
    while(i <=n1 || i<=n2){
        if(n1%i==0 && n2%i==0){
            c=i;
        }
        i++;
    }
    return c;*/
    int r, a, b;
    r=n1%n2;
    a=n2;
    b=r;
    
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    
    return ((n1*n2)/a);
}

struct tRacional soma(struct tRacional racional1, struct tRacional racional2){
    struct tRacional s;
    int com;
    
    if(racional1.denominador==racional2.denominador){
        s.denominador = racional1.denominador;
        s.numerador = racional1.numerador + racional2.numerador;
    }else{
        
        com = fatorComum(racional1.denominador,racional2.denominador);
        
        if(com!=1){
            s.denominador = (racional1.denominador*racional2.denominador)/com;
            s.numerador = (racional1.numerador*(s.denominador/racional1.denominador)) + (racional2.numerador*(s.denominador/racional2.denominador));
        }else{
            s.denominador = racional1.denominador*racional2.denominador;
            s.numerador = (racional1.numerador*(s.denominador/racional1.denominador)) + (racional2.numerador*(s.denominador/racional2.denominador));
        }
    }
    return s;
}

struct tRacional negativo(struct tRacional rac){
    rac.numerador= -rac.numerador;
    
    return rac;
}