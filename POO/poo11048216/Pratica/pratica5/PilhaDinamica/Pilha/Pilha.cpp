#include <iostream>
#include "Pilha.h"

Pilha::Pilha(){
    this->setTopo(NULL);
}

Pilha::Pilha(Item *pt){
    this->setTopo(pt);
}

void Pilha::setTopo(Item *pt){
    this->topo = pt;
}

Item* Pilha::getTopo(){
    return this->topo;
}

void Pilha::empilhar(Item *pt){
    if(this->vazia()){
        this->setTopo(pt);
    }else{
        Item *aux;
        aux = this->getTopo();
        pt->setProximo(aux);
        this->setTopo(pt);
    }
}

void Pilha::desempilhar(){
    if(!this->vazia()){
        Item *pt = this->getTopo();
        this->setTopo(pt->getProximo());
        std::cout << "[" << pt->getValor() << "]" << std::endl;
    }
}

bool Pilha::vazia(){
    if(this->getTopo()==NULL){
        return true;
    }else{
        return false;
    }
}

void Pilha::printStack(){
    if(!this->vazia()){
        Item *aux = this->getTopo();
    
        while(aux!=NULL){
            if(aux->getProximo()==NULL){
                std::cout << aux->getValor();
            }else{
                std::cout << aux->getValor() << " ";
            }
            aux = aux->getProximo();
        }
        std::cout << std::endl;
    }
}