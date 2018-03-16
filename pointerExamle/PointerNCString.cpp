#include<iostream>

int main()
{
    std::cout<<"SSS\n";

    char myName[] = "Alex\n";
    std::cout << myName;

    const char *mName = "Alex\n";
    std::cout << mName;


    return 0;
}