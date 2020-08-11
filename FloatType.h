#pragma once
#include <iostream>

struct FloatType
{
    FloatType(float floatPtr_) : floatPtr(new float(floatPtr_)){}
    ~FloatType()
    {
        delete floatPtr;
        floatPtr = nullptr;
    }


    FloatType& add( float rhs );
    FloatType& subtract( float rhs );
    FloatType& multiply( float rhs );
    FloatType& divide(  float rhs );

    operator float()  {return *floatPtr;}

    private:
        float* floatPtr;
};
