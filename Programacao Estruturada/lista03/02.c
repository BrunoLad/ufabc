#include <stdio.h>
#include <stdlib.h>

char * inverte_string(char *str);

int main()
{
    char entrada[255];
    fgets(entrada, 255, stdin);
    
    printf("%s\n", inverte_string(entrada));
    
    return 0;
}

//um jeito mais fácil ainda é criar um ponteiro de ponteiro de char e guarda as posições de tras pra frente
char * inverte_string(char *str)
{
    char *dupl;
    char *aux;
    int len = 0;

    while ((*str)!='\0') {
        len++;
        str++;
    }
    
    len++;
    
    dupl = malloc(len*sizeof(char));
    aux = dupl;
    str--;
    
    for (int i=0; i<(len-1); i++) {
        *dupl = *str;
        str--;
        dupl++;
    }
    
    (*dupl) = '\0';
    dupl = aux;
    return dupl;
}