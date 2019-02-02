#include <iostream>

struct Employee
{
    short id;
    int age;
    double wage;
};

struct Rectangle
{
	double length = 1.0; // non-static member initialization
	double width = 1.0;
};

int main()
{
    Employee jonh;
    jonh.id = 1;
    jonh.age = 28;
    jonh.wage = 10000.560;

    Employee Joe;
    Joe.id = 2;
    Joe.age = 38;
    Joe.wage = 30000.560;

    int totalAge = Joe.age + jonh.age;
    std::cout<<"Total Age "<<totalAge<<"\n";

    if (Joe.wage > jonh.wage)
        std::cout << "Joe makes more than Jonh\n";
    else if (Joe.wage < jonh.wage)
        std::cout << "Joe makes less than Jonh\n";
    else
        std::cout << "Joe and Jonh make the same amount\n";

//nitializer list
Employee Joe1 = { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
Employee frank = { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)

//C++11 Uniform initialization
Employee joe { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
Employee frank1 { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)

Rectangle x{ 2.0, 2.0 }; // uniform initialization

    return 0;
}