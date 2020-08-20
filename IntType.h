#pragma once
#include <iostream>

struct FloatType;
struct DoubleType;

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

    //Operators for Static Conversion
    //Const objects can only call their const member functions
    operator int() const {return *intPtr;}

    private:
        int* intPtr;
        IntType& powInternal(int i);

};
