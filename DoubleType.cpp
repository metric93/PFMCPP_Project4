/*Double type Definitions*/
/**/
DoubleType& DoubleType::add ( double rhs)
{
    *value += rhs;
    return *this;
}

DoubleType& DoubleType::subtract ( double rhs)
{
    *value -= rhs;
    return *this;
}

DoubleType& DoubleType::multiply (  double rhs)
{
    *value = *value * rhs;
    return *this;
}

DoubleType& DoubleType::divide ( double rhs)
{
    if (std::abs(rhs) == 0.)
    {
        std::cout << "warning: floating point division by zero!"<< std::endl;
    } 
    *value = *value / rhs;
    return *this;
}
