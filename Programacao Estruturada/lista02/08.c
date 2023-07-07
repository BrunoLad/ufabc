#include <stdio.h>

double calcula_desconto(int dias_f, double salario_base);
double calcula_acrescimo(int hr_ex, double salario_base);
double salario_final(int car, int dias_f, int hr_ex);

int main(){
    int car, dias_f, hr_ex;
    scanf("%d", &car);
    scanf("%d", &dias_f);
    scanf("%d", &hr_ex);
    
    printf("%.2lf\n", salario_final(car, dias_f, hr_ex));
    
    return 0;
}

//retorna o desconto com base nos dias faltados
double calcula_desconto(int dias_f, double salario_base){
    return salario_base * (dias_f/20.0f);
}

//retorna o acrescimo com base nas horas extras trabalhadas
double calcula_acrescimo(int hr_ex, double salario_base){
    return ((salario_base/(8 * 20.0f)) + 40) * hr_ex;
}

//calcula o salario final com base nos acrescimos e descontos
double salario_final(int car, int dias_f, int hr_ex){
    switch(car){
        case 1:
            return 10000.0f - calcula_desconto(dias_f, 10000.0f) + calcula_acrescimo(hr_ex, 10000.0f);
            break;
        case 2:
            return 8000.0f - calcula_desconto(dias_f, 8000.0f) + calcula_acrescimo(hr_ex, 8000.0f);
            break;
        case 3:
            return 5000.0f - calcula_desconto(dias_f, 5000.0f) + calcula_acrescimo(hr_ex, 5000.0f);
            break;
        case 4:
            return 3000.0f - calcula_desconto(dias_f, 3000.0f) + calcula_acrescimo(hr_ex, 3000.0f);
            break;
        case 5:
            return 2000.0f - calcula_desconto(dias_f, 2000.0f) + calcula_acrescimo(hr_ex, 2000.0f);
            break;
        default:
            //apenas para fins estéticos
            return 0.0;
            break;
    }
}