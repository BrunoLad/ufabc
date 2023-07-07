#include <stdexcept>

class PilhaVaziaException : public std::runtime_error{
    public:
            PilhaVaziaException();
};

class PilhaCheiaException : public std::runtime_error{
    public:
            PilhaCheiaException();
};