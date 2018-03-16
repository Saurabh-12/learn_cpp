#include <iostream>

int main()
{
    const int value = 5;
    const int *ptr = &value; // this is okay, ptr is a non-const pointer that is pointing to a "const int"
    //*ptr = 6;                // not allowed, we can't change a const value

    int value1 = 5;
    const int *ptrs = &value1; // ptr points to a const int

    int value2 = 6;
    ptrs = &value2; // okay, ptr now points at some other const int

//Const pointers
//A const pointer is a pointer whose value can not be changed after initialization
int values = 5;
int *const ptr = &values;
//Just like a normal const variable, a const pointer must be initialized to a value upon declaration.
// This means a const pointer will always point to the same address. 
//In the above case, ptr will always point to the address of value
// (until ptr goes out of scope and is destroyed).
int value11 = 5;
int value22 = 6;
int * const ptr12 = &value11; // okay, the const pointer is initialized to the address of value1
//ptr12 = &value22; // not okay, once initialized, a const pointer can not be changed.
int value3 = 5;
int *const ptr3 = &value3; // ptr will always point to value
*ptr3 = 6; // allowed, since ptr points to a non-const int

//Const pointer to a const value
int value4 = 5;
const int *const ptr4 = &value4;

    return 0;
}