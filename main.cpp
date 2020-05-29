/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A {};

struct HeapA
{
    //Pointer of Type A
    A* pointerA;

    //Creating an object of Type A on the heap with the new Keyword
    HeapA() : pointerA( new A()){}

    //Removing the Object and setting the Pointer to nullptr
    ~HeapA()
    {
        delete pointerA;
        pointerA = nullptr;
    }

};


 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) replace main() with the main() below

 8) click the [run] button.  Clear up any errors or warnings as best you can.
 */




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

    FloatType& add( FloatType& udt);
    FloatType& subtract( FloatType& udt);
    FloatType& multiply( FloatType& udt);
    FloatType& divide( FloatType& udt);

    FloatType& add( IntType& udt);
    FloatType& subtract( IntType& udt);
    FloatType& multiply( IntType& udt);
    FloatType& divide( IntType& udt);

    FloatType& add( DoubleType& udt);
    FloatType& subtract( DoubleType& udt);
    FloatType& multiply( DoubleType& udt);
    FloatType& divide( DoubleType& udt);
};




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

    DoubleType& add( DoubleType& udt);
    DoubleType& subtract( DoubleType& udt);
    DoubleType& multiply( DoubleType& udt);
    DoubleType& divide( DoubleType& udt);

    DoubleType& add( IntType& udt);
    DoubleType& subtract( IntType& udt);
    DoubleType& multiply( IntType& udt);
    DoubleType& divide( IntType& udt);

    DoubleType& add( FloatType& udt);
    DoubleType& subtract( FloatType& udt);
    DoubleType& multiply( FloatType& udt);
    DoubleType& divide( FloatType& udt);
};




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

    IntType& add(IntType& udt);
    IntType& subtract(IntType& udt);
    IntType& multiply(IntType& udt);
    IntType& divide(IntType& udt);

    IntType& add(DoubleType& udt);
    IntType& subtract(DoubleType& udt);
    IntType& multiply(DoubleType& udt);
    IntType& divide(DoubleType& udt);

    IntType& add(FloatType& udt);
    IntType& subtract(FloatType& udt);
    IntType& multiply(FloatType& udt);
    IntType& divide(FloatType& udt);
};












/*Float Type Definitions*/
/**/
FloatType& FloatType::add (float rhs)
{
    *value += rhs;
    return *this;
}

FloatType& FloatType::subtract (float rhs)
{
    *value -= rhs;
    return *this;
}

FloatType& FloatType::multiply ( float rhs)
{
    *value = *value * rhs;
    return *this;
}

FloatType& FloatType::divide ( float rhs)
{
    if  (std::abs(rhs) > 0) 
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
    }  
    *value = *value / rhs;
    return *this;
}


/**/
FloatType& FloatType::add (FloatType& udt)
{
    return add(*udt.value);
}

FloatType& FloatType::subtract (FloatType& udt)
{
    return subtract(*udt.value);
}

FloatType& FloatType::multiply (FloatType& udt)
{
    return multiply(*udt.value);
}

FloatType& FloatType::divide (FloatType& udt)
{
    return divide(*udt.value);
}

/**/
FloatType& FloatType::add (IntType& udt)
{
    return add(*udt.value);
}

FloatType& FloatType::subtract (IntType& udt)
{
    return subtract(*udt.value);
}

FloatType& FloatType::multiply (IntType& udt)
{
    return multiply(*udt.value);
}

FloatType& FloatType::divide (IntType& udt)
{
    return divide(*udt.value);
}

/**/
FloatType& FloatType::add (DoubleType& udt)
{
    return add(static_cast<float>(*udt.value));
}

FloatType& FloatType::subtract (DoubleType& udt)
{
    return subtract(static_cast<float>(*udt.value));
}

FloatType& FloatType::multiply (DoubleType& udt)
{
    return multiply(static_cast<float>(*udt.value));
}

FloatType& FloatType::divide (DoubleType& udt)
{
    return divide(static_cast<float>(*udt.value));
}



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

/**/
DoubleType& DoubleType::add(DoubleType& udt)
{
    return add(*udt.value);
}

DoubleType& DoubleType::subtract(DoubleType& udt)
{
    return subtract(*udt.value);
}

DoubleType& DoubleType::multiply (DoubleType& udt)
{
    return multiply(*udt.value);
}

DoubleType& DoubleType::divide (DoubleType& udt)
{
    return divide(*udt.value);
}

/**/
DoubleType& DoubleType::add(IntType& udt)
{
    return add(*udt.value);
}

DoubleType& DoubleType::subtract(IntType& udt)
{
    return subtract(*udt.value);
}

DoubleType& DoubleType::multiply (IntType& udt)
{
    return multiply(*udt.value);
}

DoubleType& DoubleType::divide (IntType& udt)
{
    return divide(*udt.value);
}

/**/
DoubleType& DoubleType::add(FloatType& udt)
{
    return add(static_cast<double>(*udt.value));
}

DoubleType& DoubleType::subtract(FloatType& udt)
{
    return subtract(static_cast<double>(*udt.value));
}

DoubleType& DoubleType::multiply (FloatType& udt)
{
    return multiply(static_cast<double>(*udt.value));
}

DoubleType& DoubleType::divide (FloatType& udt)
{
    return divide(static_cast<double>(*udt.value));
}






/*IntType Definitions*/
/**/
IntType& IntType::add ( int rhs)
{
    *value += rhs;
    return *this;
}

IntType& IntType::subtract ( int rhs)
{
    *value -= rhs;
    return *this;
}

IntType& IntType::multiply ( int rhs)
{
    *value = *value * rhs;
    return *this;
}

IntType& IntType::divide ( int rhs)
{
    if (rhs == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl; 
    }
    else
    {
        *value = *value / rhs;
    }  
    return *this;
}


/**/
IntType& IntType::add (IntType& udt)
{
    return add(*udt.value);
}

IntType& IntType::subtract(IntType& udt)
{
    return subtract(*udt.value);
}

IntType& IntType::divide(IntType& udt)
{
    return divide(*udt.value);
}

IntType& IntType::multiply(IntType& udt)
{
    return multiply(*udt.value);
}


/**/
IntType& IntType::add (FloatType& udt)
{
    return add(static_cast<int>(*udt.value));
}

IntType& IntType::subtract(FloatType& udt)
{
    return subtract(static_cast<int>(*udt.value));
}

IntType& IntType::divide(FloatType& udt)
{
    return divide(static_cast<int>(*udt.value));
}

IntType& IntType::multiply(FloatType& udt)
{
    return multiply(static_cast<int>(*udt.value));
}


/**/
IntType& IntType::add (DoubleType& udt)
{
    return add(static_cast<int>(*udt.value));
}

IntType& IntType::subtract(DoubleType& udt)
{
    return subtract(static_cast<int>(*udt.value));
}

IntType& IntType::divide(DoubleType& udt)
{
    return divide(static_cast<int>(*udt.value));
}

IntType& IntType::multiply(DoubleType& udt)
{
    return multiply(static_cast<int>(*udt.value));
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;
    
    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5).value << std::endl << std::endl;
    
    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *it.multiply(1000).divide(2).subtract(10).add(100).value << std::endl;

    
        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << 
    std::endl;                                                      
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *dt.multiply(*it.value).divide(5.0).add(*ft.value).value << std::endl;


    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}

/*
your program should generate the following output.  

3 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the pro
gram!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!



Use a service like https://www.diffchecker.com/diff to compare your output. 
you will have 3 conversion warnings at the top of your output.  
you'll learn to solve them in the next project part.

*/
