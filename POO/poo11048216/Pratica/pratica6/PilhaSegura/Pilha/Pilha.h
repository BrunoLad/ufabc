#include "../PilhaExceptions/PilhaExceptions.h"

class Pilha{
    private:
            int quantidade;
            int topo;
            int *itens;
    public:
            Pilha();
            Pilha(int);
            void setQuantidade(int);
            int getQuantidade();
            void setTopo(int);
            int getTopo();
            void setItens(int,int);
            int getItens(int);
            void empilhar(int) throw(PilhaCheiaException);
            void desempilhar() throw(PilhaVaziaException);
            void printTopDown() throw(PilhaVaziaException);
            void printBottomUp() throw(PilhaVaziaException);
            bool vazia() throw(PilhaVaziaException);
            bool cheia() throw(PilhaCheiaException);
};