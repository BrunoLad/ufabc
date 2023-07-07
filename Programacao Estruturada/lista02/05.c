#include <stdio.h>

int fatorial(int);

int produto_binomial(int, int);

int main(){
    
    int n, k;
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    printf("%d\n", produto_binomial(n, k));
    
    return 0;
}

int fatorial(int k){
    int ref=1;
    
    for(int i=2; i<=k; i++){
        ref*=i;
    }
    
    return ref;
}

int produto_binomial(int n, int k){
    return fatorial(n)/(fatorial(k)*fatorial(n-k));
}