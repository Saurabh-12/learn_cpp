#include <iostream>

void printSize(int *array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

// C++ will implicitly convert parameter array[] to *array
void printArraySize(int array[])
{
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

int main()
{
    std::cout << "Saurabh Sharma\n";

    int array[5] = {9, 7, 5, 3, 1};

    // print the value of the array variable
    std::cout << "The array has address: " << array << '\n';

    // print address of the array elements
    std::cout << "Element 0 has address: " << &array[0] << '\n';

    std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

    int *ptr = array;
    std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer

    //passing fixed arrays to functions
    int array2[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array2) << '\n'; // will print sizeof(int) * array length
 
    printSize(array2); // the array argument decays into a pointer here
    std::cout<<"........................................\n";
    printArraySize(array2);

    return 0;