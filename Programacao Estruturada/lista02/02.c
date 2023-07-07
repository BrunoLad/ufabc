#include <stdio.h>

float calcula_volume(float x, float y, float z);

int main(){
    
    float c, l, a;
    
    scanf("%f", &l);
    scanf("%f", &c);
    scanf("%f", &a);
    
    printf("%.2f\n" ,calcula_volume(l, c, a));
    
    return 0;
}

float calcula_volume(float x, float y, float z){
    return (x*y*z);
}