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

    IntType& pow(const IntType& i);
    IntType& pow(const FloatType& f);
    IntType& pow(const DoubleType& d);
    IntType& pow(int i);

    operator int()  {return *intPtr;}

    private:
        int* intPtr;
        IntType& powInternal(int i);

};
