#include <iostream>
#include <cstring>

int main()
{

    char myString[20] = "Saurabh";
    std::cout << "MyString= " << myString << '\n';
    myString[7] = 'k';
    std::cout << "MyString= " << myString << '\n';
    char userString1[255];
    std::cout << "Enter a String " << '\n';
    std::cin.getline(userString1, 255);
    int spaceCount = 0;

    for (int i = 0; i < strlen(userString1); i++)
    {
        // If the current character is a space, count it
        if (userString1[i] == ' ')
        {
            spaceCount++;
        }
    }
    std::cout << "No. of Space Found: " << spaceCount << '\n';

    std::cout << "Enter Second Syting " << '\n';
    char userString2[255];
    std::cin.getline(userString2, 255);

    int len1, len2;
    len1 = strlen(userString1);
    len2 = strlen(userString2);
    if (len1 == len2)
    {
        if (strcmp(userString1, userString2) == 0)
        {
            std::cout << userString1 << " and " << userString2 << " are equal" << '\n';
        }
        else
        {
            std::cout << userString1 << " and " << userString2 << " are NOT equal" << '\n';
        }
    }
    else
    {
        std::cout << userString1 << " and " << userString2 << " NOT equal" << '\n';
    }

    return 0;
}