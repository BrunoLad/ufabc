#include <iostream>
#include <stdexcept>

class DataEHoraInvalidas : public std::logic_error{
    public:
            DataEHoraInvalidas();
};

class DataInvalida : public std::logic_error{
    public:
            DataInvalida();
};

class HoraInvalida : public std::logic_error{
    public:
            HoraInvalida();
};

class Watch{
    private:
            int hora;
            int minuto;
            int segundo;
            bool AM;
    public:
            Watch();
            Watch(int,int,int,bool) throw(HoraInvalida);
            void setHora(int);
            int getHora() const;
            void setMinuto(int);
            int getMinuto() const;
            void setSegundo(int);
            int getSegundo() const;
            void setAM(bool);
            bool isAM() const;
};

class Data{
    private:
            int ano;
            int mes;
            int dia;
    public:
            Data();
            Data(int,int,int) throw(DataInvalida);
            void setAno(int);
            int getAno() const;
            void setMes(int);
            int getMes() const;
            void setDia(int);
            int getDia() const;
            bool isBissexto();
};

class DataPrecisa : public Watch, public Data{
    public:
            DataPrecisa();
            DataPrecisa(int,int,int,int,int,int,bool) throw(DataEHoraInvalidas, DataInvalida, HoraInvalida);
            DataPrecisa(Data);
            DataPrecisa(Data,Watch);
};

DataEHoraInvalidas::DataEHoraInvalidas() : std::logic_error("DATA E HORA INVALIDAS.")
{   }

DataInvalida::DataInvalida() : std::logic_error("DATA INVALIDA.")
{   }

HoraInvalida::HoraInvalida() : std::logic_error("HORA INVALIDA.")
{   }

Watch::Watch(){
    this->setHora(12);
    this->setMinuto(0);
    this->setSegundo(0);
    this->setAM(true);
}

Watch::Watch(int h, int m, int seg, bool am) throw(HoraInvalida){
    if((h>12 || h<1) || (m>=60 || m<0) || (seg>=60 || seg<0)){
        throw HoraInvalida();
    }else{
        this->setHora(h);
        this->setMinuto(m);
        this->setSegundo(seg);
        this->setAM(am);
        std::cout << "HORA VALIDA" << std::endl;
    }
}

void Watch::setAM(bool h){
    this->AM = h;
}

bool Watch::isAM() const{
    return this->AM;
}

void Watch::setHora(int h){
    this->hora = h;
}

int Watch::getHora() const{
    return this->hora;
}

void Watch::setMinuto(int m){
    this->minuto = m;
}

int Watch::getMinuto() const{
    return this->minuto;
}

void Watch::setSegundo(int s){
    this->segundo = s;
}

int Watch::getSegundo() const{
    return this->segundo;
}

Data::Data(){
    
}

Data::Data(int d, int m, int a) throw(DataInvalida){
    if(m<1 || m>12){
        throw DataInvalida();
    }else{
        if(d>31 || d<1){
            throw DataInvalida();
        }else{
            if((m==4 || m==6 || m==9 || m==11) && d>30){
                throw DataInvalida();
            }else{
                if(m==2 && isBissexto() && d>29){
                    throw DataInvalida();
                }else{
                    if(m==2 && !isBissexto() && d>28){
                        throw DataInvalida();
                    }else{
                        this->setDia(d);
                        this->setMes(m);
                        this->setAno(a);
                    }
                }
            }
        }
    }
}

void Data::setDia(int d){
    this->dia = d;
}

int Data::getDia() const{
    return this->dia;
}

void Data::setMes(int m){
    this->mes = m;
}

int Data::getMes() const{
    return this->mes;
}

void Data::setAno(int a){
    this->ano = a;
}

int Data::getAno() const{
    return this->ano;
}

bool Data::isBissexto(){
    if((this->getAno()%4)==0){
        return true;
    }else{
        return false;
    }
}

DataPrecisa::DataPrecisa(){
    
}

DataPrecisa::DataPrecisa(int a, int m, int d, int h, int min, int s, bool am) throw(DataEHoraInvalidas, DataInvalida, HoraInvalida){
    bool di = false, hi = false;
    this->setAno(a);
    this->setMes(m);
    this->setDia(d);
    this->setHora(h);
    this->setMinuto(min);
    this->setSegundo(s);
    this->setAM(am);
    
    if(m<1 || m>12){
        di = true;
    }else{
        if(d>31 || d<1){
            di = true;
        }else{
            if((m==4 || m==6 || m==9 || m==11) && d>30){
                di = true;
            }else{
                if(m==2 && this->isBissexto() && d>29){
                    di = true;
                }else{
                    if(m==2 && !(this->isBissexto()) && d>28){
                        di = true;
                    }
                }
            }
        }
    }
    
    if((h>12 || h<1) || (min>=60 || min<0) || (s>=60 || s<0)){
        hi = true;
    }
    
    if(di && hi){
        throw DataEHoraInvalidas();
    }else{                        
        if(di){
            throw DataInvalida();
            std::cout << "teste" << std::endl;
        }else{
            if(hi){
                throw HoraInvalida();
            }else{
                std::cout << "DATA E HORA VALIDAS." << std::endl;
            }
        }
    }
}

DataPrecisa::DataPrecisa(Data dt) : Data(dt.getAno(), dt.getMes(), dt.getDia()){
    this->setHora(0);
    this->setMes(0);
    this->setDia(0);
}

DataPrecisa::DataPrecisa(Data dt, Watch wa) : 
                Data(dt.getAno(), dt.getMes(), dt.getDia()),
                Watch(wa.getHora(), wa.getMinuto(), wa.getSegundo(), wa.isAM())
{
    
}

int main(){
    int d, mes, a, h, m, seg;
    std::string p;
    char p1,p2,b1,b2, es; //descartar os caracteres extras
    bool ref;
    
    while(std::cin >> a >> b1 >> mes >> b2 >> d >> h >> p1 >> m >> p2 >> seg >> p){
        try{
            if(p=="AM"){
                ref = true;
            }else{
                ref = false;
            }
        
            DataPrecisa(d,mes,a,h,m,seg,ref);
        }
        catch(DataEHoraInvalidas dhe){
            std::cout << dhe.what() << std::endl;
        }
        catch(DataInvalida de){
            std::cout << de.what() << std::endl;
        }
        catch(HoraInvalida he){
            std::cout << he.what() << std::endl;
        }
    }
    
    return 0;
}