#pragma once
#include <iostream>

struct IntType;
struct FloatType;

struct DoubleType
{
    

    DoubleType(double doublePtr_) : doublePtr(new double(doublePtr_)){}

    ~DoubleType() 
    {
        delete doublePtr;
        doublePtr = nullptr;
    }

    DoubleType& add( double rhs );
    DoubleType& subtract( double rhs );
    DoubleType& multiply( double rhs );
    DoubleType& divide( double rhs );

    DoubleType& pow(const IntType& i);
    DoubleType& pow(const FloatType& f);
    DoubleType& pow(const DoubleType& d);
    DoubleType& pow(double d);

    //Operators for Static Conversion
    //Const objects can only call their const member functions
    operator double() const {return *doublePtr;} 

    private:
        double* doublePtr;
        DoubleType& powInternal(double d);
};
