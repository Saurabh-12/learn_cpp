#include <iostream>


void checkEqual(int x, int y)
{
    if (x == y)
        std::cout << "First and Second No are equal" << std::endl;
    else
        std::cout << "First and Second No are NOT equal" << std::endl;
}

int main()
{
    std::cout << "Enter First Number" << std::endl;
    int x;
    std::cin >> x;
    std::cout << "Enter Second Number" << std::endl;
    int y;
    std::cin >> y;

    checkEqual(x, y);

    return 0;
}

