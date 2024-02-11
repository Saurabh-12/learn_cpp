#include <iostream>

int main(){

    int x = 7;
    int y = 4;
 
    std::cout << "int / int = " << x / y << "\n";
    std::cout << "double / int = " << static_cast<double>(x) / y << "\n";
    std::cout << "int / double = " << x / static_cast<double>(y) << "\n";
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n";
    std::cout << "float / flaot = " << static_cast<float>(x) / static_cast<float>(y) << "\n";


     // count holds the current number to print
    int count = 1; // start at 1
 
    // Loop continually until we pass number 100
    while (count <= 100)
    {
        std::cout << count << " "; // print the current number
 
        // if count is evenly divisible by 20, print a new line
        if (count % 20 == 0)
            std::cout << "\n";
 
        count = count + 1; // go to next number
    } // end of while
 

    return 0;
}