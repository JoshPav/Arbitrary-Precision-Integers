#ifndef NEGATIVENUMBERERROR_H
#define NEGATIVENUMBERERROR_H

#include <stdexcept>

namespace ExactArithmetic
{
    class NegativeNumberError : public std::domain_error
    {
    public:
        NegativeNumberError() : std::domain_error("Less than Zero") {}
    };
} // namespace ExactArithmetic

#endif