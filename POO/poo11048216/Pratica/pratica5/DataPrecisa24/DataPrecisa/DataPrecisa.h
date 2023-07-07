#include "../Relogio/Relogio.h"
#include "../Data/Data.h"

class DataPrecisa : public Relogio, public Data{
    public:
            DataPrecisa();
            DataPrecisa(int,int,int,int,int,int);
            DataPrecisa(Data);
            DataPrecisa(Data,Relogio);
            DataPrecisa operator ++();
            DataPrecisa operator ++(int);
            void imprime() const;
};