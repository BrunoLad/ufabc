class Item{
    private:
            int valor;
            Item *proximo;
    public:
            Item();
            Item(int);
            void setValor(int);
            int getValor();
            void setProximo(Item *);
            Item * getProximo();
};