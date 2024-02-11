#include <iostream>

void changeN(int &ref)
{
    ref = 6;
}
//References to const values are particularly useful as function parameters 
//because of their versatility
void printIt(const int &x)
{
    std::cout << x;
}

int main()
{
    int value = 5;    // normal integer
    int &ref = value; // reference to variable value

    value = 6; // value is now 6
    ref = 7;   // value is now 7

    std::cout << value << "\n"; // prints 7
    ++ref;
    std::cout << value << "\n"; // prints 8

    std::cout << &value << "\n"; // prints 0012FF7C
    std::cout << &ref << "\n";   // prints 0012FF7C

    int x = 5;
    int &ref1 = x; // okay, x is an non-const l-value
                   //References to non-const values, which can only be initialized with non-const l-values,
    const int y = 7;
    //int &ref2 = y; // not okay, y is a const l-value

    //int &ref3 = 6; // not okay, 6 is an r-value

    int n = 5;
    std::cout << n << '\n';
    changeN(n); // note that this argument does not need to be a reference
    std::cout << n << "\n";

    //Reference to const value
    const int vala = 5;
    const int &refa = vala; // ref is a reference to const value

    //References to const values can be initialized with non-const l-value, const l-values, and r-values.
    int x1 = 5;
    const int &refa1 = x1; // okay, x is a non-const l-value
    const int y1 = 7;
    const int &refa2 = y1; // okay, y is a const l-value
    const int &refa3 = 6; // okay, 6 is an r-value

    int valu = 9;
    const int &refu = valu; // create const reference to variable value
 
    valu = 6; // okay, value is non-const
    //refu = 7; // illegal -- ref is const
    std::cout<<"Valu: "<<valu<<"\n";
    std::cout<<"refu: "<<refu<<"\n";

    int a = 1;
    printIt(a); // non-const l-value
 
    const int b = 2;
    printIt(b); // const l-value
 
    printIt(3); // literal r-value
 
    printIt(2+b); // expression r-value

    return 0;
}