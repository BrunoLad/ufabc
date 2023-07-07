#include "ListaExceptions.h"

ListaVaziaException::ListaVaziaException() : std::underflow_error("Underflow Error: Lista Vazia.")
{   }

ChaveInexistenteException::ChaveInexistenteException() : std::logic_error("Logic Error: Chave Inexistente na Lista.")
{   }

ChaveExisteException::ChaveExisteException() : std::logic_error("Logic Error: Chave existe na Lista.")
{   }