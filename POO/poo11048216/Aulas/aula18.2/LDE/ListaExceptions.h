#include <stdexcept>

class ListaVaziaException : public std::underflow_error
{
    public:
            ListaVaziaException();
};

class ChaveExistenteException : public std::logic_error
{
    public:
            ChaveExistenteException();
};

class ChaveInexistenteException : public std::logic_error
{
    public:
            ChaveInexistenteException();
};