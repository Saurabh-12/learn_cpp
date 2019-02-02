#include<iostream>

int main(int argc, char const *argv[])
{
    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;


	std::cout << 5.0 << std::endl;
    std::cout << 5.107 << std::endl;
	std::cout << 6.7f << std::endl;
	std::cout << 9876543.21 << std::endl;

        double zero = 0.0;
    double posinf = 5.0 / zero; // positive infinity
    std::cout << posinf << std::endl;
 
    double neginf = -5.0 / zero; // negative infinity
    std::cout << neginf << std::endl;
 
    double nan = zero / zero; // not a number (mathematically invalid)
    std::cout << nan << std::endl;

    return 0;
}
