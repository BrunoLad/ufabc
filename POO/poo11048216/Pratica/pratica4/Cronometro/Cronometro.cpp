#include <iostream>

class Cronometro{
    private:
            int hora;
            int minuto;
            int segundo;
    public:
            Cronometro();
            Cronometro(int); //passa o total de segundo transcorridos
            Cronometro(int,int,int);
            void setHora(int);
            int getHora();
            void setMinuto(int);
            int getMinuto();
            void setSegundo(int);
            int getSegundo();
            Cronometro operator ++(); //não sei se é necessário implementar o retorno
            Cronometro operator ++(int);
};

Cronometro::Cronometro(){
    this->setSegundo(0);
    this->setMinuto(0);
    this->setHora(0);
}

Cronometro::Cronometro(int s){
    this->setHora(s/3600);
    s%=3600;
    this->setMinuto(s/60);
    s%=60;
    this->setSegundo(s);
}

Cronometro::Cronometro(int h, int m, int s){
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(s);
}

void Cronometro::setHora(int h){
    this->hora = h;
}

int Cronometro::getHora(){
    return this->hora;
}

void Cronometro::setMinuto(int m){
    this->minuto = m;
}

int Cronometro::getMinuto(){
    return this->minuto;
}

void Cronometro::setSegundo(int s){
    this->segundo = s;
}

int Cronometro::getSegundo(){
    return this->segundo;
}

Cronometro Cronometro::operator ++(){
    if(this->getSegundo()<59){
        this->setSegundo(this->getSegundo()+1);
    }else{
        if(this->getSegundo()==59 && this->getMinuto()<59){
            this->setHora(0);
            this->setMinuto(this->getMinuto()+1);
        }else{
            if(this->getMinuto()==59){
                this->setMinuto(0);
                this->setHora(this->getHora()+1);
            }
        }
    }
    return *this;
}

Cronometro Cronometro::operator ++(int){
    
    Cronometro c(this->getHora(),this->getMinuto(),this->getSegundo());
    
    if(this->getSegundo()<59){
        this->setSegundo(this->getSegundo()+1);
    }else{
        if(this->getSegundo()==59 && this->getMinuto()<59){
            this->setSegundo(0);
            this->setMinuto(this->getMinuto()+1);
        }else{
            if(this->getMinuto()==59){
                this->setSegundo(0);
                this->setMinuto(0);
                this->setHora(this->getHora()+1);
            }
        }
    }
    
    return c;
}

int main(){
    
    Cronometro c;
    std::string s;
    
    while(std::cin >> s){
        if(s=="tic"){
            c++;
        }
    }
    
    std::cout << c.getHora() << ":" << c.getMinuto() << ":" << c.getSegundo() << std::endl;
    
    return 0;
}