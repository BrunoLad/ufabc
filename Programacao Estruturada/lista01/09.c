#include <stdio.h>

//assinatura das funções
double conversorCF(double temp, int op);

int main(){

	int op;
	double temp;
	
	scanf("%lf", &temp);
	scanf("%d", &op);

	temp = conversorCF(temp, op);

	printf("%.1lf\n", temp);

}

//Recebe uma temperatura e faz a conversão entre celsius e fahrenheit
//1 C->F
//2 F->C
double conversorCF(double temp, int op){
	double nTemp;

	if (op==1) {
		nTemp = (9*temp/5) + 32; 
	} else {
		nTemp = (5*temp - 160)/9;
	}

	return nTemp;
}