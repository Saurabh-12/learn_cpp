#include <iostream>

class Base
{
  protected:
    int base_Value;

  public:
    Base(int value) : base_Value(value)
    {
        std::cout << "Base class constructor"
                  << "\n";
    }

    void getFunction() { std::cout << "Base class get Function "<<base_Value<<"\n"; }
};

class Derived : public Base
{
  public:
    Derived(int value)
        : Base(value)
    {
    }

    void getFunction() 
    { 
        Base::getFunction(); // call Base::identify() first
        std::cout << "Derived class get Function "<<base_Value<<"\n"; 
    }
};

int main(int argc, char const *argv[])
{
    Base base(5); 
    base.getFunction();

    std::cout<<"..............................\n";
 
    Derived derived(7);
    derived.getFunction();

    return 0;
}
