#include <stdio.h>

int potenciacao(int x, int y);
int retorna_pot(int x, int y);

int main(){

	int x, y;
	scanf("%d", &x);
	scanf("%d", &y);

	printf("%d\n", retorna_pot(x, y));

	return 0;
}

int retorna_pot(int x, int y){
	int val = 1;
	
	val*=potenciacao(x,y);

	return val;
}

int potenciacao(int x, int y){
	if(y>1){
		y--;
		return x*potenciacao(x,y);
	}
}