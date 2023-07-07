#include <iostream>
#include <stdexcept>

class LotacaoExcedidaException : public std::logic_error{
    public:
            LotacaoExcedidaException();
};

class CapacidadeExcedidaException : public std::logic_error{
    public:
            CapacidadeExcedidaException();
};

class LotacaoECapacidadeExcedidadsExceptions : public std::logic_error{
    public:
            LotacaoECapacidadeExcedidadsExceptions();
};

class ElevadorVazioException : public std::logic_error{
    public:
            ElevadorVazioException();
};

class Elevador{
    private:
            int tara;
            int capacidade;
            int lotacao;
            int pessoas;
            int pesoP;
    public:
            Elevador();
            Elevador(int,int,int);
            Elevador(int,int,int,int); //construtor está errado
            void setTara(int);
            int getTara();
            void setCapacidade(int);
            int getCapacidade();
            void setLotacao(int);
            int getLotacao();
            void setPessoas(int);
            int getPessoas();
            void setPesoP(int);
            int getPesoP();
            void subida(int) throw(LotacaoExcedidaException, CapacidadeExcedidaException, LotacaoECapacidadeExcedidadsExceptions);
            void descida(int) throw(ElevadorVazioException);
            void relatorio();
};

LotacaoExcedidaException::LotacaoExcedidaException() : std::logic_error("Lotacao do Elevador Excedida.")
{   }

CapacidadeExcedidaException::CapacidadeExcedidaException() : std::logic_error("Capacidade Total do Elevador Excedida.")
{   }

LotacaoECapacidadeExcedidadsExceptions::LotacaoECapacidadeExcedidadsExceptions() : std::logic_error("Lotacao e Capacidade Total do Elevador Excedidas.")
{   }

ElevadorVazioException::ElevadorVazioException() : std::logic_error("Elevador Vazio.")
{   }

Elevador::Elevador()
{   }

Elevador::Elevador(int t, int c, int l){
    this->setTara(t);
    this->setCapacidade(c);
    this->setLotacao(l);
    this->setPessoas(0);
    this->setPesoP(0);
}

Elevador::Elevador(int t, int c, int l, int p){
    this->setTara(t);
    this->setCapacidade(c);
    this->setLotacao(l);
    this->setPessoas(p);
}

void Elevador::setTara(int t){
    this->tara = t;
}

int Elevador::getTara(){
    return this->tara;
}

void Elevador::setCapacidade(int c){
    this->capacidade = c;
}

int Elevador::getCapacidade(){
    return this->capacidade;
}

void Elevador::setLotacao(int l){
    this->lotacao = l;
}

int Elevador::getLotacao(){
    return this->lotacao;
}

void Elevador::setPessoas(int p){
    this->pessoas = p;
}

int Elevador::getPessoas(){
    return this->pessoas;
}

void Elevador::setPesoP(int p){
    this->pesoP = p;
}

int Elevador::getPesoP(){
    return this->pesoP;
}

void Elevador::subida(int p) throw(LotacaoECapacidadeExcedidadsExceptions, LotacaoExcedidaException, CapacidadeExcedidaException){
    if((this->getPessoas()+1)>this->getLotacao() && (this->getPesoP()+this->getTara()+p)>this->getCapacidade()){
        throw LotacaoECapacidadeExcedidadsExceptions();
    }else{
        if((this->getPessoas()+1)>this->getLotacao()){
         throw LotacaoExcedidaException();   
        }else{
            if((this->getPesoP()+this->getTara()+p)>this->getCapacidade()){
                throw CapacidadeExcedidaException();
            }else{
                this->setPesoP(this->getPesoP()+p);
                this->setPessoas(this->getPessoas()+1);
            }
        }
    }
}

void Elevador::descida(int p) throw(ElevadorVazioException){
    if(this->getPessoas()==0){
        throw ElevadorVazioException();
    }else{
        this->setPessoas(this->getPessoas()-1);
        this->setPesoP(this->getPesoP()-p);
    }
}

void Elevador::relatorio(){
    std::cout << "===== RELATORIO DE SEGURANCA DO ELEVADOR =====" << std::endl;
    std::cout << "TARA .............: " << getTara() << " kg." << std::endl;
    std::cout << "LOTACAO TOTAL ....: " << getLotacao() << " passageiros" << std::endl;
    std::cout << "CAPACIDADE TOTAL .: " << getCapacidade() << " kg." << std::endl;
    std::cout << "LOTACAO ATUAL ....: " << getPessoas() << " passageiros" << std::endl;
    std::cout << "PESO .............: " << getPesoP() << " kg." << std::endl;
    std::cout << "PESO TOTAL .......: " << getTara() + getPesoP() << " kg." << std::endl;
    std::cout << "==============================================" << std::endl;
}

int main(){
    int t, c, l;
    char op;
    std::cin >> t >> c >> l;
    
    Elevador e(t,c,l);
    
    while(std::cin >> op){
        try{
            switch(op){
                case 'V':
                    e.relatorio();
                    break;
                case 'S':
                    int pes;
                    std::cin >> pes;
                    e.subida(pes);
                    break;
                case 'D':
                    int pesd;
                    std::cin >> pesd;
                    e.descida(pesd);
                    break;
                default:
                    break;
            }
        }
        catch(LotacaoExcedidaException le){
            std::cout << le.what() << std::endl;
        }
        catch(CapacidadeExcedidaException ce){
            std::cout << ce.what() << std::endl;
        }
        catch(LotacaoECapacidadeExcedidadsExceptions lec){
            std::cout << lec.what() << std::endl;
        }
        catch(ElevadorVazioException eve){
            std::cout << eve.what() << std::endl;
        }
    }
    return 0;
}