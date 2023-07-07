#include <stdio.h>
#include <math.h>
#include <string.h>

//assinatura das funções
char* conversorDcHx(int valor);
int conversorHxDc(char *valor);


int main(){
	int op;
	char vHx[100];
	int valor;

	scanf("%d", &op);

	if (op==1) {
		scanf("%d", &valor);
		char hex[100];
		int cont = 0;

		while (valor!=0) {
			switch (valor%16) {
				case 15:
					hex[cont] = 'F';
					cont ++;
					break;
				case 14:
					hex[cont] = 'E';
					cont ++;
					break;
				case 13:
					hex[cont] = 'D';
					cont ++;
					break;
				case 12:
					hex[cont] = 'C';
					cont ++;
					break;
				case 11:
					hex[cont] = 'B';
					cont ++;
					break;
				case 10:
					hex[cont] = 'A';
					cont ++;
					break;
				default:
					hex[cont] = valor%16;
					cont ++;
			}
			valor/=16;
		}
		
		hex[cont] ='\0';
		cont = 0;

		while (hex[cont] !='\0') {
			printf("%c", hex[cont]);
			cont ++;
		}
			printf("\n");

		//printf("%s\n", vHx);
	} else {
		scanf("%s", vHx);
		valor = conversorHxDc(vHx);
		printf("%d\n", valor);
	}

	return 0;
}

int conversorHxDc(char *vHx){
	int cont = 0;
	int valor = 0;
	while (vHx[cont]!='\0') {
			if (vHx[cont] == 'A' || vHx[cont] == 'a') {
				valor+= (10*pow(16,cont));
			} else {
				if (vHx[cont] == 'B' || vHx[cont] == 'b') {
					valor+= (11*pow(16,cont));
				} else {
					if (vHx[cont] == 'C' || vHx[cont] == 'c') {
						valor+= (12*pow(16,cont));
					} else {
						if (vHx[cont] == 'D' || vHx[cont] == 'd') {
							valor+= (13*pow(16,cont));
						} else {
							if (vHx[cont] == 'E' || vHx[cont] == 'e') {
								valor+= (14*pow(16,cont));
							}else{
								if (vHx[cont] == 'F' || vHx[cont] == 'f') {
									valor+= (15*pow(16,cont));
								}else{
									valor+= ((int)(vHx[cont])*pow(16,cont));
								}
							}
						}
					}
				}
			}
			cont ++;
		}

	return valor;
}