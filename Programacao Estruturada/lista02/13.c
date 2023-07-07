#include <stdio.h>

unsigned int mdc(int a, int b);

int main(){

	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);

	printf("%d\n", mdc(m,n));

	return 0;
}

unsigned int mdc(int a, int b){
	if(!a) return b;
	if(!b) return a;

	return b > a ? mdc(a, (a%b)) : mdc(b, (b%a));
}