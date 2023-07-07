#include <iostream>

class Romano{
    private:
            std::string valor;
    public:
            Romano();
            Romano(std::string);
            Romano(int);
            void setValor(std::string);
            std::string getValor();
            operator int();
};

Romano::Romano(){
    
}

Romano::Romano(std::string s){
    this->setValor(s);
}

Romano::Romano(int n){
    int aux;
    std::string saida = "";
    
    aux = (n/1000);
    for(int i=0; i<aux; i++){
        saida+="M";
    }
    
    n%=1000;
    
    aux = (n/900);
    
    for(int i=0; i<aux; i++){
        saida+="CM";
    }
    
    n%=900;
    
    aux = (n/500);
    
    for(int i=0; i < aux; i++){
        saida+="D";
    }
    
    n%=500;
    
    aux = (n/400);
    
    for(int i=0; i<aux; i++){
        saida+="CD";
    }
    
    n%=400;
    
    aux = (n/100);
    
    for(int i=0; i<aux; i++){
        saida+="C";
    }
    
    n%=100;
    
    aux = (n/90);
    
    for(int i=0; i<aux; i++){
        saida+="XC";
    }
    
    n%=90;
    
    aux = (n/50);
    
    for(int i=0; i<aux; i++){
        saida+="L";
    }
    
    n%=50;
    
    if((n/40)!=0){
        saida+="XL";
        n%=40;
    }
    
    aux = (n/10);
    
    for(int i=0; i<aux; i++){
        saida+="X";
    }
    
    n%=10;
    
    if((n/9)!=0){
        saida+="IX";
        n%=9;
    }
    
    aux = (n/5);
    
    for(int i=0; i<aux; i++){
        saida+="V";
    }
    
    n%=5;
    
    if(n/4==1){
        saida+="IV";
        n%=4;
    }
    
    for(int i=0; i<n; i++){
        saida+="I";
    }
    
    this->setValor(saida);
}

void Romano::setValor(std::string s){
    this->valor = s;
}

std::string Romano::getValor(){
    return this->valor;
}

Romano::operator int(){
    
}

int main(){
    
    Romano r;
    int nInd;
    
    while(std::cin >> nInd){
        r = nInd;
        
        std::cout << r.getValor() << std::endl;
    }
    
    return 0;
}