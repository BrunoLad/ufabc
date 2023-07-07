#include <stdio.h>

int par_ou_impar(int n);

int main(){
    
    int x;
    
    scanf("%d", &x);
    
    /*if(par_ou_impar(x)){
        printf("O numero %d eh impar.\n", x);
    }else{
        printf("O numero %d eh par.\n", x);
    }*/
    
    printf("%d\n", par_ou_impar(x));
    
    return 0;
}

int par_ou_impar(int n){
    
    if(n%2) return 1;
    
    return 0;
}