#include <stdio.h>

int main(){

	int soma = 0;
	int aux;

	//recebe 10 valores e calcula a média entre eles
	for (int i=0; i<10; i++) {
		scanf("%d",&aux);
		soma += aux;
	}

	printf("soma = %d\n",soma);
	printf("media = %.1f\n",soma/10.0f);

	return 0;
}