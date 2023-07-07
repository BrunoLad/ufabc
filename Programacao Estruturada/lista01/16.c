#include <stdio.h>

int main(){

	int id, faltas, h_extra;
	scanf("%d", &id);
	scanf("%d", &faltas);
	scanf("%d", &h_extra);

	float desc, acresc;
	switch(id){
		case 1:
			acresc = h_extra < 40 ? (h_extra*((10000/160.0f)+40)) : (40*((10000/160.0f)+40));
			desc = (0.05 * 10000.0f)*faltas;
			printf("cargo        : %s\n", "Diretor");
			printf("# de faltas  : %d\n", faltas);
			printf("# horas-extra: %d\n", h_extra);
			printf("descontos    : %.2f\n", desc);
			printf("acrescimos   : %.2f\n", acresc);
			printf("salario      : %.2f\n", (acresc + 10000 - desc));
			break;
		case 2:
			acresc = h_extra < 40 ? (h_extra*((8000/160.0f)+40)) : (40*((8000/160.0f)+40));
			desc = (0.05 * 8000.0f)*faltas;
			printf("cargo        : %s\n", "Gerente");
			printf("# de faltas  : %d\n", faltas);
			printf("# horas-extra: %d\n", h_extra);
			printf("descontos    : %.2f\n", desc);
			printf("acrescimos   : %.2f\n", acresc);
			printf("salario      : %.2f\n", (acresc + 8000 - desc));
			break;
		case 3:
			acresc = h_extra < 40 ? (h_extra*((5000/160.0f)+40)) : (40*((5000/160.0f)+40));
			desc = (0.05 * 5000.0f)*faltas;
			printf("cargo        : %s\n", "Engenheiro");
			printf("# de faltas  : %d\n", faltas);
			printf("# horas-extra: %d\n", h_extra);
			printf("descontos    : %.2f\n", desc);
			printf("acrescimos   : %.2f\n", acresc);
			printf("salario      : %.2f\n", (acresc + 5000 - desc));
			break;
		case 4:
			acresc = h_extra < 40 ? (h_extra*((3000/160.0f)+40)) : (40*((3000/160.0f)+40));
			desc = (0.05 * 3000.0f)*faltas;
			printf("cargo        : %s\n", "Tecnico");
			printf("# de faltas  : %d\n", faltas);
			printf("# horas-extra: %d\n", h_extra);
			printf("descontos    : %.2f\n", desc);
			printf("acrescimos   : %.2f\n", acresc);
			printf("salario      : %.2f\n", (acresc + 3000 - desc));
			break;
		case 5:
			acresc = h_extra < 40 ? (h_extra*((2000/160.0f)+40)) : (40*((2000/160.0f)+40));
			desc = (0.05 * 2000.0f)*faltas;
			printf("cargo        : %s\n", "Operador");
			printf("# de faltas  : %d\n", faltas);
			printf("# horas-extra: %d\n", h_extra);
			printf("descontos    : %.2f\n", desc);
			printf("acrescimos   : %.2f\n", acresc);
			printf("salario      : %.2f\n", (acresc + 2000 - desc));
			break;
		default:
			break;
	}

	return 0;
}