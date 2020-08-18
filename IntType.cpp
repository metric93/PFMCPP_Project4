#include "IntType.h"
#include <cmath> 

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