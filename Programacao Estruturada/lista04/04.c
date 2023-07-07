#include <stdio.h>
#include <time.h>
#include <limits.h>

#define BIGNUM ULONG_MAX

typedef unsigned long int ulint;

ulint f1(ulint x)
{
    /*int div = 8;
    return x / div;*/
    ulint soma = 0;
    
    while(x){
        if(!(x % 2)){
            soma++;
            x/=2;
        }else{
            return -1;
        }
    }
}

ulint f2(ulint x)
{
    //return x >> 3;
    ulint ref = 2;
    ulint pos = 1;
    while(x >= ref){
        if(x & ref && !(~ref & x)){
            return pos;
        }else{
            ref <<= 1;
            pos++;
        }
    }
    /*ulint soma = 0;
    ulint pos = 0;
    while (x) {
        soma += x & 1;
        x >>= 1;
        pos++;
        printf("%lu\n", x);
    }
    if (soma == 1) return pos;
    return -1;*/
}

int main(void) {
    
    clock_t tempo_init, tempo_fim;
    double tempo_gasto;
    ulint soma = 0;
    
    /*tempo_init = clock();
    for(int i = 0; i<BIGNUM; i++){
        soma+=f1(i);
    }
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
    printf("Tempo gasto na versao normal: %lf\n", tempo_gasto);*/
    
    soma = 0;
    tempo_init = clock();
    for (int i = 0 ; i<BIGNUM; i++) {
        soma+=f2(i);
    }
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
    printf("Tempo gasto na versao bitwise: %lf\n", tempo_gasto);
}