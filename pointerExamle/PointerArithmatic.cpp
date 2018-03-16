#include<iostream>

int main()
{
      int value = 7;
    int *ptr = &value;
 
    std::cout << ptr << '\n';
    std::cout << ptr+1 << '\n';
    std::cout << ptr+2 << '\n';
    std::cout << ptr+3 << '\n';

       int array [5] = { 9, 7, 5, 3, 1 };
 
     std::cout << &array[1] << '\n'; // print memory address of array element 1
     std::cout << array+1 << '\n'; // print memory address of array pointer + 1 
 
     std::cout << array[1] << '\n'; // prints 7
     std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)

     int array2[] = { 8, 4, 9, 7, 1 };
 
    std::cout << "Element 0 is at address: " << &array2[0] << '\n';
    std::cout << "Element 1 is at address: " << &array2[1] << '\n';
    std::cout << "Element 2 is at address: " << &array2[2] << '\n';
    std::cout << "Element 3 is at address: " << &array2[3] << '\n';

    std::cout << "Element 0 is at address: "<<array2<<"\n";
    std::cout << "Element 1 is at address: "<<(array2+1)<<"\n";
    std::cout << "Element 2 is at address: "<<(array2+2)<<"\n";


    return 0;
}