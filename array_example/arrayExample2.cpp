#include <iostream>

int main()
{
    std::cout << "Hey!! HRU" << std::endl;
    int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};
    int length = sizeof(array) / sizeof(array[0]);

        // First, read in valid input from user
    int number = 0;
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;
 
        // if the user entered an invalid character
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags
 
        std::cin.ignore(32767, '\n'); // ignore any extra characters in the input buffer
 
    } while (number < 1 || number > 9);


        for (int i = 0; i < length; i++)
        {
            std::cout << " array[" << i << "] : " << array[i] << "\n";
        }

        std::cout << " array[" << number << "] : " << array[number] << "\n";

    return 0;
}
