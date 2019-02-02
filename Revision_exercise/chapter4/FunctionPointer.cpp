#include<iostream>

int doSomething()
{
    return 5;
}

int foo()
{
    return 5;
}
 
int goo()
{
    return 6;
}
 

int main()
{
    std::cout<<"DoSomethong: "<<doSomething()<<"\n";

    int (*fcnPtr)() = foo; // fcnPtr points to function foo
    fcnPtr = goo; // fcnPtr now points to function goo

    return 0;
}