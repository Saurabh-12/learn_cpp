#include <iostream>

int main()
{
    const int value = 5;
    const int *ptr = &value; // this is okay, ptr is a non-const pointer that is pointing to a "const int"
    //*ptr = 6;                // not allowed, we can't change a const value

    int value1 = 5;
    const int *ptr1 = &value1; // ptr points to a non const int

    int value2 = 6;
    ptr1 = &value2; // okay, ptr now points at some other non const int

//Const pointers
//A const pointer is a pointer whose value can not be changed after initialization
int value3 = 7;
int *const ptr2 = &value3;
//Just like a normal const variable, a const pointer must be initialized to a value upon declaration.
// This means a const pointer will always point to the same address. 
//In the above case, ptr will always point to the address of value
// (until ptr goes out of scope and is destroyed).

//ptr2 = &value1;  // will throw CTE because we are trying to change the address value of ptr2;

int value4 = 5;
int value5 = 6;
int * const ptr3 = &value4; // okay, the const pointer is initialized to the address of value4
//ptr3 = &value5; // not okay, once initialized, a const pointer can not be changed.
int value6 = 5;
int *const ptr4 = &value6; // ptr will always point to value
*ptr4 = 6; // allowed, since ptr points to a non-const int

//Const pointer to a const value
int value7 = 5;
const int *const ptr5 = &value7;
int value8 = 8;
const int value9 = 9;
//ptr5 = &value8; // not okay, ptr5 is a const pointer to a const value, so we can't change the address it points to
//*ptr5 = value9; // ptr5 points to a constant value, hence you can not change it.

    return 0;
}