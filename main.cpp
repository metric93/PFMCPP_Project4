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

    FloatType() : pointerFloat(new float()){}
    ~FloatType()
    {
        delete pointerFloat;
        pointerFloat = nullptr;
    }

    float add( float lhs, float rhs );
    float subtract( float lhs, float rhs );
    float multiply( float lhs, float rhs );
    float divide( float lhs, float rhs );
};

float FloatType::add ( float lhs, float rhs)
{
    return lhs + rhs;
}

float FloatType::subtract ( float lhs, float rhs)
{
    return lhs - rhs;
}

float FloatType::multiply ( float lhs, float rhs)
{
    return lhs * rhs;
}

float FloatType::divide ( float lhs, float rhs)
{
    if (std::abs(rhs) > 0.f) 
    {
        return lhs / rhs; 
    }
    std::cout << "Watch out! Float Divison by 0." << std::endl;
    return lhs / rhs;
}


struct DoubleType
{
    double* pointerDouble;

    DoubleType() : pointerDouble(new double()){}

    ~DoubleType() 
    {
        delete pointerDouble;
        pointerDouble = nullptr;
    }

    double add( double lhs, double rhs );
    double subtract( double lhs, double rhs );
    double multiply( double lhs, double rhs );
    double divide( double lhs, double rhs );
};

double DoubleType::add ( double lhs, double rhs)
{
    return lhs + rhs;
}

double DoubleType::subtract ( double lhs, double rhs)
{
    return lhs - rhs;
}

double DoubleType::multiply ( double lhs, double rhs)
{
    return lhs * rhs;
}

double DoubleType::divide ( double lhs, double rhs)
{
    if (std::abs(rhs) > 0.)
    {
        return lhs / rhs; 
    }
    std::cout << "Watch out! Float Divison by 0." << std::endl;
    return lhs / rhs;
}


struct IntType
{
    int* pointerInt;

    IntType() : pointerInt(new int()){}

    ~IntType() 
    {
        delete pointerInt;
        pointerInt = nullptr;
    }


    int add( int lhs, int rhs );
    int subtract( int lhs, int rhs );
    int multiply( int lhs, int rhs );
    int divide( int lhs, int rhs );
};

int IntType::add ( int lhs, int rhs)
{
    return lhs + rhs;
}

int IntType::subtract ( int lhs, int rhs)
{
    return lhs - rhs;
}

int IntType::multiply ( int lhs, int rhs)
{
    return lhs * rhs;
}

int IntType::divide ( int lhs, int rhs)
{
    if (rhs == 0)
    {
        std::cout << "Invalid Expression!  Can't divide integers by 0!!" << std::endl; 
        return lhs;
    }
    return lhs / rhs;
}







int main()
{
    FloatType ft;
    IntType it;
    DoubleType db;

    float ftResult;
    int itResult;
    double dbResult;

    ftResult = ft.add (3.2f, 23.f );
    std::cout <<"result of ft.add(): " << ftResult << std::endl;

    ftResult = ft.subtract( 250.f, 0.1f );
    std::cout <<"result of ft.subtract(): " << ftResult << std::endl;

    ftResult = ft.divide( 15.5254f, 0.f );
    std::cout <<"result of ft.divide(): " << ftResult << std::endl;

    ftResult = ft.divide( 15.5254f, 12.f );
    std::cout <<"result of ft.divide(): " << ftResult << std::endl;

    ftResult = ft.divide( 15.5254f, -12.f );
    std::cout <<"result of ft.divide(): " << ftResult << std::endl;

    itResult = it.divide( 15, 0);
    std::cout <<"result of it.divide(): " << itResult << std::endl;

    dbResult = db.divide( 15.25, 0.00);
    std::cout <<"result of db.divide(): " << dbResult << std::endl;

    dbResult = db.divide( 15.35, -2.54535);
    std::cout <<"result of db.divide(): " << dbResult << std::endl;


    std::cout << "good to go!" << std::endl;
}
