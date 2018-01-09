#include <iostream>
#include <iomanip>

int main()
{

    std::cout << "Welcome Saurabh" << std::endl;
    double zero = 0.0;
    double posinf = 5.0 / zero; // positive infinity
    std::cout << posinf << "\n";

    double neginf = -5.0 / zero; // negative infinity
    std::cout << neginf << "\n";

    double nan = zero / zero; // not a number (mathematically invalid)
    std::cout << nan << "\n";

    bool b1 = true; // copy initialization
    bool b2(false); // direct initialization
    bool b3{true};  // uniform initialization (C++11)
    b3 = false;     // assignment
 //std::cout << std::noboolalpha; // print bools as true or false
    std::cout << true << std::endl;  // true evaluates to 1
    std::cout << !true << std::endl; // !true evaluates to 0

    std::cout << b3 << std::endl;  // b is false, which evaluates to 0
    std::cout << !b3 << std::endl; // !b is true, which evaluates to 1

    return 0;
}