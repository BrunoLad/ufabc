#include "ListaExceptions.h"

ListaVaziaException::ListaVaziaException() : std::underflow_error("Underflow Error: Lista Vazia.")
{   }

ChaveExistenteException::ChaveExistenteException() : std::logic_error("Logic Error: Chave Existente na Lista.")
{   }

ChaveInexistenteException::ChaveInexistenteException() : std::logic_error("Logic Error: Chave Inexistente na Lista.")
{   }