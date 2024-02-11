#include<iostream>

void setToNull(int *tempPtr)
{
    // we're making tempPtr point at something else, not changing the value that tempPtr points to.
    tempPtr = nullptr; // use 0 instead if not C++11
}

//Passing addresses by reference
void setToNull1(int *&tempPtr)
{
    tempPtr = nullptr;

}

int main()
{

     // First we set ptr to the address of five, which means *ptr = 5
    int five = 5;
    int *ptr = &five;
	
    // This will print 5
    std::cout << *ptr;
 
    // tempPtr will receive a copy of ptr
    setToNull1(ptr);
 
    // ptr is still set to the address of five!
 
    // This will print 5
    if (ptr)
        std::cout << *ptr;
    else
        std::cout << " ptr is null";

    return 0;
}