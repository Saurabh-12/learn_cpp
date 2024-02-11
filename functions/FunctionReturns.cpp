#include<iostream>
#include<array>

//Return by value
int returnByValue(int x)
{
    int value = x * 2;
    return value; // A copy of value will be returned here
} // value goes out of scope here

//Return by address

//this is come mistake done by newer Programmer
int* returnByAddress(int x)
{
    int value = x * 2;
    return &value; // return value by address here
} // value destroyed here

int* allocateArray(int size)
{
    return new int[size];
}

//Return by reference
// Returns a reference to the index element of array
int& getElementbyReference(std::array<int, 25> &array, int index)
{
    // we know that array[index] will not be destroyed when we return to the caller 
    //(since the caller passed in the array in the first place!)
    // so it's okay to return it by reference
    return array[index];
}


int main()
{
    int y = 7;
    //int *ptr = returnByAddress(y);
    //std::cout<<" *ptr "<<*ptr;

    int *array = allocateArray(25);
    std::cout<<"Size of array : "<<sizeof(array)<<"\n";
    delete[] array;

    std::array<int, 25> array1;
    // Set the element of array with index 10 to the value 5
    getElementbyReference(array1, 10) = 5;
    std::cout << array1[10] << '\n';

    return 0;
}