#include <iostream>

class Item
{
    private:
            int chave;
            Item * proximo;
    public:
            Item();
            Item(int);
            void setChave(int);
            void setProximo(Item *);
            int getChave();
            Item * getProximo();
};