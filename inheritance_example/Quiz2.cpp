#include<iostream>

class Base
{
    public:
    Base()
    {
        std::cout<<" Base Construction \n";
    }

    ~Base()
    {
        std::cout<< "Base Destructor \n";
    }

};

class Derived : public Base
{
    public:
    Derived()
    {
        std::cout<<" Derived Construction \n";
    }

    ~Derived()
    {
        std::cout<<"Derived Destructor \n";
    }

};


int main()
{
    Derived d;
    Base b;

    return 0;
}