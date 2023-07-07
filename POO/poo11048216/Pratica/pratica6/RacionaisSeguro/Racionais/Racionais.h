#include "../RacionaisException/RacionaisException.h"

class Racionais{
    private:
            int numerador;
            int denominador;
    public:
            Racionais();
            Racionais(int,int) throw(DenominadorZeroException);
            void setNumerador(int);
            int getNumerador();
            void setDenominador(int);
            int getDenominador();
            void oposto(); //dá o equivalente negativo
            void inverso(); // dá a recíproca
            void simplifica();
            Racionais operator +(Racionais);
            Racionais operator *(Racionais);
            void imprime();
};