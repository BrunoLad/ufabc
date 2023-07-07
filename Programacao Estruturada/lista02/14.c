#include <stdio.h>
#include <math.h>

int inverta_numero(int n, int tam);
int calcula_tamanho(int n);

int main(){

	int pal;
	scanf("%d", &pal);

	if(pal == inverta_numero(pal, calcula_tamanho(pal))){
		//printf("%d\n", inverta_numero(pal, calcula_tamanho(pal)));
		printf("sim\n");
	}else{
		//printf("%d\n", inverta_numero(pal, calcula_tamanho(pal)));
		printf("nao\n");
	}

	return 0;
}

int inverta_numero(int n, int tam){
	if(n){
		int tamAnt = tam;
		tam--;
		return pow(10,tam)*(n%10) + inverta_numero(n/10, tam);
	}
}

int calcula_tamanho(int n){
	if(n){
		return 1 + calcula_tamanho(n/10);
	}
}