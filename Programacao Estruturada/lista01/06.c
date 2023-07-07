#include <stdio.h>

//assinatura das funções
int fatorial(int n);

int main()
{
	int n,resu;

	scanf ("%d",&n);
	resu = fatorial(n);

	printf ("%d\n", resu);

	return 0;
}

//calcula o fatorial do número
int fatorial(int n){
	
	int fat = 1;

	for (int i = n; i>0; i--)
	{
		fat*=i;	
	}

	return fat;
}