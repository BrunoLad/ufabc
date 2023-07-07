#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

class Complexo{
    private:
            int real;
            int imaginario;
    public:
            Complexo();
            Complexo(int, int);
            void setReal(int);
            int getReal();
            void setImaginario(int);
            int getImaginario();
            Complexo operator + (Complexo);
            Complexo operator - (Complexo);
            Complexo operator * (Complexo);
            Complexo operator / (Complexo);
};

Complexo::Complexo(){
    
}

Complexo::Complexo(int r, int i){
    this->setReal(r);
    this->setImaginario(i);
}

void Complexo::setReal(int r){
    this->real = r;
}

int Complexo::getReal(){
    return this->real;
}

void Complexo::setImaginario(int i){
    this->imaginario = i;
}

int Complexo::getImaginario(){
    return this->imaginario;
}

Complexo Complexo::operator + (Complexo c){
    Complexo res;
    
    res.setReal(this->getReal() + c.getReal());
    res.setImaginario(this->getImaginario() + c.getImaginario());
    
    return res;
}

Complexo Complexo::operator - (Complexo c){
    Complexo res;
    
    res.setReal(this->getReal() - c.getReal());
    res.setImaginario(this->getImaginario() - c.getImaginario());
    
    return res;
}

Complexo Complexo::operator * (Complexo c){
    Complexo res;
    
    res.setReal((this->getReal()*c.getReal()) - (this->getImaginario()*c.getImaginario()));
    res.setImaginario((this->getImaginario()*c.getReal()) + (this->getReal()*c.getImaginario()));
    
    return res;
}

Complexo Complexo::operator / (Complexo c){
    Complexo res;
    int quad = ((pow(c.getReal(),2)) + (pow(c.getImaginario(),2)));
    c.setImaginario(c.getImaginario()*(-1));
    
    res = (*this)*c;
    res.setReal(res.getReal()/quad);
    res.setImaginario(res.getImaginario()/quad);
    
    return res;
}


int main(){
    std::string i1, i2;
    int r1, r2, imi1, imi2;
    char op;
    
    while(std::cin >> r1 >> i1 >> op >> r2 >> i2){
        i1.erase(i1.end()-1);
        i2.erase(i2.end()-1);
        
        if(!i1.empty()){
            if(i1.length()==1 && *(i1.begin())=='-'){
                imi1 = -1;
            }else{
                imi1 = atoi(i1.c_str());
            }
        }else{
            imi1 = 1;
        }
        
        if(!i2.empty()){
            if(i2.length()==1 && *(i2.begin())=='-'){
                imi2 = -1;
            }else{
                imi2 = atoi(i2.c_str());
            }
        }else{
            imi2 = 1;
        }
        
        
        Complexo c1(r1,imi1), c2(r2,imi2), c;
        switch(op){
            case '+':
                c = c1 + c2;
                break;
            case '-':
                c = c1 - c2;
                break;
            case '*':
                c = c1 * c2;
                break;
            case '/':
                c = c1/c2;
                break;
            default:
                break;
        }
        if(c.getImaginario()>0){
            std::cout << c.getReal() << " +" << c.getImaginario() << "i" << std::endl;
        }else{
            std::cout << c.getReal() << " " << c.getImaginario() << "i" << std::endl;
        }
    }
    
    
    return 0;
}