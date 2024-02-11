#include <iostream>
#include <array>
#include <algorithm>

void printLength(const std::array<double, 5> &myarray)
{
    std::cout << "length: " << myarray.size() << "\n";
}

//An introduction to std::array in C++11
//std::array provides fixed array functionality that won’t decay when passed into a function

int main()
{
    std::array<int, 3> myarray1;                   // declare an integer array with length 3
    std::array<int, 5> myarray2 = {9, 7, 5, 3, 1}; // initialization list
    std::array<int, 5> myarray3{9, 7, 5, 3, 1};    // uniform initialization

    //size and sorting
    std::array<double, 5> myarray4{9.0, 7.2, 5.4, 3.6, 1.8};
    std::cout << "length: " << myarray4.size() << "\n";
    printLength(myarray4);

    std::array<int, 5> myarray5{7, 3, 1, 9, 5};
    //std::sort(myarray5.begin(), myarray5.end()); // sort the array forwards
    std::sort(myarray5.rbegin(), myarray5.rend()); // sort the array backwards

    for (const auto &element : myarray5)
        std::cout << element << ' ';

    return 0;
}