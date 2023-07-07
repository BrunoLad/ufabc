#include <stdio.h>

//assinatura das funções
int potenciacao(int x, int y);

int main(){

	int n1, n2;
	
	scanf("%d",&n1);
	scanf("%d",&n2);

	printf("%d\n", potenciacao(n1,n2));
}

int potenciacao(int x, int y){
	int valor = 1;
	
	for (int i = 0; i < y; i++) {
		valor*=x;
	}
	return valor;
}