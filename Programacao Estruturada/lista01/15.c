#include <stdio.h>

int main(){

	
	int n;
	scanf("%d", &n);

	//imprime todos os valores entre 100 e n que são divisíveis por 2
	for (int i=100; i<=n; i+=2) {
		if (i == n || i == (n-1)) {
			printf("%d\n", i);
		} else {
			printf("%d, ", i);
		}
	}

	return 0;
}