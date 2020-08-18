#include "DoubleType.h"
#include <cmath> 

DoubleType& DoubleType::add ( double rhs)
{
    *doublePtr += rhs;
    return *this;
}

DoubleType& DoubleType::subtract ( double rhs)
{
    *doublePtr -= rhs;
    return *this;
}

DoubleType& DoubleType::multiply (  double rhs)
{
    *doublePtr = *doublePtr * rhs;
    return *this;
}

DoubleType& DoubleType::divide ( double rhs)
{
    if (std::abs(rhs) == 0.)
    {
        std::cout << "warning: floating point division by zero!"<< std::endl;
    } 
    *doublePtr = *doublePtr / rhs;
    return *this;
}

DoubleType& DoubleType::powInternal(double d)
{
    *doublePtr =  static_cast<double>( std::pow(*doublePtr, d) ); 
    return *this; 
}

DoubleType& DoubleType::pow(const DoubleType& d)
{
    return powInternal(static_cast<double>(d));
}