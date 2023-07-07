#include "PilhaExceptions.h"

PilhaVaziaException::PilhaVaziaException() : std::underflow_error("Underflow Error: Pilha Vazia.")
{   }