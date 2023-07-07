#include "../DataExceptions/DataExceptions.h"

class Data{
    private:
            int ano;
            int mes;
            int dia;
    public:
            Data();
            Data(int,int,int) throw(DataInvalidaException);
            void setAno(int);
            int getAno() const;
            void setMes(int);
            int getMes() const;
            void setDia(int);
            int getDia() const;
            bool isBissexto();
};