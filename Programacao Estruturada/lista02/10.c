#include <stdio.h>

int fibMem[1000];

int fib (int n);

int main()
{	
	int n;

	fibMem[1] = 1;
	fibMem[2] = 1;

	scanf("%d", &n);
	printf("%d\n", fib(n));
	return 0;
}

//a saida exigida e o do programa original estão diferentes
//qual a correta?
int fib (int n)
{
	if (n==0) return 0;
	if (n<=2) return 1;

	if (fibMem[n] != (fib(n-1) + fib(n-2))) {
		fibMem[n] = fib(n-1) + fib(n-2);
	}

	return fibMem[n];
}