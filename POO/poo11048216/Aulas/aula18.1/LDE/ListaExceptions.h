#include <stdexcept>

class ListaVaziaException : public std::underflow_error
{
    public:
            ListaVaziaException();
};

class ChaveInexistenteException : public std::logic_error
{
    public:
            ChaveInexistenteException();
};

class ChaveExisteException : public std::logic_error
{
    public:
            ChaveExisteException();
};