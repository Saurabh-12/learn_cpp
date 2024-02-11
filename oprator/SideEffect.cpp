#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x = 1;
    x = x++;

    std::cout << " x " << x << "\n";

    int y = 5;
    // is this 5 + 6, or 6 + 6? It depends on what order your compiler evaluates the function arguments in
    int value = add(y, ++y);

    // value could be 11 or 12, depending on how the above line evaluates!
    std::cout << value << "\n";
}