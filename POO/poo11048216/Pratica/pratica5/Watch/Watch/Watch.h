class Watch{
    private:
            int hora;
            int minuto;
            int segundo;
            bool AM;
    public:
            Watch();
            Watch(int,int,int, std::string);
            void setHora(int);
            int getHora() const;
            void setMinuto(int);
            int getMinuto() const;
            void setSegundo(int);
            int getSegundo() const;
            void setAM(bool);
            bool isAM() const;
            Watch operator ++();
            Watch operator ++(int);
            void incrementaMinuto();
            void incrementaHora();
            void imprime() const;
};