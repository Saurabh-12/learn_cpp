#include<iostream>

int main()
{
    const int value1 = 5;
    int value2(8);

    const int *ptr1;
    int *ptr2;

    ptr1 = &value2;
    ptr2 = &value2;

    value2 = 12;

    //*ptr1 = 6; // ptr treats its value as const, so changing the value through ptr is not legal
    ptr1 = &value1;

    int *const ptr3 = &value2;
    
    int value = 5;
    int *const ptr = &value; // ptr will always point to value
    *ptr = 6; // allowed, since ptr points to a non-const int
    


    


    return 0;
}