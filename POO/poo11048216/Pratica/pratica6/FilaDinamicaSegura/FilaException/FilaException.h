#include <stdexcept>

class FilaVaziaException : public std::underflow_error{
    public:
        FilaVaziaException();
};