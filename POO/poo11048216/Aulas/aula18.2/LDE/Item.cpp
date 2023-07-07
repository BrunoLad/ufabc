#include "Item.h"

Item::Item()
{   }

Item::Item(int ch)
{
    this->setChave(ch);
    this->setProximo(NULL);
}

void Item::setChave(int ch)
{
    this->chave = ch;
}

void Item::setProximo(Item *it)
{
    this->proximo = it;
}

int Item::getChave()
{
    return this->chave;
}

Item * Item::getProximo()
{
    return this->proximo;
}