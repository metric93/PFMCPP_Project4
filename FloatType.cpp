#include "FloatType.h"

FloatType& FloatType::add (float rhs)
{
    *value += rhs;
    return *this;
}

FloatType& FloatType::subtract (float rhs)
{
    *value -= rhs;
    return *this;
}

FloatType& FloatType::multiply ( float rhs)
{
    *value = *value * rhs;
    return *this;
}

FloatType& FloatType::divide ( float rhs)
{
    if  (std::abs(rhs) > 0) 
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
    }  
    *value = *value / rhs;
    return *this;
}
