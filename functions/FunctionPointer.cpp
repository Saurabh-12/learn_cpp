#include<iostream>

int foo()
{
    return 9;
}

int goo()
{
    return 6;
}

// function prototypes
int foo1();
double goo1();
int hoo(int x);

int main()
{
    int a = foo();
    std::cout<<"a : "<<a<<"\n";

    std::cout<<"foo() call : "<<foo<<"\n";
    std::cout << reinterpret_cast<void*>(foo); // Tell C++ to interpret function foo as a void pointer

    int (*fcnPtr)() = foo; // fcnPtr points to function foo
    fcnPtr = goo; // fcnPtr now points to function goo

    //Note that the type (parameters and return type) of the function pointer must match
    // the type of the function
    // function pointer assignments
    int (*fcnPtr1)() = foo1;    // okay
    int (*fcnPtr2)() = goo1;    // wrong -- return types don't match!
    double (*fcnPtr4)() = goo1; // okay
    fcnPtr1 = hoo;             // wrong -- fcnPtr1 has no parameters, but hoo() does
    int (*fcnPtr3)(int) = hoo; // okay

    

    return 0;
}