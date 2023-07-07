class Relogio{
    private:
            int hora;
            int minuto;
            int segundo;
    public:
            Relogio();
            Relogio(int,int,int);
            void setHora(int);
            int getHora() const;
            void setMinuto(int);
            int getMinuto() const;
            void setSegundo(int);
            int getSegundo() const;
            Relogio operator ++();
            Relogio operator ++(int);
            void incrementaMinuto();
            void incrementaHora();
            void imprime() const; 
};