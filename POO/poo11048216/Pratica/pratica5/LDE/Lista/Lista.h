#include "../Item/Item.h"

class LDE{
    private:
            Item *inicio;
    public:
            LDE();
            LDE(Item *);
            void setInicio(Item *);
            Item* getInicio();
            void inclusao(Item *);
            void exclusao(int);
            bool busca(int);
            void imprime();
            bool vazia();
};
