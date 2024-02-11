#include <iostream>

//A pointer to a pointer is exactly what you’d expect:
//a pointer that holds the address of another pointer.

int main()
{
    int nValue = 5;

    int *ptr; //pointer to an int, one asterisk

    int **ptrptr; //pointer to a pointer to an int, two asterisks

    ptr = &nValue;
    std::cout << *ptr << "\n" ; // dereference pointer to int to get int value

    ptrptr = &ptr;
    // first dereference to get pointer to int, second dereference to get int value
    std::cout<<"Pointer of Pointer Value: " << **ptrptr <<"\n"; 

    

    return 0;
}