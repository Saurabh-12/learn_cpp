#include<iostream>

struct Something
{
    int nX, nY, nZ;
};

int main()
{
    int value = 5;
    int *iPtr = &value;

    std::cout<<"Value "<<value<<"\n";
    std::cout << &value << '\n'; // print the address of variable value
    std::cout << iPtr << '\n'; // print the address that ptr is holding
    std::cout<<"*iPtr "<<*iPtr<<"\n";

    int x(4);
	std::cout << typeid(&x).name()<<"\n";

    int *IntPtr = &x;
    std::cout<<" IntPtr "<<IntPtr<<"\n";
    std::cout<<"*IntPtr "<<*IntPtr<<"\n";

    char *chPtr; // chars are 1 byte
    int *iPtr1; // ints are usually 4 bytes

Something *somethingPtr; // Something is probably 12 bytes
std::cout << sizeof(chPtr) << '\n'; // prints 8
std::cout << sizeof(iPtr1) << '\n'; // prints 8
std::cout << sizeof(somethingPtr) << '\n'; // prints 8

    return 0;
}