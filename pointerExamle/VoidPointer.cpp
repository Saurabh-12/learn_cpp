#include <iostream>

//A void pointer can point to objects of any data type

struct Emplyoe
{
    int age ;
    float salary;
    std::string name;

};

enum Type
{
    INT,
    FLOAT,
    CSTRING
};

void printValue(void *ptr, Type type)
{
    switch (type)
    {
        case INT:
            std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and dereference
            break;
        case FLOAT:
            std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and dereference
            break;
        case CSTRING:
            std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer (no dereference)
            // std::cout knows to treat char* as a C-style string
            // if we were to dereference the result, then we'd just print the single char that ptr is pointing to
            break;
    }
}

int main()
{
    int nValue = 7;
    float fValue = 6.90;
    char szValue[] = "Mollie";
 
    printValue(&nValue, INT);
    printValue(&fValue, FLOAT);
    printValue(szValue, CSTRING);

    Emplyoe emp;

    void *ptr;

    ptr = &nValue;
    ptr = &fValue;
    ptr = &emp;
    

    return 0;
}