#include <stdio.h>
#include <math.h>

//assinatura das funções
float to_fahrenheit(int op, float v);
float to_kelvin(int op, float v);
float to_celsius(int op, float v);
int to_binario(int op, int v);
int to_decimal(int op, int v);

int main(){

	int op, ent, sai;
	float valor;
	scanf("%d", &op);
	scanf("%d", &ent);
	scanf("%d", &sai);
	scanf("%f", &valor);

	if(op==1){
		if(sai==1){
			printf("%.2f C\n", to_celsius(ent, valor));
		}else{
			if(sai==2){
				printf("%.2f F\n", to_fahrenheit(ent, valor));
			}else{
				printf("%.2f K\n", to_kelvin(ent, valor));
			}
		}
	}else{
		if(sai==1){
			printf("%d\n", to_decimal(ent, valor));
		}else{
			printf("%d\n", to_binario(ent, valor));
		}
	}


	return 0;
}

//verifica em qual escala estava a temperatura 
//anterior e faz a conversao
float to_fahrenheit(int op, float v){
	if(op==2){
		return v;
	}else{
		if(op==1){
			return (v * (9/5.0f)) + 32;
		}else{
			return ((v-273.15f) * (9.0f/5)) + 32;
		}
	}
}

//verifica em qual escala estava a temperatura 
//anterior e faz a conversao
float to_celsius(int op, float v){
	if(op==1){
		return v;
	}else{
		if(op==2){
			return ((v-32)/9)*5.0f;
		}else{
			return v - 273.15f;
		}
	}
}

//verifica em qual escala estava a temperatura 
//anterior e faz a conversao
float to_kelvin(int op, float v){
	if(op==3){
		return v;
	}else{
		if(op==1){
			return v + 273.15;
		}else{
			return (((v-32)/9)*5.0f) + 273.15f;
		}
	}
}

int to_binario(int op, int v){
	if(op==2){
		return v;
	}
	
	int resu = 0;
	int ind = 1;

	while(v){
		resu += (ind*(v%2));
		v/=2;
		ind*=10;
	}

	return resu;

}

int to_decimal(int op, int v){
	if(op==1){
		return v;
	}

	int resu = 0;
	int ind = 0;

	while(v){
		resu = resu + ((v%10)*pow(2, ind));
		v/=10;
		ind++;
	}

	return resu;
}