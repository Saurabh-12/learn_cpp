#include <iostream>

int main()
{
    int outer = 5;
    while (outer >= 1)
    {
        int inner = outer;
        while (inner >= 1)
            std::cout << inner-- << " ";

        std::cout << "\n";
        --outer;
    }
    std::cout << "......................\n";

    int outer1 = 1;
    while (outer1 < 6)
    {
        int inner1 = 1;
        while (inner1 <= outer1)
        {
            std::cout << inner1++ << " ";
        }
        std::cout << "\n";
        ++outer1;
    }
    std::cout << "......................\n";
    int outer2 = 1;
    while (outer2 <= 5)
    {
        int inner2 = 5;
        while (inner2 >= 1)
        {
            // The first number in any row is the same as the row number
            // So number should be printed only if it is <= the row number, space otherwise
            if (inner2 <= outer2)
                std::cout << inner2 << " ";
            else
                std::cout << "  "; // extra spaces purely for formatting purpose

            --inner2;
        }
        std::cout << "\n";
        ++outer2;
    }

    /* char alphabet = 'A';
    char myChar = 'a';
    while(alphabet<='Z' && myChar<='z')
    {
        std::cout<<alphabet<<" "<<static_cast<int>(alphabet)<<"  "
        <<myChar<<"  "<<static_cast<int>(myChar)<<"\n";
        alphabet++;
        myChar++;
    }
    */
}