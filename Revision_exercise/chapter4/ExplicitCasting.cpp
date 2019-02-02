
/***
 * There are 5 type casting avilable in Cpp
 * C style
 * Static 
 * Dynamic
 * const
 * reinterpret
 * Avoid const casts and reinterpret casts unless you have a very good reason to use them
 * C-style casts are not checked by the compiler at compile time, 
 * C-style casts can be inherently misused, Consequently, C-style casts should generally be avoided.
 * 
 * **/
#include <iostream>

int main()
{
    using std::cout;
    //C-Style
    int i1 = 10;
    int i2 = 4;
    float f = (float)i1 / i2;
    cout<<" Foat f "<<f<<"\n";

//Static cast 
char c = 'a';
cout << static_cast<int>(c) << std::endl; // prints 97, not 'a'

int int1 = 10;
int int2 = 4;
float float1 = static_cast<float>(int1) / int2;
cout << " float f2 "<<float1<<"\n";

    return 0;
}