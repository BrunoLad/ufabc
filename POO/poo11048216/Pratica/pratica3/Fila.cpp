#include <iostream>

class Fila{
    private:
        int *itens;
        int inicio;
        int final;
        int quantidade;
        int tamanho;
    public:
        Fila();
        Fila(int);
        int getItens(int);
        void setItens(int, int);
        int getInicio();
        void setInicio(int);
        int getFinal();
        void setFinal(int);
        int getQuantidade();
        void setQuantidade(int);
        //int getTamanho();
        //void setTamanho(int);
        void enfileirar(int);
        void desinfileirar(); //não ta retornando devido ao que é pedido no problema. Retorna a fila para o estado inicial depois que remover o último
        bool cheia();
        bool vazia();
};

Fila::Fila(){
    this->setInicio(-1);
    this->setFinal(-1);
}

Fila::Fila(int t){
    this->setQuantidade(t);
    this->setInicio(-1);
    this->setFinal(-1);
    this->itens = new int[t];
}

int Fila::getItens(int ind){
    return this->itens[ind];
}

void Fila::setItens(int valor, int ind){
    this->itens[ind] = valor;
}

int Fila::getInicio(){
    return this->inicio;
}

void Fila::setInicio(int primeiro){
    this->inicio = primeiro;
}

int Fila::getFinal(){
    return this->final;
}

void Fila::setFinal(int fim){
    this->final = fim;
}

int Fila::getQuantidade(){
    return this->quantidade;
}

void Fila::setQuantidade(int q){
    this->quantidade = q;
}

/*int Fila::getTamanho(){
    return this->tamanho;
}

void Fila::setTamanho(int t){
    this->tamanho = t;
}*/

bool Fila::cheia(){
    if(this->getFinal()==(this->getQuantidade()-1)){
        return true;
    }else{
        return false;
    }
}

bool Fila::vazia(){
    if(this->getInicio()==this->getFinal()){
        return true;
    }else{
        return false;
    }
}

void Fila::enfileirar(int valor){
    if(this->getInicio()==-1){
        this->setInicio(0);
        this->setFinal(0);
        this->setItens(valor, this->getFinal());
        //this->setQuantidade(this->getQuantidade()+1);
      
    }else{
        if(!this->cheia()){
            this->setFinal(this->getFinal()+1);
            this->setItens(valor, this->getFinal());
            //this->setQuantidade(this->getQuantidade()+1);
        }
    }
}

void Fila::desinfileirar(){
    if(this->getInicio()!=-1){
        if(this->vazia()){
            std::cout << this->getItens(this->getInicio()) << std::endl;
            this->setInicio(-1);
            this->setFinal(-1);
            //this->setQuantidade(0);
        }else{
            std::cout << this->getItens(this->getInicio()) << std::endl;
            this->setInicio(this->getInicio()+1);
            //this->setQuantidade(this->getQuantidade()-1);
        }
    }
}

int main(){
    
    int N, v;
    char op;
    
    std::cin >> N;
    
    Fila f(N);
    
    while(std::cin >> op){
        switch(op){
            case 'E':
                //inserção de valor
                std::cin >> v;
                f.enfileirar(v);
                break;
            case 'D':
                //remoção de um valor
                // A cada operação de exclusão de itens da fila, o valor desenfileirado deve ser exibido.
                f.desinfileirar();
            default:
                //fins estéticos
                break;
        }
        
    }
    
    return 0;
}
//precisa ser refeito. O caso quando ta cheio é somente quando o inicio é igual ao fim, ai reseta a fila