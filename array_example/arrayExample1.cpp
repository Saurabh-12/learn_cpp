#include <iostream>

int main()
{
    std::cout << "Welcome Saurabh...\n";

    int prime[5]; // hold the first 5 prime numbers
    prime[0] = 2; // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;

    std::cout << "The lowest prime number is: " << prime[0] << "\n";
    std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << "\n";

    struct Rectangle
    {
        int length;
        int width;
    };
    Rectangle rects[5]; // declare an array of 5 Rectangle
    rects[0].length = 24;
    rects[0].width = 20;
    std::cout << "Rect length " << rects[0].length << "\n";

    // using a literal constant
    int array[5]; // Ok

// using a macro symbolic constant
    #define ARRAY_LENGTH 5
    int arr[ARRAY_LENGTH]; // Syntactically okay, but don't do this

    // using a symbolic constant
    const int arrayLength = 5;
    int arrs[arrayLength]; // Ok

    // using an enumerator
    enum ArrayElements
    {
        MAX_ARRAY_LENGTH = 5
    };
    int arrays[MAX_ARRAY_LENGTH]; // Ok

    // using a non-const variable
    int length;
    std::cin >> length;
    int array1[length]; // Not ok -- length is not a compile-time constant!

    // using a runtime const variable
    int temp = 5;
    // the value of length isn't known until runtime, so this is a runtime constant, 
    // not a compile-time constant!
    const int len = temp; 
    int array2[len];       // Not ok

    return 0;
}
