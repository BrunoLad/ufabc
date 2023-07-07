#include "RacionaisException.h"

DenominadorZeroException::DenominadorZeroException() : std::runtime_error("Denominador igual a zero.")
{   }