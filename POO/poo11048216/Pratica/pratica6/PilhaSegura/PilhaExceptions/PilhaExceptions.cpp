#include "PilhaExceptions.h"

PilhaVaziaException::PilhaVaziaException() : std::runtime_error("Runtime Error: Pilha Vazia.")
{   }

PilhaCheiaException::PilhaCheiaException() : std::runtime_error("Runtime Error: Pilha Cheia.")
{   }