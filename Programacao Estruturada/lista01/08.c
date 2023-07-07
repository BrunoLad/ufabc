#include <stdio.h>

//assinatura das funções
void fibonacci(int n);

int main(){

	int n;

	scanf("%d", &n);
	fibonacci(n);

	return 0;
}

void fibonacci(int n){
	int ant = 0;
	int atu = 1;
	int aux;

	if (n>=2) {
	
		printf("%d, ", ant);
		printf("%d, ", atu);

		for (int i = 1; i<n; i++) {
			aux = atu;
			atu += ant;
			ant = aux;
			
			if (i==(n-1)) {
				printf("%d\n",atu);
			} else {
				printf("%d, ", atu);
			}
		}
	} else {
		if (n==1) {
			printf("%d\n", atu);
		} else {
			printf("%d\n", ant);
		}
	}
}