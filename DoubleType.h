#pragma once
#include <iostream>


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


    operator double() {return *doublePtr;}

    private:
        double* doublePtr;
};
