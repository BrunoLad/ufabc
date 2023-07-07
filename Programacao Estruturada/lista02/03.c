#include <stdio.h>
#include <math.h>

double gauss_legendre_sequence();

int main(){
    
    printf("%lf\n", gauss_legendre_sequence());
    
    return 0;
}

double gauss_legendre_sequence(){
    float a = 1;
    float b= 1/(sqrt(2));
    float t = 0.25;
    float p = 1;
    
    for(int i=0; i < 10; i++){
        float a1 = (a+b)/2;
        b = sqrt((a*b));
        t = t - p*(pow((a-a1),2));
        p = 2*p;
        a = a1;
    }
    
    return (pow(a+b,2)/(4*t));
}