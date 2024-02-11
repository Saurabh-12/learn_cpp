#include<iostream>

int getUserInput()
{
    int x;
    std::cout<<"Enter a Number \n";
    std::cin>>x;
    return x;
}

int calculate(int x, int y, char opr)
{
    switch(opr)
    {
        case '+' :
        return x+y;
        case '-' :
        return x-y;
        case '*' :
        return x*y;
        case '/' :
        return x/y;
        case '%' :
        return x%y;
        default :
        std::cout<<"Unhandled case \n";
        return 0;
    }
}

int main()
{

    int x = getUserInput();
    int y = getUserInput();
    char opr;
    std::cout<<"Enter a mathematical operator (+, -, *, /, or %): ";
    std::cin>>opr;

    std::cout<< x <<" "<< opr <<" "<< y <<" is "<<calculate(x,y,opr)<<"\n";

    return 0;
}