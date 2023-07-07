#include <stdio.h>

//assinatura dos métodos
void sub(int n, int m);

//recebe dois números e imprime o quociente entre eles
void sub(int n, int m){
	printf("%d\n",(n/m));
}

int main(){

	int n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);

	sub(n1,n2);

	return 0;
}