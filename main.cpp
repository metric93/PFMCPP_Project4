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
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
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
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */




#include <iostream>



struct FloatType
{
    float* pointerFloat;

    FloatType(float value) : pointerFloat(new float(value)){}
    ~FloatType()
    {
        delete pointerFloat;
        pointerFloat = nullptr;
    }

    FloatType& add( float rhs );
    FloatType& subtract( float rhs );
    FloatType& multiply( float rhs );
    FloatType& divide(  float rhs );
};

FloatType& FloatType::add (float rhs)
{
    *pointerFloat += rhs;
    return *this;
}

FloatType& FloatType::subtract (float rhs)
{
    *pointerFloat -= rhs;
    return *this;
}

FloatType& FloatType::multiply ( float rhs)
{
    *pointerFloat = *pointerFloat * rhs;
    return *this;
}

FloatType& FloatType::divide ( float rhs)
{
    if (std::abs(rhs) > 0.f) 
    {
        *pointerFloat = *pointerFloat / rhs;
        return *this; 
    }
    std::cout << "Watch out! Float Divison by 0." << std::endl;
    return *this;
}


struct DoubleType
{
    double* pointerDouble;

    DoubleType(double value) : pointerDouble(new double(value)){}

    ~DoubleType() 
    {
        delete pointerDouble;
        pointerDouble = nullptr;
    }

    DoubleType& add( double rhs );
    DoubleType& subtract( double rhs );
    DoubleType& multiply( double rhs );
    DoubleType& divide( double rhs );
};

DoubleType& DoubleType::add ( double rhs)
{
    *pointerDouble += rhs;
    return *this;
}

DoubleType& DoubleType::subtract ( double rhs)
{
    *pointerDouble -= rhs;
    return *this;
}

DoubleType& DoubleType::multiply (  double rhs)
{
    *pointerDouble = *pointerDouble * rhs;
    return *this;
}

DoubleType& DoubleType::divide ( double rhs)
{
    if (std::abs(rhs) > 0.)
    {
        *pointerDouble = *pointerDouble / rhs;
        return *this; 
    }
    std::cout << "Watch out! Float Divison by 0." << std::endl;
    return *this;
}


struct IntType
{
    int* pointerInt;

    IntType(int value) : pointerInt(new int(value)){}

    ~IntType() 
    {
        delete pointerInt;
        pointerInt = nullptr;
    }


    IntType& add( int rhs );
    IntType& subtract( int rhs );
    IntType& multiply( int rhs );
    IntType& divide( int rhs );
};

IntType& IntType::add ( int rhs)
{
    *pointerInt += rhs;
    return *this;
}

IntType& IntType::subtract ( int rhs)
{
    *pointerInt -= rhs;
    return *this;
}

IntType& IntType::multiply ( int rhs)
{
    *pointerInt = *pointerInt * rhs;
    return *this;
}

IntType& IntType::divide ( int rhs)
{
    if (rhs == 0)
    {
        std::cout << "Invalid Expression!  Can't divide integers by 0!!" << std::endl; 
        return *this;
    }
    *pointerInt = *pointerInt / rhs;
    return *this;
}







int main()
{
    FloatType ft (5.5f);
    IntType it (5);
    DoubleType db (5.523);

    //float ftResult;
    //int itResult;
    //double dbResult;
    /*
    ftResult = ft.add (23.f );
    std::cout <<"result of ft.add(): " << ftResult << std::endl;

    ftResult = ft.subtract( 0.1f );
    std::cout <<"result of ft.subtract(): " << ftResult << std::endl;

    ftResult = ft.divide( 0.f );
    std::cout <<"result of ft.divide(): " << ftResult << std::endl;

    ftResult = ft.divide( 1 12.f );
    std::cout <<"result of ft.divide(): " << ftResult << std::endl;

    ftResult = ft.divide(  -12.f );
    std::cout <<"result of ft.divide(): " << ftResult << std::endl;

    itResult = it.divide( 15, 0);
    std::cout <<"result of it.divide(): " << itResult << std::endl;

    dbResult = db.divide( 15.25, 0.00);
    std::cout <<"result of db.divide(): " << dbResult << std::endl;

    dbResult = db.divide( 15.35, -2.54535);
    std::cout <<"result of db.divide(): " << dbResult << std::endl;
    */

    std::cout << "good to go!" << std::endl;
}
