
#include <iostream>

int main()
{
    std::cout << "Enter First Integer" << "\n";
    int x;
    std::cin >> x;

    std::cout << "Enter second Integer" << "\n";
    int y;
    std::cin >> y;

    if(x == y)
        std::cout << x <<" Equals " << y << "\n";
        if (x != y)
        std::cout << x << " does not equal " << y << "\n";
    if (x > y)
        std::cout << x << " is greater than " << y << "\n";
    if (x < y)
        std::cout << x << " is less than " << y << "\n";
    if (x >= y)
        std::cout << x << " is greater than or equal to " << y << "\n";
    if (x <= y)
        std::cout << x << " is less than or equal to " << y << "\n";

    return 0;
}