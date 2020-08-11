struct DoubleType
{
    double* value;

    DoubleType(double value_) : value(new double(value_)){}

    ~DoubleType() 
    {
        delete value;
        value = nullptr;
    }

    DoubleType& add( double rhs );
    DoubleType& subtract( double rhs );
    DoubleType& multiply( double rhs );
    DoubleType& divide( double rhs );

};
