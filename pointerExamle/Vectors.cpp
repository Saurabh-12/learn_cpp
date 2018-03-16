#include <iostream>
#include <vector>

int main()
{
    // no need to specify length at initialization
    std::vector<int> array;

    // use initializer list to initialize array
    std::vector<int> array2 = {9, 7, 5, 3, 1};

    // use uniform initialization to initialize array (C++11 onward)
    std::vector<int> array3{9, 7, 5, 3, 1};

    std::cout << "The length is: " << array3.size() << '\n';

    //Resizing a built-in dynamically allocated array is complicated.
    //Resizing a std::vector is as simple as calling the resize() function

    array3.resize(7);
    std::cout << "The length is: " << array3.size() << '\n';
    for (const auto &element : array3)
        std::cout << element << " ";

//Resizing a vector is computationally expensive, so you should strive to minimize 
//the number of times you do so.
    
    array3.resize(3);
    std::cout << "\nThe lenght is : " << array3.size() << '\n';
    for (const auto &ele : array3)
        std::cout << ele << " ";
    std::cout << "\n";


    return 0;
}