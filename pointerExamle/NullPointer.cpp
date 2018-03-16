#include <iostream>

void doSomething(int *ptr)
{
    if (ptr)
        std::cout << "You passed in " << *ptr << '\n';
    else
        std::cout << "You passed in a null pointer\n";
}

int main()
{
    std::cout << "Welcme Saurbh \n";
    int *ptr(0);

    std::cout << "Null pointer: " << ptr << "\n";

    int *ptr2; // ptr2 is uninitialized
    ptr2 = 0;  // ptr2 is now a null pointer

    double *ptr3(0);

    if (ptr3)
        std::cout << "ptr is pointing to a double value.";
    else
        std::cout << "ptr is a null pointer.\n";

int *ptr4(NULL); // assign address 0 to ptr

//Starting with C++11, this should be favored instead of 0 when we want a null pointer:
int *ptr5 = nullptr; // note: ptr is still an integer pointer, just set to a null value (0)

 doSomething(nullptr); // the argument is definitely a null pointer (not an integer)

    return 0;
}