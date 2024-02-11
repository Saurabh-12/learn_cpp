#include <iostream>
#include "IntArray.h"

int main()
{
    // Declare an array with 10 elements
    IntArray intarray(10);

    // Fill the array with numbers 1 through 10
    for (int i = 0; i < 10; i++)
        intarray[i] = i + 1;

    // Resize the array to 8 elements
    intarray.resize(8);

    // Insert the number 20 before element with index 5
    intarray.insertBefore(20, 5);

    // Remove the element with index 3
    intarray.remove(3);

    // Add 30 and 40 to the end and beginning
    intarray.insertAtEnd(30);
    intarray.insertAtBeginning(40);

    // Print out all the numbers
    for (int j = 0; j < intarray.getLength(); j++)
        std::cout << intarray[j] << " ";
    std::cout << "\n";

    IntArray array{5, 4, 3, 2, 1}; // initializer list
    for (int count = 0; count < array.getLength(); ++count)
        std::cout << array[count] << ' ';
    std::cout << "\n";

    return 0;
}