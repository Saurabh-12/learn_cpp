#include <iostream>

int main()
{
    using namespace std;

//------ const pointer 1 ---------------------------//
    const int value = 5;
    const int *ptr = &value; // this is okay, ptr is a non-const pointer that is pointing to a "const int"
    //*ptr = 6;                // not allowed, we can't change a const value
    cout<< "ptr "<<*ptr<<" value = "<<value<<'\n';

    int value1 = 5;
    const int *ptr1 = &value1; // ptr points to a non const int

    int value2 = 6;
    ptr1 = &value2; // okay, ptr now points at some other non const int
   
    //*ptr1 = 45; //not allowed  we can not change constant value
    cout<< "ptr1 "<<*ptr1<<" value1 = "<<value1<<" value 2= "<<value2<<'\n';

//---------------- Const pointers 2 ---------------------------//
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
int *const ptr4 = &value4; // ptr will always point to value
*ptr4 = value5; // allowed, since ptr points to a non-const int

//Const pointer to a const value
int value6 = 5;
const int *const ptr5 = &value6;
int value8 = 8;
const int value9 = 9;
//ptr5 = &value8; // not okay, ptr5 is a const pointer to a const value, so we can't change the address it points to
//*ptr5 = value9; // ptr5 points to a constant value, hence you can not change it.
cout<< "Constptr "<<*ptr5<<" values = "<<value6<<'\n';

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