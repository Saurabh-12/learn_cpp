#include<iostream>

int sumTo(int value)
{
    int sum = 0;
    for (int i = 1; i <= value; i++)
        sum+=i;

    return sum;
}

int main()
{

    for (int i = 1, j = 9; i < 10; i++, j--)
        std::cout << i << " " << j << " \n";

    std::cout<<"....................\n";

    for (int p = 0; p <= 20; p+=2)
        std::cout << p << " \n";

std::cout<<"....................\n";
std::cout<<sumTo(5)<<"\n";

    return 0;
}