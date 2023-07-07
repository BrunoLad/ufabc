#include "FilaException.h"

FilaVaziaException::FilaVaziaException() : std::underflow_error("Underflow Error: Fila Vazia.")
{   }