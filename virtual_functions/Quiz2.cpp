#include<iostream>

class A
{
    public:
    virtual const char* getName() const { return "Class A ";}

};

class B : public A
{
    public:
    virtual const char* getName() { return "Class B";}

};

class C : public B
{
    public:
    virtual const char* getName() { return "Class C ";}
};

class D : public C
{
    public:
    virtual const char* getName() { return "Class D";}
};

int main()
{
    D d;
    A &rBase = d;
    std::cout<<"A base: "<<rBase.getName()<<"\n";
    
    return 0;
}