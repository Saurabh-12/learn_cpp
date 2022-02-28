#include <iostream>

int main()
{
    using namespace std;

//------ const pointer 1 ---------------------------//
    const int value = 5;
    const int *ptr = &value; // this is okay, ptr is a non-const pointer that is pointing to a "const int"
    //*ptr = 6;                // not allowed, we can't change a const value
    cout<< "ptr "<<*ptr<<" value = "<<value<<'\n';

    int value1 = 15;
    ptr = &value1; // ptr points to a const int
    //*ptr = 45; not allowed  we can not change constant value
    cout<< "ptr "<<*ptr<<" value1 = "<<value1<<" value = "<<value<<'\n';

    int value2 = 16;
    ptr = &value2; // okay, ptr now points at some other const int
    cout<< "ptr "<<*ptr<<" value2 = "<<value2<<" value = "<<value<<'\n';

//---------------- Const pointers 2 ---------------------------//
//A const pointer is a pointer whose value can not be changed after initialization
int values = 5;
int *const Constptr = &values;
//Just like a normal const variable, a const pointer must be initialized to a value upon declaration.
// This means a const pointer will always point to the same address. 
//In the above case, ptr will always point to the address of value
// (until ptr goes out of scope and is destroyed).
cout<< "Constptr "<<*Constptr<<" values = "<<values<<'\n';
int value11 = 5;
int value22 = 6;
*Constptr = 123;
int * const ptr12 = &value11; // okay, the const pointer is initialized to the address of value1
cout<< "ptr12 "<<*ptr12<<" value11 = "<< value11<<" Constptr = "<<*Constptr<<" values = "<<values<<'\n';
//ptr12 = &value22; // not okay, once initialized, a const pointer can not be changed.

int value3 = 95;
int *const ptr3 = &value3; // ptr3 will always point to value3
cout <<" ptr3 = "<<*ptr3<<" value3 = "<<value3<<'\n';
*ptr3 = 46; // allowed, since ptr points to a non-const int
// now value3 is 46
cout << " ptr3 = "<<*ptr3<<" value3 = "<<value3<<'\n';

//--------------const pointer 3-----------------------
//Const pointer to a const value
//address contained in the pointer and the value being pointed to are constant and cannot be changed (most restrictive variant)
int value4 = 5;
const int *const ptr4 = &value4;
cout<<" ptr4 = "<<*ptr4<<" value4 = "<<value4<<'\n';
int value5 = 80;
//*ptr4 = 9;
//ptr4 = &value5;
cout<<"ptr4 = "<<*ptr4<<'\n';

    return 0;
}