#include <iostream>

class Horas12{
    private:
            int hora;
            int minuto;
            int segundo;
            bool AM;
    public:
            Horas12();
            Horas12(int,int,int,bool);
            void setHora(int);
            int getHora();
            void setMinuto(int);
            int getMinuto();
            void setSegundo(int);
            int getSegundo();
            void setAM(bool);
            bool isAM();
};


class Horas24{
    private:
            int hora;
            int minuto;
            int segundo;
    public:
            Horas24();
            Horas24(int,int,int);
            Horas24(Horas12);
            void setHora(int);
            int getHora();
            void setMinuto(int);
            int getMinuto();
            void setSegundo(int);
            int getSegundo();
            operator Horas12();
};

Horas12::Horas12(){
    
}

Horas12::Horas12(int h, int m, int s, bool t){
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(s);
    this->setAM(t);
}

void Horas12::setHora(int h){
    this->hora = h;
}

int Horas12::getHora(){
    return this->hora;
}

void Horas12::setMinuto(int m){
    this->minuto = m;
}

int Horas12::getMinuto(){
    return this->minuto;
}

void Horas12::setSegundo(int s){
    this->segundo = s;
}

int Horas12::getSegundo(){
    return this->segundo;
}

void Horas12::setAM(bool cond){
    this->AM = cond;
}

bool Horas12::isAM(){
    return this->AM;
}

Horas24::Horas24(){
    
}

Horas24::Horas24(int h, int m, int s){
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(s);
}

Horas24::Horas24(Horas12 hr){
    if(hr.isAM()){
        if(hr.getHora()==12){
            this->setHora(0);
            this->setMinuto(hr.getMinuto());
            this->setSegundo(hr.getSegundo());
        }else{
            this->setHora(hr.getHora());
            this->setMinuto(hr.getMinuto());
            this->setSegundo(hr.getSegundo());
        }
    }else{
        if(hr.getHora()==12){
            this->setHora(12);
            this->setMinuto(hr.getMinuto());
            this->setSegundo(hr.getSegundo());
        }else{
            this->setHora(hr.getHora()+12);
            this->setMinuto(hr.getMinuto());
            this->setSegundo(hr.getSegundo());
        }
    }
}

void Horas24::setHora(int h){
    this->hora = h;
}

int Horas24::getHora(){
    return this->hora;
}

void Horas24::setMinuto(int m){
    this->minuto = m;
}

int Horas24::getMinuto(){
    return this->minuto;
}

void Horas24::setSegundo(int s){
    this->segundo = s;
}

int Horas24::getSegundo(){
    return this->segundo;
}

Horas24::operator Horas12(){
    int h, m, s;
    bool am;
    
    m = this->getMinuto();
    s = this->getSegundo();
    
    if(this->getHora()>=12){
        if(this->getHora()==12){
            h = 12;
            am = false;
        }else{
            h = this->getHora() - 12;
            am = false;
        }
    }else{
        if(!this->getHora()){
            h = 12;
            am = true;
        }else{
            h = this->getHora();
            am = true;
        }
    }
    
    return Horas12(h,m,s,am);
    
}

int main(){
    
    int h, m, s;
    std::string cond;
    
    while(std::cin >> h >> m >> s >> cond){
        Horas12 *h1;
        if(cond == "AM"){
            h1 = new Horas12(h,m,s,true);
        }else{
            h1 = new Horas12(h,m,s,false);
        }
        Horas24 h2(*h1);
        
        
        std::cout << h2.getHora() << ":" << h2.getMinuto() << ":" << h2.getSegundo() << std::endl;
        
    }
    
    return 0;
}