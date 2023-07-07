#include <stdio.h>
#include <math.h>

//assinatura dos métodos
double calcula_delta(double a, double b, double c);
double primeira_raiz(double a, double b, double delta);
double segunda_raiz(double a, double b, double delta);
double parte_imaginaria(double delta, double a);
char formatacao(double n); 

int main(){
	double a, b, c;
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);

	char c1 = formatacao(b);
	char c2 = formatacao(c);

	printf("A equacao eh %.2lfx^2 %c%.2lfx %c%.2lf = 0\n", a, c1, b, c2, c);

	double aux = calcula_delta(a, b, c);

	if(!aux){
		printf("A equacao possui uma so raiz real x1=x2= %.3lf\n", primeira_raiz(a, b, 0));
	}else{
		if(aux > 0){
			printf("A equacao possui 2 raizes reais distintas\n");
			printf("Primeira raiz x1 = %.3lf\n", primeira_raiz(a, b, aux));
			printf("Segunda raiz x2 = %.3lf\n", segunda_raiz(a, b, aux));
		}else{
			printf("A equacao possui 2 raizes imaginarias\n");
			printf("Primeira raiz x1 = %.3lf %.3lfi\n", primeira_raiz(a, b, aux), parte_imaginaria(aux, a));
			printf("Segunda raiz x2 = %.3lf %.3lfi\n", segunda_raiz(a, b, aux), parte_imaginaria(aux, -a));
		}
	}
	return 0;
}

double calcula_delta(double a, double b, double c){
	return (b*b) - (4*a*c);
}

//implementado duas raizes, porque a convenção foi não
//utilizar o printf e scanf dentro das funções
//cada método retorna uma raiz
double primeira_raiz(double a, double b, double delta){
	return ((-1)*b + sqrt(delta))/(2*a);
}

double segunda_raiz(double a, double b, double delta){
	return ((-1)*b - sqrt(delta))/(2*a);
}

double parte_imaginaria(double delta, double a){
	return sqrt(delta)/(2*a);
}

char formatacao(double n){
	if(n > 0){
		return '+';
	}else{
		return ' ';
	}
}