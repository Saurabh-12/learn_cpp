#include<iostream>

void printString(const char *cstring)
{
    // Only print if cstring is non-null
    if (cstring)
        std::cout << cstring;
}




int main()
{
    return 0;
}