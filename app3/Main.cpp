#include <iostream>
#include "Math.h"
#include "Geometry.h"
#include "Square.h" // square.h is also included once here

int main()
{
    std::cout<< "Enter a number"<<std::endl;
    int x = 0;
    std::cin >> x;
    std::cout<<"Squre of Number "<<x <<" is "<<getSquareSide(x)<<std::endl;

    std::cout << "Please enter second number " << std::endl;
    int y = 0;
    std::cin >>y;
    std::cout << "Area of Squre is "<<getSquareArea(y)<<std::endl;
    std::cout << "A square of length "<<y <<" has perimeter length "<< getSquarePerimeter(y) 
    << std::endl;



return 0;
}