#include <stdio.h>

//Assinatura dos métodos
void isPar(int n);

//Verifica e imprime se o número é par
void isPar(int n){
	
	if(n % 2){
		printf("impar\n");
	}else printf("par\n");
}

int main(){
	
	int n;
	
	scanf("%d",&n);
	isPar(n);
	
	return 0;
}

