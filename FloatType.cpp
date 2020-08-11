#include "FloatType.h"

FloatType& FloatType::add (float rhs)
{
    *floatPtr += rhs;
    return *this;
}

FloatType& FloatType::subtract (float rhs)
{
    *floatPtr -= rhs;
    return *this;
}

FloatType& FloatType::multiply ( float rhs)
{
    *floatPtr = *floatPtr * rhs;
    return *this;
}

FloatType& FloatType::divide ( float rhs)
{
    if  (std::abs(rhs) == 0.f) 
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
    }  
    *floatPtr = *floatPtr / rhs;
    return *this;
}