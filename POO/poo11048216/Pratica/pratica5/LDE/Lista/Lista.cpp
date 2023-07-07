#include "Lista.h"
#include <iostream>

LDE::LDE(){
    this->setInicio(NULL);
}

LDE::LDE(Item *pi){
    this->setInicio(pi);
}

void LDE::setInicio(Item *pi){
    this->inicio = pi;
}

Item* LDE::getInicio(){
    return this->inicio;
}

void LDE::inclusao(Item *pi){
    if(this->vazia()){
        this->setInicio(pi);
        (this->getInicio())->setProximo(NULL);
    }else{
        if(!this->busca(pi->getValor())){
            
            Item *aux = this->getInicio();
            
            if(aux->getValor() > pi->getValor()){
                pi->setProximo(aux);
                this->setInicio(pi);
            }else{
                bool inserido = false;
                while(aux->getProximo()!=NULL){
                    if((aux->getProximo())->getValor() > pi->getValor()){
                        pi->setProximo(aux->getProximo());
                        aux->setProximo(pi);
                        inserido = true;
                        break;
                    }else{
                        aux = aux->getProximo();
                    }
                }
                
                if(!inserido){
                    aux->setProximo(pi);
                    pi->setProximo(NULL);
                }
            }
        }
    }
}


void LDE::exclusao(int v){
    if(!this->vazia()){
        Item *aux = this->getInicio();
        if(aux->getValor()==v){
            this->setInicio(aux->getProximo());
        }else{
            while(aux->getProximo()!=NULL){
                if((aux->getProximo())->getValor()==v){
                    aux->setProximo((aux->getProximo())->getProximo());
                    break;
                }else{
                    aux = aux->getProximo();
                }
            }
        }
    }
}

bool LDE::busca(int v){
    Item *aux = this->getInicio();
    while(aux!=NULL){
        if(aux->getValor()==v){
            return true;
        }else{
            aux = aux->getProximo();
        }
    }
    return false;
}

void LDE::imprime(){
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

bool LDE::vazia(){
    if(this->getInicio()==NULL){
        return true;
    }else{
        return false;
    }
}