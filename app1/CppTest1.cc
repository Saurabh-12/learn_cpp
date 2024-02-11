#include<iostream>

int add(int x, int y);

int main ()
{

std::cout << "Enter 1st Number ";
int x;
std::cin >>x;
std::cout << "Enter second Number ";
int y;
std::cin >> y;

int result = add(x,y);
std::cout << "Sum of "<<x << " and " <<y<<" = " <<result << std::endl;


return 0;
}
