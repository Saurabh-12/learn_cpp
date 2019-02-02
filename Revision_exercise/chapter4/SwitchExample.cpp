#include<iostream>

int main()
{

    switch(1)
    {
        int a;
        //int b = 1;
        
        case 1:
        int y; // okay, declaration is allowed within a case
        y = 4; // okay, this is an assignment
        break;
 
    case 2:
        y = 5; // okay, y was declared above, so we can use it here too
        break;
 
    case 3:
        //int z = 4; // illegal, initialization is not allowed within a case
        break;
 
    default:
        std::cout << "default case" << std::endl;
        break;

    }

    return 0;
}