#include <stdio.h>
#include <stdlib.h>

int * soma_vetor(int *v1, int *v2);

int main()
{
    int v1[5];
    int v2[5];
    int *aux;
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &v1[i]);
    }
    for (int i = 0; i < 5; i++) {
        scanf("%d", &v2[i]);
    }
    
    aux = soma_vetor(v1, v2);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(aux));
        aux++;
    }
    
    return 0;    
}

int * soma_vetor(int *v1, int *v2)
{
    int *v3 = malloc(5*sizeof(int));
    int *temp = v3;
    
    for (int i = 0; i < 5; i++) {
        *v3 = *v2 + *v1;
        v1++;
        v2++;
        v3++;
    }
    
    v3 = temp;
    
    return v3;
}