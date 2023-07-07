#include <stdio.h>
#include <math.h>

typedef struct posicao{
    float x;
    float y;
    float z;
} posicao;

float distancia(posicao *p1, posicao *p2);

int main() {
    posicao p1;
    posicao p2;
    
    scanf("%f, %f, %f", &(p1.x), &(p1.y), &(p1.z));
    scanf("%f, %f, %f", &(p2.x), &(p2.y), &(p2.z));
    
    printf("%.2f\n", distancia(&p1, &p2));
        
    return 0;
}

float distancia(posicao *p1, posicao *p2)
{
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
}