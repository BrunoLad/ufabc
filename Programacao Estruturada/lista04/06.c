#include <stdio.h>
#include <time.h>
#include <limits.h>

#define BIGNUM ULONG_MAX

typedef unsigned long int ulint;

ulint f1(ulint x, ulint y)
{
    /*int div = 8;
    return x / div;*/
    if (x > y) return x;
    
    return y;
}

ulint f2(ulint x, ulint y)
{
    //return x >> 3;
    /*ulint yori = y;
    ulint xori = x;
    ulint posx = 0;
    ulint posy = 0;
    while (x || y) {
        if (x) {
            posx++;
        } else {
            return yori;
        }
        
        if (y) {
            posy++;
        }else{
            return xori;
        }
        x >>= 1;
        y >>= 1;
    }
    return x;*/
    
}

int main(void) {
    
    clock_t tempo_init, tempo_fim;
    double tempo_gasto;
    ulint soma = 0;
    
    tempo_init = clock();
    for(int i = 0; i<BIGNUM; i++){
        soma+=f1(i, i+1);
    }
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
    printf("Tempo gasto na versao normal: %lf\n", tempo_gasto);
    
    soma = 0;
    tempo_init = clock();
    for (int i = 0 ; i<BIGNUM; i++) {
        soma+=f2(i, i+1);
    }
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
    printf("Tempo gasto na versao bitwise: %lf\n", tempo_gasto);
}