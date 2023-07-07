#include <iostream>

class Pilha{
    private:
        int *itens;
        int topo;
        int tamanho;
    public:
        Pilha();
        Pilha(int);
        int getItens(int);
        void setItens(int, int);
        int getTopo();
        void setTopo(int);
        int getTamanho();
        void setTamanho(int);
        void empilhar(int);
        void desempilhar(); //void devido a necessidade do problema
        bool vazia();
        bool cheia();
        void printBottomUp();
        void printTopDown();
};

Pilha::Pilha(){
    this->setTopo(-1);
}

Pilha::Pilha(int t){
    this->setTamanho(t);
    this->itens = new int[t];
    this->setTopo(-1);
}

int Pilha::getItens(int ind){
    return this->itens[ind];
}

void Pilha::setItens(int valor, int ind){
    this->itens[ind] = valor;
}

int Pilha::getTopo(){
   return this->topo; 
}

void Pilha::setTopo(int v){
    this->topo = v;
}

int Pilha::getTamanho(){
    return this->tamanho;
}

void Pilha::setTamanho(int t){
    this->tamanho = t;
}

void Pilha::empilhar(int v){
    if(!this->cheia()){
        this->setItens(v,(this->getTopo()+1));
        this->setTopo(this->getTopo()+1);
    }
}

void Pilha::desempilhar(){
    if(!this->vazia() && !this->cheia()){
        //this->setItens(NULL,this->getTopo());
        this->setTopo(this->getTopo()-1);
    }else{
        this->setTopo(this->getTopo()-2);
    }
}

bool Pilha::vazia(){
    if(this->getTopo()==-1){
        return true;
    }else{
        return false;
    }
}

bool Pilha::cheia(){
    if(this->getTopo()==this->getTamanho()){
        return true;
    }else{
        return false;
    }
}

void Pilha::printBottomUp(){
    if(!this->cheia()){
        for(int i=0; i<(this->getTopo()+1); i++){
            std::cout << this->getItens(i) << std::endl;
        }
    }else{
        for(int i=0; i<this->getTamanho(); i++){
            std::cout << this->getItens(i) << std::endl;
        }
    }
}

void Pilha::printTopDown(){
    if(!this->cheia()){
        for(int i=this->getTopo(); i>-1; i--){
            std::cout << this->getItens(i) << std::endl;
        }
    }else{
         for(int i=(this->getTopo()-1); i>-1; i--){
            std::cout << this->getItens(i) << std::endl;
        }
    }
}

int main(){
    int N, v;
    char op;
    
    std::cin >> N;
    
    Pilha *p = new Pilha(N);
    
    while(std::cin >> op){
        switch(op){
            case 'E':
                std::cin >> v;
                p->empilhar(v);
                break;
            case 'T':
                p->printTopDown();
                break;
            case 'D':
                p->desempilhar();
                break;
            case 'B':
                p->printBottomUp();
                break;
            default:
                //coloquei só por fins estéticos
                break;
        }
    }
    
    return 0;
}