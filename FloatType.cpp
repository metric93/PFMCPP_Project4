#include "FloatType.h"
#include <cmath> 

//These Includes are so the operators are avaiable
#include "IntType.h"
#include "DoubleType.h"

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

FloatType& FloatType::powInternal(float f)
{
    *floatPtr =  static_cast<float>( std::pow(*floatPtr, f) ); 
    return *this; 
}

FloatType& FloatType::pow(const FloatType& f)
{
    return powInternal(static_cast<float>(f));
}

FloatType& FloatType::pow(const IntType& i)
{
    return powInternal(static_cast<float>(i));
}

FloatType& FloatType::pow(const DoubleType& d)
{
    return powInternal(static_cast<float>(d));
}

FloatType& FloatType::pow(float f)
{
    return powInternal(f);
}