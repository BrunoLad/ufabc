#include <stdexcept>

class DataInvalidaException : public std::logic_error{
    public:
        DataInvalidaException();
};