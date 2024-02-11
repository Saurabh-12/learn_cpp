#include <iostream>
#include <math.h>   //for sin() and cos()

void refFunction1(int &y)
{
    y = y + 1;
}

void getSinCos(double degrees, double &sinOut, double &cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    const double pi = 3.14159265358979323846; // the value of pi
    double radians = degrees * pi / 180.0;
    sinOut = sin(radians);
    cosOut = cos(radians);
}

int main()
{
    int x = 5;

    refFunction1(x);

    std::cout << " x : " << x << "\n";

    //Sometimes we need a function to return multiple values. 
    //However, functions can only have one return value. 
    //One way to return multiple values is using reference parameters:
    double sin(90.0);
    double cos(45.0);
 
    // getSinCos will return the sin and cos in variables sin and cos
    getSinCos(30.0, sin, cos);
 
    std::cout << "The sin is " << sin << '\n';
    std::cout << "The cos is " << cos << '\n';

    return 0;
}
//When to use pass by reference:
     // When passing structs or classes (use const if read-only).
     // When you need the function to modify an argument.

//When not to use pass by reference:
     //When passing fundamental types (use pass by value).
    //When passing built-in arrays (use pass by address).