#include "../Watch/Watch.h"
#include "../Data/Data.h"

class DataPrecisa : public Watch, public Data{
    public:
            DataPrecisa();
            DataPrecisa(int,int,int,int,int,int,bool);
            DataPrecisa(Data);
            DataPrecisa(Data,Watch);
            DataPrecisa operator ++();
            DataPrecisa operator ++(int);
            void imprime() const;
};