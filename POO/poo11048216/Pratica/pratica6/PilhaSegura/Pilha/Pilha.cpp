#include <iostream>
#include "Pilha.h"

Pilha::Pilha(){
    this->setQuantidade(0);
    this->setTopo(-1);
}

Pilha::Pilha(int t){
    this->setQuantidade(t);
    this->setTopo(-1);
    this->itens = new int[t];
}

void Pilha::setQuantidade(int t){
    this->quantidade = t;
}

int Pilha::getQuantidade(){
    return this->quantidade;
}

void Pilha::setTopo(int tp){
    this->topo = tp;
}

int Pilha::getTopo(){
    return this->topo;
}

void Pilha::setItens(int val, int ind){
    this->itens[ind] = val;
}

int Pilha::getItens(int ind){
    return this->itens[ind];
}

void Pilha::empilhar(int v) throw(PilhaCheiaException){
    if(this->cheia()){
        throw PilhaCheiaException();
    }else{
        this->setTopo(this->getTopo()+1);
        this->setItens(v, this->getTopo());
    }
}

void Pilha::desempilhar() throw(PilhaVaziaException){
    if(this->vazia()){
        throw PilhaVaziaException();
    }else{
        this->setTopo(this->getTopo()-1);
    }
}

void Pilha::printTopDown() throw(PilhaVaziaException){
    if(this->vazia()){
        throw PilhaVaziaException();
    }else{
        for(int i = this->getTopo(); i>-1; i--){
            std::cout << this->getItens(i) << std::endl;
        }
    }
}

void Pilha::printBottomUp() throw(PilhaVaziaException){
    if(this->vazia()){
        throw PilhaVaziaException();
    }else{
        for(int i=0; i<=this->getTopo(); i++){
            std::cout << this->getItens(i) << std::endl;
        }
    }
}

bool Pilha::vazia() throw(PilhaVaziaException){
    if(this->getTopo()==-1){
        throw PilhaVaziaException();
    }else{
        return false;
    }
}

bool Pilha::cheia() throw(PilhaCheiaException){
    if(this->getTopo()==(this->getQuantidade()-1)){
        throw PilhaCheiaException();
    }else{
        return false;
    }
}