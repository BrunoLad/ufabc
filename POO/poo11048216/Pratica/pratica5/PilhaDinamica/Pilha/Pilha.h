#include "../Item/Item.h"

class Pilha{
    private:
            Item *topo;
    public:
            Pilha();
            Pilha(Item *);
            void setTopo(Item *);
            Item *getTopo();
            void empilhar(Item *);
            void desempilhar();
            bool vazia();
            void printStack();
};