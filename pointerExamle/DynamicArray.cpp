#include<iostream>

int main()
{
    std::cout << "Enter a positive integer: ";
    int length;
    std::cin >> length;
 
    int *array = new int[length]; // use array new.  Note that length does not need to be constant!
 
    std::cout << "I just allocated an array of integers of length " << length << '\n';
 
    array[0] = 5; // set element 0 to value 5
    array[2] = 8; // set element 0 to value 5

    std::cout<<" array[0] "<<array[0]<<"\n";
    std::cout<<"array[1] "<<array[1]<<"\n";
    std::cout<<"array[2] "<<array[2]<<"\n";
    std::cout<<"array[3] "<<array[3]<<"\n";
 
    delete[] array; // use array delete to deallocate array
    array = 0; // use nullptr instead of 0 in C++11

int fixedArray[5] = { 9, 7, 5, 3, 1 }; // initialize a fixed array in C++03
int *array1 = new int[5] { 9, 7, 5, 3, 1 }; // initialize a dynamic array in C++11


int fixedArray1[] {1, 2, 3}; // okay: implicit array size for fixed arrays
 
int *dynamicArray1 = new int[] {1, 2, 3}; // not okay: implicit size for dynamic arrays
 
int *dynamicArray2 = new int[3] {1, 2, 3}; // okay: explicit size for dynamic arrays

    return 0;
}