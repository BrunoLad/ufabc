class Data{
    private:
            int ano;
            int mes;
            int dia;
    public:
            Data();
            Data(int,int,int);
            void setAno(int);
            int getAno() const;
            void setMes(int);
            int getMes() const;
            void setDia(int);
            int getDia() const;
            Data operator ++();
            Data operator ++(int);
            void imprime() const;
            bool isBissexto(int);
};