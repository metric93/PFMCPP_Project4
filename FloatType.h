#pragma once
#include <iostream>

struct IntType;
struct DoubleType;

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

    FloatType& pow(const IntType& i);
    FloatType& pow(const FloatType& f);
    FloatType& pow(const DoubleType& d);
    FloatType& pow(float f);

    //Operators for Static Conversion
    //Const objects can only call their const member functions
    operator float() const  {return *floatPtr;}

    private:
        float* floatPtr;
        FloatType& powInternal(float f);

};
