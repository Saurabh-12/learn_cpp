#include<iostream>
#include<array>

int main()
{
    std::array<int, 4> myArray1; // declare an integer array with length 3
//Just like the native implementation of fixed arrays, 
//the length of a std::array must be set at compile time.
myArray1[0] = 11;
myArray1[1] = 44;
myArray1[2] = 13;
myArray1[3] = 41;

//std::array can be initialized using an initializer lists or uniform initialization:

std::array<int, 5> myArray2 = { 1,2,3,4,5}; // initialization list
std::array<int, 5> myArray3 { 9, 7, 5, 3, 1 }; // uniform initialization


for(const auto &ref : myArray1)
{
    std::cout<<" "<<ref<<" ";
}
std::cout<<"\n";


    return 0;
}