#include <stdio.h>
#include <math.h>

int conversor_binario(int v, int ind);
int retorna_conversao(int op, int v);
int conversor_decimal(int v, int ind);

int main(){

	int op, n;
	scanf("%d", &n);
	scanf("%d", &op);

	printf("%d\n",retorna_conversao(op, n));

	return 0;
}

int retorna_conversao(int op, int v){
	if(op==1){
		conversor_binario(v, 1);
	}else{
		conversor_decimal(v, 0);
	}
}

int conversor_binario(int v, int ind){
	if(v){
		int dev = v%2;
		int indA = ind;
		ind*=10;
		v/=2;
		return (dev*indA) + conversor_binario(v, ind);
	}
	return 0;
}

int conversor_decimal(int v, int ind){
	if(v){
		int dev = v%10;
		int indA = ind;
		ind++;
		v/=10;

		return dev*(pow(2, indA)) + conversor_decimal(v, ind);
	}
	return 0;
}