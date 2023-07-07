#include <stdexcept>

class DenominadorZeroException : public std::runtime_error{
    public:
        DenominadorZeroException();
};