#include <stdio.h>
#include <stdlib.h>

int ** transposta(int **m);

int main()
{
    int m[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int **transp = transposta(m);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", **m);
            m++;
        }
        printf("\n");
    }
    
    return 0;
}

int ** transposta(int **m)
{
    int **mT = malloc(3*sizeof(int*));
    
    for (int i=0; i < 3; i++) {
        mT[i] = malloc(3*sizeof(int));
    }
    
    int **aux = mT;
    
    for(int i=0; i < 3; i++){
        for(int j = 1; j <= 2; j++){
            **mT = **m;
            mT++;
            m += (j*3);
        }
        mT = mT - 6 + 1;
    }
    mT = aux;
    
    return mT;
}