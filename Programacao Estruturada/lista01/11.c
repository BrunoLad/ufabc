#include <stdio.h>
#include <math.h>

//assinatura de funções
int conversorBinDec(int valor, int op);

int main(){

	int v, op;

	scanf("%d", &v);
	scanf("%d", &op);

	v = conversorBinDec(v, op);

	printf("%d\n", v);

	return 0;
}

//conversor entre Binário e decimal
//1 converte de decimal para binário
//2 converte de binário para decimal

int conversorBinDec(int valor, int op){
	int nValor=0;
	int pos = 1;

	if (op==1) {
		while (valor!=0) {
			nValor = nValor + pos*(valor%2);
			valor /= 2;
			pos*=10;
		} 
	} else {
		pos = 0;
		while(valor != 0){
			nValor = pow(2,pos)*(valor%10) +nValor;
			pos++;
			valor /= 10;
		}
	}

	return nValor;
}