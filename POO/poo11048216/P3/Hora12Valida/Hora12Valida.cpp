#include <iostream>
#include <stdexcept>
#include <string>

class HorarioInvalidoException : public std::logic_error {
    public:
            HorarioInvalidoException();
};

HorarioInvalidoException::HorarioInvalidoException() : std::logic_error("HORARIO INVALIDA")
{   }

class Watch{
    private:
            int hora;
            int minuto;
            int segundo;
            bool AM;
    public:
            Watch();
            Watch(int,int,int,bool) throw(HorarioInvalidoException);
            void setHora(int);
            int getHora() const;
            void setMinuto(int);
            int getMinuto() const;
            void setSegundo(int);
            int getSegundo() const;
            void setAM(bool);
            bool isAM() const;
};

Watch::Watch(){
    this->setHora(12);
    this->setMinuto(0);
    this->setSegundo(0);
    this->setAM(true);
}

Watch::Watch(int h, int m, int seg, bool am) throw(HorarioInvalidoException){
    if((h>12 || h<1) || (m>=60 || m<0) || (seg>=60 || seg<0)){
        throw HorarioInvalidoException();
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

int main(){
    int h, m, s;
    bool ref;
    std::string p;
    char p1, p2;//para descartar os dois pontos
    
    while(std::cin >> h >> p1 >> m >> p2 >> s >> p){
        try{
            if(p=="AM"){
                ref = true;
            }else{
                ref = false;
            }
            Watch w(h,m,s,ref);
        }
        catch(HorarioInvalidoException he){
            std::cout << he.what() << std::endl;
        }
    }
    
    return 0;
}