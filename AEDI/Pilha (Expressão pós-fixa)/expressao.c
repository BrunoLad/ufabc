#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedNodeD LinkedNodeD;
struct LinkedNodeD {
	double val;
	LinkedNodeD *proximo;
};

typedef struct pilhaD pilhaD;
struct pilhaD {
	LinkedNodeD *topo;
};

void insercaoD(pilhaD *pl, double c) {
	LinkedNodeD *novo = malloc(sizeof(LinkedNodeD));
	novo->val = c;

	if(pl->topo == NULL){
		pl->topo = novo;
		(pl->topo)->proximo = NULL;
	}else{
		novo->proximo = pl->topo;
		pl->topo = novo;
	}
}

LinkedNodeD * desalocarD(pilhaD *pl){
	if(pl->topo == NULL) return NULL;
		
	LinkedNodeD *aux = pl->topo;
	pl->topo = (pl->topo)->proximo;
	return aux;
}

double operacaoUnaria(double n1) {
	return n1 * 3.0f;
}

double operacaoBinaria(double n1, double n2, char op){
	if (op == '+')
	{
		return n1 + n2;
	}
	
	return n1 - n2;
}

double operacaoTernaria(double n1, double n2, double n3, char op){
	if (op == 'f')
	{
		return ((n1*n1) - (n2/2.0f) + n3);
	}

	return ((n1*n2) + n3);
}

//para impedir que a conversão converte para valores da tabela ASCII
int conversaocharInt(char c){
	switch(c){
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return -1;
	}
}

int main(int argc, char const *argv[])
{
	char entrada[100];
	scanf("%s", entrada);
	
	pilhaD *numeros = malloc(sizeof(pilhaD));
	LinkedNodeD ld[3];
	
	double final = 0.0;
	int v, pos = 0, aux = 2, cont = 0, opR= 0, itens = 0;
	int opInv = 0;
	
	while(entrada[pos] != '\0' && !opInv){
	    v = conversaocharInt(entrada[pos]);
	    if(v!=-1){
	        insercaoD(numeros, (double)v);
	        itens ++;
	    }else{
	        opR++;
	        if(entrada[pos] == 'h'){
	            cont = 1;
	        }else{
	            if(entrada[pos] == '+' || entrada[pos] == '-'){
	                cont = 2;
	            }else{
	                cont = 3;
	            }
	        }
	        
	        while(cont){
	            if((numeros->topo)!= NULL){
	                ld[aux] = *desalocarD(numeros);
	            }
	            
	            aux--;
	            cont--;
	            
	            if(numeros->topo == NULL && cont){
	                opInv = 1;
	                break;
	            }
	        }
	        if(entrada[pos] == 'h'){
                insercaoD(numeros, operacaoUnaria((ld[2]).val));
	        } else {
	            if(entrada[pos] == '+' || entrada[pos] == '-'){
	                insercaoD(numeros, operacaoBinaria((ld[1]).val, (ld[2]).val, entrada[pos]));
	                itens--;
	            }else {
	                insercaoD(numeros, operacaoTernaria((ld[0]).val, (ld[1]).val, (ld[2]).val, entrada[pos]));
	                itens -=2;
	            }
	        }
	    }
	    aux = 2;
	    pos++;
	}
	

    final += desalocarD(numeros)->val;

    if((!opR && itens!=1) || opInv || itens!=1){
       printf("ERRO\n"); 
    } else {
    	printf("%.2lf\n", final);
    }
    
	return 0;
}