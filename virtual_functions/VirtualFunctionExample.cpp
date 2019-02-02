#include<iostream>

class Base
{
    public:
    virtual const char* getName(){ return "Base ";}

};

class Derived : public Base
{
    public:
    virtual const char* getName(){ return "Derived ";}

};

class A
{
    public:
    virtual const char* getName(){ return "A \n";}

};

class B : public A
{
    public:
    virtual const char* getName() { return "B \n"; }
};

class C : public B
{
    public:
    virtual const char* getName(){ return "C \n"; }
};

class D: public C
{
    public:
    virtual const char* getName() { return "D \n"; }
};

int main()
{
    Derived d;
    Base &rbase = d;
    std::cout<<"rbase : "<<rbase.getName()<<"\n";

    C c;
    A &rBase = c;
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}