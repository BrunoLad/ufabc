#include "Fila.h"
#include <iostream>

FilaDinamica::FilaDinamica(){
    this->setInicio(NULL);
    this->setFim(NULL);
}

FilaDinamica::FilaDinamica(Item *pi){
    this->setInicio(pi);
    (this->getInicio())->setProximo(NULL);
    this->setFim(pi);
}

void FilaDinamica::setInicio(Item *pi){
    this->inicio = pi;
}

Item* FilaDinamica::getInicio(){
    return this->inicio;
}

void FilaDinamica::setFim(Item *pf){
    this->fim = pf;
}

Item* FilaDinamica::getFim(){
    return this->fim;
}

void FilaDinamica::enfileirar(Item *pi){
    if(this->vazia()){
        this->setInicio(pi);
        (this->getInicio())->setProximo(pi);
        this->setFim(pi);
    }else{
        if((this->getInicio())->getProximo()==NULL){
            this->setFim(pi);
            (this->getInicio())->setProximo(pi);
            (this->getFim())->setProximo(NULL);
        }else{
            (this->getFim())->setProximo(pi);
            this->setFim(pi);
            (this->getFim())->setProximo(NULL);
        }
        
    }
}

void FilaDinamica::desenfileirar(){
    if(!this->vazia()){
        Item *aux = this->getInicio();
        this->setInicio(aux->getProximo());
        
        std::cout << "<" << aux->getValor() << ">" << std::endl;
    }
}

void FilaDinamica::imprime(){
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

bool FilaDinamica::vazia(){
    if(this->getInicio()==NULL){
        return true;
    }else{
        return false;
    }
}