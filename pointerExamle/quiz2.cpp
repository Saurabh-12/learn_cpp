#include <iostream>

int main()
{
    const std::string names[] = {"Alex", "Betty", "Caroline", "Dave", "Emily",
                                 "Fred", "Greg", "Holly"};

    std::cout << "Enter a name: \n";
    std::string name;
    std::cin >> name;
    bool found = false;

    for (const auto &searchName : names)
    {
        if (searchName == name)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        std::cout << name << " was found.\n";
    }
    else
    {
        std::cout << name << " was not found.\n";
    }

    return 0;
}