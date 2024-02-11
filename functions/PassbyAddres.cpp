#include<iostream>

//Passing an argument by address involves passing the address of the argument variable 
//rather than the argument variable itself
// Because the argument is an address, the function parameter must be a pointer

void changeVariable(int *ptr)
{
    *ptr = 8;
}

void printAray(int *array, int length)
{
    for (int index = 0; index < length; index++)
        std::cout << array[index] << " ";
}

int main()
{
    int mValue = 5;
    int *ptr1 = &mValue;
    std::cout<<" mValue : "<<mValue << "\n";
    changeVariable(ptr1);
    std::cout<<" mValue : "<<mValue << "\n";
    std::cout<<" ptr1 : "<<*ptr1<< "\n";

    //Pass by address is typically used with pointers, 
    //which most often are used to point to built-in arrays
    int mArray[] = {9, 1, 6,2,7,8,3};
    printAray(mArray, 7);





    return 0;
}