#include <iostream>
#include "Fila.h"

Fila::Fila()
{   
    this->setInicio(NULL);
    this->setFim(NULL);
}

Fila::Fila(Item *it){
    this->setInicio(it);
    (this->getInicio())->setProximo(NULL);
    this->setFim(it);
}

void Fila::setInicio(Item *ini){
    this->inicio = ini;
}

Item * Fila::getInicio(){
    return this->inicio;
}

void Fila::setFim(Item *fi){
    this->fim = fi;
}

Item * Fila::getFim(){
    return this->fim;
}

void Fila::enfileirar(Item *add){
    if(this->vazia()){
        this->setInicio(add);
        (this->getInicio())->setProximo(NULL);
        this->setFim(add);
    }else{
      if((this->getInicio())->getProximo()==NULL){
            (this->getInicio())->setProximo(add);
            this->setFim(add);
            (this->getFim())->setProximo(NULL);
        }else{
            (this->getFim())->setProximo(add);
            this->setFim(add);
            (this->getFim())->setProximo(NULL);
        }
    }
}

void Fila::desenfileirar() throw(FilaVaziaException){
    if(this->vazia()){
        throw FilaVaziaException();
    }else{
        std::cout << "<" << (this->getInicio())->getValor() << ">" << std::endl;
        this->setInicio((this->getInicio())->getProximo());
    }
}

void Fila::imprime() throw(FilaVaziaException){
    if(this->vazia()){
        throw FilaVaziaException();
    }else{
        Item *aux = this->getInicio();
    
        while(aux!=NULL){
            if(aux->getProximo()==NULL){
                std::cout << aux->getValor() << std::endl;
            }else{
                std::cout << aux->getValor() << " ";
            }
            aux = aux->getProximo();
        }
    }
}

bool Fila::vazia(){
    if(this->getInicio()==NULL){
        return true;
    }else{
        return false;
    }
}// seria mais interessante ter colocado a exception aqui.