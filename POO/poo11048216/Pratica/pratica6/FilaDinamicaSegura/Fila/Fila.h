#include "../Item/Item.h"
#include "../FilaException/FilaException.h"

class Fila{
    private:
            Item *inicio;
            Item *fim;
    public:
            Fila();
            Fila(Item *);
            void setInicio(Item *);
            Item * getInicio();
            void setFim(Item *);
            Item * getFim();
            void enfileirar(Item *);
            void desenfileirar() throw(FilaVaziaException);
            void imprime() throw(FilaVaziaException);
            bool vazia();
};