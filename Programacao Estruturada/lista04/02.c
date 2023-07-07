#include <stdio.h>

typedef struct cronometro{
    int minutos;
    int segundos;
    int decimos;
} cronometro;

cronometro * diferenca_tempo(cronometro *c1, cronometro *c2);

int main() {
    
    cronometro c1;
    cronometro c2;
    
    scanf("%dm %ds %d", &(c1.minutos), &(c1.segundos), &(c1.decimos));
    scanf("%dm %ds %d", &(c2.minutos), &(c2.segundos), &(c2.decimos));
    
    cronometro *c3 = diferenca_tempo(&c1, &c2);
    
    printf("%dm %ds %d\n", c3->minutos, c3->segundos, c3->decimos);
    
    return 0;
}

cronometro * diferenca_tempo(cronometro *c1, cronometro *c2)
{
    cronometro *c3;
    if (c1->minutos > c2->minutos) {
        c3 = c1;
        c3->decimos -= c2->decimos;
        if(c3->decimos < 0){
            c3->decimos += 100;
            --(c3->segundos);
        }
        
        c3->segundos -= c2->segundos;
        if(c3->segundos < 0){
            c3->segundos += 60;
            --(c3->minutos);
        }
        
        c3->minutos -= c2->minutos;
    } else {
        c3 = c2;
        c3->decimos -= c1->decimos;
        if(c3->decimos < 0){
            c3->decimos += 100;
            --(c3->segundos);
        }
        
        c3->segundos -= c1->segundos;
        if(c3->segundos < 0){
            c3->segundos += 60;
            --(c3->minutos);
        }
        
        c3->minutos -= c1->minutos;
    }
    
    return c3;
}