#include <iostream>

int main()
{
    // dynamically allocate an integer,  By default, if new fails, a bad_alloc exception is thrown
    int *ptr = new int;

    // value will be set to a null pointer if the integer allocation fails
    int *ptr2 = new (std::nothrow) int;

    *ptr = 7; //put a value in that memory location
    *ptr2 = 9;

    // return the memory to the operating system.  ptr is now a dangling pointer.
    delete ptr;

    // Dereferencing a dangling pointer will cause undefined behavior
    std::cout << *ptr;

    // trying to deallocate the memory again will also lead to undefined behavior.
    delete ptr;

    int *value = new (std::nothrow) int; // ask for an integer's worth of memory
    if (!value)  // handle case where new returned null
    {
        // Do error handling here
        std::cout << "Could not allocate memory";
    }

    //Null pointers and dynamic memory allocation uses

    if (!ptr) // If ptr isn't already allocated, allocate it
        ptr = new int;

    //Deleting a null pointer has no effect. Thus, there is no need for the following:
    if (ptr)
        delete ptr;
//Instead, you can just write:
//delete ptr;

//Memory leaks happen when your program loses the address of some bit of dynamically allocated memory 
//before giving it back to the operating system
int val = 5;
int *ptrnew = new int; // allocate memory
ptrnew = &val; // old address lost, memory leak results

//This can be fixed by deleting the pointer before reassigning it
delete ptr; // return memory back to operating system

    return 0;
}