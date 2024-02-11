#include<iostream>

int getFactorial(int n)
{
    int result;
    if (n < 1)
        result = 1;
    else
        result = (n * getFactorial(n - 1));

    return result;
}

int main()
{
    std::cout << getFactorial(-2)<<"\n";

    return 0;
}