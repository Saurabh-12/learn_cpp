#include<iostream>

int main()
{
   int value = 5; // normal integer
    int &ref = value; // reference to variable value
 
    value = 6; // value is now 6
    ref = 7; // value is now 7
 
    std::cout << value<<"\n"; // prints 7
    ++ref;
    std::cout << value<<"\n"; // prints 8

    std::cout << &value<<"\n"; // prints 0012FF7C
    std::cout << &ref<<"\n"; // prints 0012FF7C

//References can not be reassigned
    int value1 = 5;
    int value2 = 6;
 
    int &ref11 = value1; // okay, ref is now an alias for value1
    std::cout<<" ref11 "<<ref11<<"\n";
    std::cout<<" Value1 "<<value1<<"\n";
     std::cout<<" Value2 "<<value2<<"\n";
    ref11 = value2; // assigns 6 (the value of value2) to value1 -- does NOT change the reference!

    std::cout<<" ref11 "<<ref11<<"\n";
    std::cout<<" Value1 "<<value1<<"\n";
     std::cout<<" Value2 "<<value2<<"\n";


    return 0;
}