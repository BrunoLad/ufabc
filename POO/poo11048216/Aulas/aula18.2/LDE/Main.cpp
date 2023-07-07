#include "Lista.h"

int main()
{
    Lista *l = new Lista();
    Item *it;
    int chave;
    char op;
    while(std::cin >> op)
    {
        try
        {
            if(op == 'I')
            {
                std::cin >> chave;
                l->inserir(new Item(chave));
            }
            else if(op == 'R')
            {
                std::cin >> chave;
                it = l->remover(chave);
                std::cout << "REMOVIDO: " << it->getChave() << std::endl;
                delete it;
            }
            else
            {
                l->mostrar();
            }
        }
        catch(ListaVaziaException lve)
        {
            std::cout << lve.what() << std::endl;
        }
        catch(ChaveInexistenteException cie)
        {
            std::cout << cie.what() << std::endl;
        }
        catch(ChaveExistenteException cee)
        {
            std::cout << cee.what() << std::endl;
        }
    }
    return 0;
}