#include "../Item/Item.h"

class FilaDinamica{
    private:
            Item *inicio;
            Item *fim;
    public:
            FilaDinamica();
            FilaDinamica(Item *);
            void setInicio(Item *);
            Item *getInicio();
            void setFim(Item *);
            Item *getFim();
            void enfileirar(Item *);
            void desenfileirar();
            void imprime();
            bool vazia();
};