#include "IntType.h"
#include <cmath> 

//These Includes are so the operators are avaiable
#include "FloatType.h"
#include "DoubleType.h"

IntType& IntType::add ( int rhs)
{
    *intPtr += rhs;
    return *this;
}

IntType& IntType::subtract ( int rhs)
{
    *intPtr -= rhs;
    return *this;
}

IntType& IntType::multiply ( int rhs)
{
    *intPtr = *intPtr * rhs;
    return *this;
}

IntType& IntType::divide ( int rhs)
{
    if (rhs == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl; 
    }
    else
    {
        *intPtr = *intPtr / rhs;
    }  
    return *this;
}

IntType& IntType::powInternal(int i)
{
    *intPtr =  static_cast<int>( std::pow(*intPtr, i) ); 
    return *this; 
}

IntType& IntType::pow(const FloatType& f)
{
    return powInternal(static_cast<int>(f));
}

IntType& IntType::pow(const IntType& i)
{
    return powInternal(static_cast<int>(i));
}

IntType& IntType::pow(const DoubleType& d)
{
    return powInternal(static_cast<int>(d));
}

IntType& IntType::pow(int i)
{
    return powInternal(i);
}
