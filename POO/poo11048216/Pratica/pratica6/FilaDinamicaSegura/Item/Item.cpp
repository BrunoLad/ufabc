#include "Item.h"

Item::Item()
{   }

Item::Item(int v){
    this->setValor(v);
}

void Item::setValor(int v){
    this->valor = v;
}

int Item::getValor(){
    return this->valor;
}

void Item::setProximo(Item *it){
    this->proximo = it;
}

Item * Item::getProximo(){
    return this->proximo;
}