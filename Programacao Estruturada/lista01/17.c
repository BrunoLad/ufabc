#include <stdio.h>
#include <math.h>

//assinatura das funções
int somaGauss(int fim);

int main(){

	int ini, fim;
	int somaQ = 0;
	int quadradoS;
	int descarte, aux;
	scanf("%d", &ini);
	scanf("%d", &fim);

	//faz o quadrado da soma entre ini e fim
	descarte = somaGauss(ini-1);
	descarte *= descarte;
	aux = somaGauss(fim);
	aux *= aux;
	quadradoS = aux - descarte;

	//faz soma dos quadrados entre ini e fim
	for (int i=ini; i<=fim; i++) {
		somaQ += (i*i);
	}

	printf("soma dos quadrados = %d\n", somaQ);
	printf("quadrado da soma   = %d\n", quadradoS);
	printf("diferenca          = %d\n", (int)(fabs(quadradoS - somaQ)));

	return 0;
}

//retorna a soma de gauss de 1 até fim
int somaGauss(int fim){
	return ((1+fim)*fim)/2;
}