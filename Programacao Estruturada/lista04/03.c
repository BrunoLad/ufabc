#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    float p1;
    float p2;
    float p3;
    float media;
    char nome[100];
} aluno;

float media_notas(aluno *a);

int main() {
    
    FILE * fp = fopen("lista_alunos.txt", "r");
    aluno alunos[50];
    
    int i = 0;
    
    while (i < 50) {
        fscanf(fp, "\%s \%d \%f \%f %f",
                    alunos[i].nome, &alunos[i].matricula, 
                    &alunos[i].p1, &alunos[i].p2, &alunos[i].p3);
        i++;
    }    
    
    fclose(fp);
    fp = fopen("media_alunos.txt", "w");
    i = 0;
    
    while (i < 50) {
        alunos[i].media = media_notas(alunos + i);
        
        fprintf(fp, "\%s \%d \%.2f \%.2f \%.2f \%.2f\n",
                alunos[i].nome, alunos[i].matricula,
                alunos[i].p1, alunos[i].p2, alunos[i].p3,
                alunos[i].media);
        i++;
    }
    fclose(fp);
    return 0;
}

float media_notas(aluno *a)
{
    return (a->p1 + a->p2 + a->p3)/3.0;
}