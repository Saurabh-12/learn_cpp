#include<iostream>

class Base
{
    public:
    int m_value;

    public:
    Base(int x): m_value(x)
    {
        std::cout<<"Base class Constructor\n";
    }

    const char* getName() { return "Base"; }
    int getValue() { return m_value; }

};

class Derived : public Base
{
    public:
    Derived(int x) : Base(x)
    {
        std::cout<<"Derived class Constructor\n";
    }

    const char* getName() { return "Derived"; }
    int getValueDoubled() { return m_value * 2; }

};


int main()
{
    Derived derived(7);
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    Derived &rderived = derived;
    std::cout << "rDerived is a " << rderived.getName() << " and has value " << rderived.getValue() << '\n';
    Derived* pderived = &derived;
    std::cout << "pDerived is a " << pderived->getName() << " and has value " << pderived->getValue() << '\n';

    Base &rbase = derived;
    Base *pbase = &derived;
    std::cout << "rBase is a " << rbase.getName() << " and has value " << rbase.getValue() << '\n';
    std::cout << "pBase is a " << pbase->getName() << " and has value " << pbase->getValue() << '\n';


    return 0;
}
