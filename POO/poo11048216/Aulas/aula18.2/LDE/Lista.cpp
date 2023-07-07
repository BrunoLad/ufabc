#include "Lista.h"

Lista::Lista()
{
    this->setPrimeiro(NULL);
    this->setUltimo(NULL);
}

void Lista::setPrimeiro(Item *it)
{
    this->primeiro = it;
}

void Lista::setUltimo(Item *it)
{
    this->ultimo = it;
}

Item * Lista::getPrimeiro()
{
    return this->primeiro;
}

Item * Lista::getUltimo()
{
    return this->ultimo;
}


void Lista::inserir(Item *novo) throw (ChaveExistenteException)
{
    Item *ant=NULL, *atu=this->getPrimeiro();
    bool achei = false;

    try
    {
        if(!this->vazia())
        {
        
            while(atu!=NULL && !achei)
            {
                if(atu->getChave() < novo->getChave())
                {
                    ant = atu;
                    atu = atu->getProximo();
                }
                else
                {
                    achei = true;
                }
            }
            if(atu!=NULL && atu->getChave() == novo->getChave())
            {
                delete novo;
                throw ChaveExistenteException();
            }
            else
            {
                if(ant==NULL) // eh o primeiro
                {
                    novo->setProximo(atu);
                    this->setPrimeiro(novo);
                    
                }
                else if(atu==NULL) // eh o ultimo
                {
                    ant->setProximo(novo);
                    this->setUltimo(novo);
                }
                else // eh o do meio
                {
                    ant->setProximo(novo);
                    novo->setProximo(atu);
                }
            }
        }
    }
    catch(ListaVaziaException lve)
    {
        this->setPrimeiro(novo);
        this->setUltimo(novo);
    }
}

Item * Lista::remover(int ch) throw(ListaVaziaException, ChaveInexistenteException)
{
    Item *ant = NULL, *atu = this->getPrimeiro();
    
    if(!this->vazia())
    {
        while(atu!=NULL && atu->getChave() != ch)
        {
            ant = atu;
            atu = atu->getProximo();
        }
        if(atu!=NULL) // encontrei
        {
            if(ant!=NULL) // eh meio ou ultimo
            {
                ant->setProximo(atu->getProximo());
                if(atu == this->getUltimo())
                {
                    this->setUltimo(ant);
                }
            }
            else // eh primeiro 
            {
                this->setPrimeiro(atu->getProximo());
                if(this->getPrimeiro() == NULL)
                {
                    this->setUltimo(NULL);
                }
            }
        }
        else
        {
            throw ChaveInexistenteException();
        }
    }
    return atu;
}

void Lista::mostrar() throw (ListaVaziaException)
{
    Item *atu=this->getPrimeiro();
    if(!this->vazia())
    {
        while(atu!=NULL)
        {
            std::cout << atu->getChave() << (atu->getProximo()!=NULL?" ":"\n");
            atu = atu->getProximo();
        }
    }
}

bool Lista::vazia() throw (ListaVaziaException)
{
    if(this->getPrimeiro() == NULL && this->getUltimo() == NULL)
    {
        throw ListaVaziaException();
    }
    else
    {
        return false;
    }
}