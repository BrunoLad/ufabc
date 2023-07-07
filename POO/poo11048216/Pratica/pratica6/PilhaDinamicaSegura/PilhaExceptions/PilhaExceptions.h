#include <stdexcept>

class PilhaVaziaException : public std::underflow_error{
    public:
            PilhaVaziaException();
};