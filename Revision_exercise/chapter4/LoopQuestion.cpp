#include <iostream>

void printNumberPyramid(int num)
{
    int outer = 1;
    
    while(outer<=num){
        
        int inner = 1;

        while(inner<=outer)
        {
            std::cout<<inner++<<" ";
        }
        std::cout<<"\n";
        outer++;
    } 
}

void printReverseNumberPyramid(int num)
{
    int outer = num;

    while(outer>=1)
    {
        int inner = outer;

        while(inner>=1)
        {
            std::cout<<inner--<<" ";
        }
        std::cout<<"\n";
        outer--;
    }
}

void printNumberTringle(int num)
{
    int outer = 1;

    while(outer<=num)
    {
        int inner = num;

        while(inner >= 1)
        {
            if(inner <= outer)
            std::cout<<inner<<" ";
            else
            std::cout<<" ";
            inner--;
        }
        std::cout<<"\n";
        outer++;
    }
}

void printEvenNumber(int num)
{

    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            std::cout << i;
        else
            std::cout << " ";
    }
    std::cout<<"\n";
}

void printAddNumber(int num)
{
    int sum = 0;
    
    for(int i = 1; i <= num; i++)
    {
        sum = sum+i;
    }
    std::cout<<"Sum of Number: "<<sum<<"\n"; 
}

int main(int argc, char const *argv[])
{
    int count = 0;

    char mychar = 'A';
    while (mychar <= 'Z')
    {
        std::cout << mychar << " " << static_cast<int>(mychar) << " ";
        // if the loop variable is divisible by 10, print a newline
        if (mychar % 10 == 0)
            std::cout << "\n";
        ++mychar;
    }
    std::cout<<"\n";
    printNumberPyramid(5);
    std::cout<<"\n";
    printReverseNumberPyramid(5);
    std::cout<<"\n";
    printNumberTringle(5);
    std::cout<<"\n";
    printEvenNumber(20);
    std::cout<<"\n";
    printAddNumber(11);

    return 0;
}
