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
    int saida=0;
    std::string ref = this->getValor();
    
    for(int i=0; i<ref.length(); i++){
        if(ref[i]=='M'){
            saida+=1000;
        }else{
            if(ref[i]=='C'){
                if(ref[i+1]=='M'){
                    saida+=900;
                    i++;
                }else{
                    if(ref[i+1]=='D'){
                        saida+=400;
                        i++;
                    }else{
                        saida+=100;
                    }
                }
            }else{
                if(ref[i]=='D'){
                    saida+=500;
                }else{
                    if(ref[i]=='X'){
                        if(ref[i+1]=='C'){
                            saida+=90;
                            i++;
                        }else{
                            if(ref[i+1]=='L'){
                                saida+=40;
                                i++;
                            }else{
                                saida+=10;
                            }
                        }
                    }else{
                        if(ref[i]=='L'){
                            saida+=50;
                        }else{
                            if(ref[i]=='I'){
                                if(ref[i+1]=='X'){
                                    saida+=9;
                                    i++;
                                }else{
                                    if(ref[i+1]=='V'){
                                        saida+=4;
                                        i++;
                                    }else{
                                        saida ++;
                                    }
                                }
                            }else{
                              saida+=5;
                            }
                        }
                    }
                }
            }
        }
    }
    return saida;
}

int main(){
    
    std::string valor;
    int nInd;
    
    while(std::cin >> valor){
        Romano r(valor);
        nInd = r;
        
        std::cout << nInd << std::endl;
    }
    
    return 0;
}