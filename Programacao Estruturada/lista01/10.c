#include <stdio.h>

//assinatura dos metodos
double conversorCK(double temp, int op);

int main(){

	int opcao;
	double temp;

	scanf("%lf", &temp);
	scanf("%d", &opcao);

	temp = conversorCK(temp, opcao);

	printf("%.2lf\n", temp);

	return 0;
}

//conversão entre kelvin e celsius
//op == 1 C->K
//op == 2 K->c
double conversorCK(double temp, int op){
	double nTemp;

	if (op==1) {
		nTemp = temp + 273.15;
	} else {
		nTemp = temp - 273.15;
	}

	return nTemp;
}