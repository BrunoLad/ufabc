#include <stdio.h>
#include <math.h>

float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);
float potenciacao(float a, float b);

float main(){
    
    int op;
    float resu;
    scanf("%d", &op);
    
    float a, b;
    scanf("%f", &a);
    scanf("%f", &b);
    
    
    switch(op){
        case 1:
            resu = soma(a, b);
            break;
        case 2:
            resu = subtracao(a, b);
            break;
        case 3:
            resu = multiplicacao(a, b);
            break;
        case 4:
            resu = divisao(a, b);
            break;
        case 5:
            resu = potenciacao(a, b);
            break;
    }
    
    printf("%f\n", resu);
    
    return 0;
}

float soma(float a, float b){
    return (a + b);
}

float subtracao(float a, float b){
    return (a-b);
}

float multiplicacao(float a, float b){
    return (a*b);
}

float divisao(float a, float b){
    return (a/b);
}

float potenciacao(float a, float b){
    return pow(a, b);
}