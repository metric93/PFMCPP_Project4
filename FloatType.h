#pragma once
#include <iostream>

struct IntType;
struct DoubleType;

struct FloatType
{
    float* value;

    FloatType(float value_) : value(new float(value_)){}
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }


    FloatType& add( float rhs );
    FloatType& subtract( float rhs );
    FloatType& multiply( float rhs );
    FloatType& divide(  float rhs );

};
