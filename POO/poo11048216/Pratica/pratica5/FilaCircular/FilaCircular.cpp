#include <iostream>

class FilaCircular{
    private:
            int *itens;
            int tamanho;
            int inicio;
            int fim;
    public:
            FilaCircular();
            FilaCircular(int);
            void setItens(int,int);
            int getItens(int);
            void setTamanho(int);
            int getTamanho();
            void setInicio(int);
            int getInicio();
            void setFim(int);
            int getFim();
            void enfileirar(int);
            void desenfileirar();
            bool vazia();
            bool cheia();
};

FilaCircular::FilaCircular(){
    this->setTamanho(0);
    this->setInicio(-1);
    this->setFim(-1);
}

FilaCircular::FilaCircular(int tam){
    this->setTamanho(tam);
    this->itens = new int[tam];
    this->setInicio(-1);
    this->setFim(-1);
}

void FilaCircular::setItens(int v, int ind){
    this->itens[ind] = v;
}

int FilaCircular::getItens(int ind){
    return this->itens[ind];
}

void FilaCircular::setTamanho(int tam){
    this->tamanho = tam;
}

int FilaCircular::getTamanho(){
    return this->tamanho;
}

void FilaCircular::setInicio(int ini){
    this->inicio = ini;
}

int FilaCircular::getInicio(){
    return this->inicio;
}

void FilaCircular::setFim(int f){
    this->fim = f;
}

int FilaCircular::getFim(){
    return this->fim;
}

void FilaCircular::enfileirar(int v){
    if(this->vazia()){
        this->setInicio(0);
        this->setFim(0);
        this->setItens(v,this->getFim());
    }else{
        if(!this->cheia()){
            if(this->getFim()==(this->getTamanho()-1)){
                this->setFim(-1);
                this->setFim(this->getFim()+1);
                this->setItens(v,this->getFim());
            }else{
                this->setFim(this->getFim()+1);
                this->setItens(v, this->getFim());
            }
        }
    }
}

void FilaCircular::desenfileirar(){
    int v;
    if(!this->vazia()){
        v = this->getItens(this->getInicio());
        
        this->setInicio(this->getInicio()+1);
        
        if(this->getInicio()==this->getTamanho()){
            this->setInicio(0);
        }
        
        if(this->getInicio()==(this->getFim()+1)){
                this->setInicio(-1);
                this->setFim(-1);
        }
        
        std::cout << v << std::endl;
    }
}

bool FilaCircular::vazia(){
    if(this->getInicio()==-1 && this->getFim()==-1){
        return true;
    }else{
        return false;
    }
}

bool FilaCircular::cheia(){
    if((this->getFim()==(this->getTamanho()-1) && this->getInicio()==0) || (this->getFim()==(this->getInicio()-1))){
        return true;
    }else{
        return false; 
    }
}

int main(){
    char op;
    int t, v;
    
    std::cin >> t;
    
    FilaCircular fc(t);
    
    while(std::cin >> op){
        switch(op){
            case 'E':
                std::cin >> v;
                fc.enfileirar(v);
                break;
            case 'D':
                fc.desenfileirar();
                break;
            default:
                break;
        }
    }
    
    return 0;
}
//as entradas do FilaCircular e da DataPrecisa12 só podem estar erradas
//a filacircular ta implementada do mesmo jeito que foi recomendado num site (igualzinho as verificações e tudo)
