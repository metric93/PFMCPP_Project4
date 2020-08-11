struct IntType
{
    int* value;

    IntType(int value_) : value(new int(value_)){}

    ~IntType() 
    {
        delete value;
        value = nullptr;
    }


    IntType& add( int rhs );
    IntType& subtract( int rhs );
    IntType& multiply( int rhs );
    IntType& divide( int rhs );

};
