#include <stdio.h>

//assinatura das funções
int somaGauss(int fim);

int main(){

	int fim;

	scanf("%d", &fim);
	printf("%d\n", somaGauss(fim));

	return 0;
}

//faz a soma dos números de 1 até fim
int somaGauss(int fim){
	int total = ((1+fim)*fim)/2;

	return total;
}