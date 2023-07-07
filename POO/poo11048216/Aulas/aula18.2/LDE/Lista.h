#include "Item.h"
#include "ListaExceptions.h"

class Lista
{
    private:
            Item *primeiro;
            Item *ultimo;
    public:
            Lista();
            void setPrimeiro(Item *);
            void setUltimo(Item *);
            Item * getPrimeiro();
            Item * getUltimo();
            
            void inserir(Item *) throw(ChaveExistenteException);
            Item * remover(int) throw (ChaveInexistenteException, ListaVaziaException);
            void mostrar() throw (ListaVaziaException);
            bool vazia() throw (ListaVaziaException);
};