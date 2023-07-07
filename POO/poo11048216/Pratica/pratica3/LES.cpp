#include <iostream>

class Lista{
    private:
        int *itens;
        int tamanho;
        int quantidade;
    
    public:
        Lista(int);
        void setTamanho(int);
        void setQuantidade(int);
        void setItens(int, int);
        int getTamanho();
        int getQuantidade();
        int getItens(int);
        void inserir(int);
        int busca(int);
        void remover(int);
        void mostra();
        bool cheia();
        bool vazia();
        
};

Lista::Lista(int tamanho){
    this->setTamanho(tamanho);
    this->itens = new int[tamanho];
    this->setQuantidade(0);
}

void Lista::setTamanho(int t){
    this->tamanho = t;
}

void Lista::setQuantidade(int q){
    this->quantidade = q;
}

void Lista::setItens(int valor, int indice){
    this->itens[indice] = valor;
}

int Lista::getTamanho(){
    return this->tamanho;
}

int Lista::getQuantidade(){
    return this->quantidade;
}

int Lista::getItens(int ind){
    return this->itens[ind];
}

bool Lista::cheia(){
    if(this->getQuantidade()==(this->getTamanho()-1)){
        return true;
    }else{
        return false;
    }
}

bool Lista::vazia(){
    if(this->getQuantidade()==0){
        return true;
    }else{
        return false;
    }
}

void Lista::mostra(){
    for(int i=0; i<this->getQuantidade(); i++){
        std::cout << this->getItens(i) << std::endl;
    }
}

int Lista::busca(int valor){
    //int pos;
    
    /*while(1){
        pos = (this->getQuantidade())/2;
        
        if(this->getItens(pos)==valor){
            return pos;
        }else{
            if(this->getItens(pos)>valor){
                pos = (pos+this->getQuantidade())/2;
            }else{
                pos/=2;
            }
            
        }
        
        //std::cout << "teste" << std::endl;
        
        if(pos==0 || pos>=(this->getQuantidade()-1)){
            //ac=1;
            return -1;
        }
    }*/
    
    for(int i=0; i<this->getQuantidade(); i++){
        if(this->getItens(i)==valor){
            return i;
        }
    }
    return -1;
}

void Lista::inserir(int valor){
    int aux, posi=-1, aux2;
    
    if(!this->cheia()){
    
        if(this->vazia()){
            this->setItens(valor, 0);
            this->setQuantidade(this->getQuantidade()+1);
        }else{
            if(this->busca(valor)==-1){
                for(int i=0; i<this->getQuantidade(); i++){
                    if(valor < this->getItens(i)){
                        aux = this->getItens(i);
                        this->setItens(valor, i);
                        this->setQuantidade(this->getQuantidade()+1);
                        posi = i+1;
                        break;
                    }
                }
                
                if(posi==-1){
                    this->setItens(valor,quantidade);
                    this->setQuantidade(this->getQuantidade()+1);
                }else{
                
                    for(int i=posi; i <= this->getQuantidade(); i++){
                        aux2=aux;
                        aux=this->getItens(i);
                        this->setItens(aux2,i);
                    }
                }
            }
        }
    }
}

void Lista::remover(int valor){
    int pos, aux;
    
    if(!this->vazia()){
        if(this->busca(valor)!=-1){
            pos = this->busca(valor);
            
            for(int i=pos; i<(this->getQuantidade()-1); i++){
                this->setItens(this->getItens(i+1),i);
            }
            
            this->setQuantidade(this->getQuantidade()-1);
        }
    }
}

int main(){
    
    int q;
    
    std::cin >> q;
    
    Lista *l = new Lista(q);
    
    for(int i=0; i<q; i++){
        int n;
        char op;
        
        std::cin >> op >> n;
        //std::cout << "teste" << std::endl;
        
        if(op=='I'){
            l->inserir(n);
        }else{
            if(op=='E'){
                l->remover(n);
            }
        }
    }
    
    l->mostra();
    
    return 0;
}