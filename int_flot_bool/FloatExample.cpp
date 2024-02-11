#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Hello Saurabh" << std::endl;
    float f;
    f = 9.87654321f; // f suffix means this number should be treated as a float
    std::cout << f << std::endl;
    f = 987.654321f;
    std::cout << f << std::endl;
    f = 987654.321f;
    std::cout << f << std::endl;
    f = 9876543.21f;
    std::cout << f << std::endl;
    f = 0.0000987654321f;
    std::cout << f << std::endl;

    std::cout << std::setprecision(16); // show 16 digits
    float f1 = 3.33333333333333333333333333333333333333f;
    std::cout << f1 << std::endl;
    double d = 3.3333333333333333333333333333333333333;
    std::cout << d << std::endl;

    return 0;
}