#include <iostream>

int getSumOfDigit(int num)
{
    if (num < 10)
        return num;
    else
        return getSumOfDigit(num / 10) + num % 10;
}

// h/t to reader Gapo for this solution
void printBinary(int x)
{
    // Termination case
    if (x == 0)
        return;

    // Recurse to the next bit
    printBinary(x / 2);

    // Print out the remainders (in reverse order)
    std::cout << x % 2;
}

int main()
{
    std::cout << getSumOfDigit(93427) << "\n";

    std::cout << "Enter a Number "<<"\n";
    int x;
    std::cin >>x;
    printBinary(x);
    std::cout << "\n";

    return 0;
}