#include<iostream>

int passByValue(int i)
{
    i = 99;
    return i;
}

void passByArray(int ii[5])
{
    ii[0] = 1;
    ii[1] = 2;
    ii[2] = 3;
    ii[3] = 4;
    ii[4] = 5;
}


int main()
{
    int num = 12;
    std::cout<<"Num value before passing to Function   "<<num<<"\n";
    int num1 = passByValue(num);
    std::cout<<"Num value After passing to Function   "<<num<<"\n";
    std::cout<<"Function return value   "<<num1<<"\n";

    int params[5] = {11, 16, 25, 30, 40};
    std::cout<<"Array Value before passing to function"<<"\n";
    
    for(int i = 0; i < 5; i++)
    {
        std::cout<<" count "<<i+1<<" "<<params[i]<<" ";
    }
    std::cout<<"\n";
    passByArray(params);

    std::cout<<"Array Value before passing to function"<<"\n";
    for(int i = 0; i < 5; i++)
    {
        std::cout<<" count "<<i+1<<" "<<params[i]<<" ";
    }
    std::cout<<"\n";
    

    return 0;
}