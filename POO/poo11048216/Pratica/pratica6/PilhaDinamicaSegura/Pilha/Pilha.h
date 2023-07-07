#include "../Item/Item.h"
#include "../PilhaExceptions/PilhaExceptions.h"

class Pilha{
    private:
            Item *topo;
    public:
            Pilha();
            Pilha(Item *);
            void setTopo(Item *);
            Item * getTopo();
            void empilhar(Item *);
            void desempilhar() throw(PilhaVaziaException);
            void imprime() throw(PilhaVaziaException);
            bool vazia() throw(PilhaVaziaException);
};