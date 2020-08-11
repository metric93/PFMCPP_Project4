#pragma once
#include <iostream>

struct IntType
{
    IntType(int intPtr_) : intPtr(new int(intPtr_)){}

    ~IntType() 
    {
        delete intPtr;
        intPtr = nullptr;
    }


    IntType& add( int rhs );
    IntType& subtract( int rhs );
    IntType& multiply( int rhs );
    IntType& divide( int rhs );

    operator int()  {return *intPtr;}

    private:
        int* intPtr;
};
