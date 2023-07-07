#include <iostream>

struct Data{
    int dia, mes, ano;
};

struct Aluno{
    std::string nome;
    std::string matricula;
    struct Data nascimento;
    float notas[3];
};

void ordenaAlunosNota(struct Aluno *, int);
void ordenaSelecao(struct Aluno *, int);
void ordenaInsercao(struct Aluno *, int);
float calcMedia(float *);
int buscaMaior(struct Aluno *, int, int);

int main(){
    int n;
    struct Aluno *Classe;
    
    std::cin >> n;
    
    Classe = new Aluno[n];
    
    for(int i=0; i<n; i++){
        std::cin >> Classe[i].nome;
        std::cin >> Classe[i].matricula;
        std::cin >> Classe[i].nascimento.dia;
        std::cin >> Classe[i].nascimento.mes;
        std::cin >> Classe[i].nascimento.ano;
        std::cin >> Classe[i].notas[0];
        std::cin >> Classe[i].notas[1];
        std::cin >> Classe[i].notas[2];
    }
    
    ordenaInsercao(Classe, n);
    
    
    for(int i=0; i<n; i++){
        std::cout << Classe[i].nome << std::endl;
        std::cout << Classe[i].matricula << std::endl;
        std::cout << calcMedia(Classe[i].notas) << std::endl;
    }
    
    return 0;
}

void ordenaAlunosNota(struct Aluno *turma, int n){
    struct Aluno aux;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(calcMedia(turma[j].notas) < calcMedia(turma[j+1].notas)){
                aux = turma[j+1];
                turma[j+1] = turma[j];
                turma[j] = aux;
            }
        }
    }
}

void ordenaInsercao(struct Aluno *turma, int n){
    struct Aluno aux;
    
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(calcMedia(turma[j].notas)>calcMedia(turma[j-1].notas)){
                aux = turma[j];
                turma[j] = turma[j-1];
                turma[j-1] = aux;
            }else{
                break;
            }
        }
    }
}

void ordenaSelecao(struct Aluno *turma, int n){
    struct Aluno aux;
    int indice = 0;
    
    for(int i=0; i<n; i++){
        
        indice = buscaMaior(turma, n, i);
        
        aux = turma[indice];
        turma[indice] = turma[i];
        turma[i] = aux;
    }
   
}

float calcMedia(float *notas){
    return (notas[0]+notas[1]+notas[2])/3.0f;
}

int buscaMaior(struct Aluno *turma, int n, int i){
    int max = calcMedia(turma[i].notas);
    int indice = i;
    
    for(int j=i+1; j<n; j++){
        if(calcMedia(turma[j].notas)> max){
            max = calcMedia(turma[j].notas);
            indice = j;
        }
    }
    
    return indice;
}