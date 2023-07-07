#include <iostream>
#include "Pilha.h"

Pilha::Pilha()
{   
    this->setTopo(NULL);
}

Pilha::Pilha(Item *ite){
    this->setTopo(ite);
}

void Pilha::setTopo(Item *t){
    this->topo = t;
}

Item * Pilha::getTopo(){
    return this->topo;
}

void Pilha::empilhar(Item *add){
    try{
        if(this->vazia()){
            throw PilhaVaziaException();
        }else{
            add->setProximo(this->getTopo());
            this->setTopo(add);
        }
    }
    catch(PilhaVaziaException pe){
        this->setTopo(add);
        add->setProximo(NULL);
    }
}

void Pilha::desempilhar() throw(PilhaVaziaException){
    if(this->vazia()){
        throw PilhaVaziaException();
    }else{
        Item *aux = this->getTopo();
        this->setTopo(aux->getProximo());
        std::cout << "[" << aux->getValor() << "]" << std::endl;
    }
}

void Pilha::imprime() throw(PilhaVaziaException){
    if(this->vazia()){
        throw PilhaVaziaException();
    }else{
        Item *aux = this->getTopo();
    
        while(aux!=NULL){
            std::cout << aux->getValor() << (aux->getProximo()!=NULL ? " " : "\n");
            aux = aux->getProximo();
        }
    }
}

bool Pilha::vazia() throw(PilhaVaziaException){
    if(this->getTopo()==NULL){
        throw PilhaVaziaException();
    }else{
        return false;
    }
}