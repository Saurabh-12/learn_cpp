#include <iostream>
#include "Add.h"
 
// needed so main.cpp knows that add() is a function declared elsewher
//int addTwoNumber(int x, int y);

int main()
{
    std::cout << "Please Enter first number " << std::endl;
    int x = 0;
    std::cin >> x;
    std::cout <<"Please enter second number " << std::endl;
    int y = 0;
    std::cin >> y;
    std::cout << "Addition of two number "<< addTwoNumber(x,y) << std::endl;
    
    return 0;
}
