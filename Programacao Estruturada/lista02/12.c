#include <stdio.h>
#include <math.h>

int produto_binomail(int n, int k);
int fatorial(int n);

int main(){
	
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);

	printf("%d\n", produto_binomial(n, k));

	return 0;
}

/*feito sem o triângulo
com o triângulo teria que fazer
return 2^n - produto_binomial(n, 0)... produto_binomial(n, n)
pulando o produto_binomial(n, k)*/
int produto_binomial(int n, int k){
    return fatorial(n)/(fatorial(k)*fatorial(n-k));
}
int fatorial(int n){
	
	if (n==0) return 1;

	return n*(fatorial(n-1));
}