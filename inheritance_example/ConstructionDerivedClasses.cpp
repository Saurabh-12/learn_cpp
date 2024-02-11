#include <iostream>
using namespace std;

class Base
{
  public:
    int m_id;

    Base(int id = 0) : m_id(id)
    {
        std::cout << "Base\n";
    }

    int getId() const { return m_id; }
};

class Derive : public Base
{
  public:
    double m_cost;

    Derive(double cost = 0.0) : m_cost(cost)
    {
        std::cout << "Derived\n";
    }
};

class A
{
    public:
    A()
    {
        std::cout<<"A\n";
    }
};

class B : public A
{
    public:
    B()
    {
        std::cout<<"B\n";
    }
};

class C : public B
{
    public:
    C()
    {
        std::cout<<"C\n";
    }
};

class D : public C
{
    public:
    D()
    {
        std::cout<<"D\n";
    }
};

int main()
{
    std::cout << "Instantiating Base" << std::endl;
    Base cBase;

    std::cout << "Instantiating Derived" << std::endl;
    Derive cDerived;

        A cA;
 
    cout << "Constructing B: " << endl;
    B cB;
 
    cout << "Constructing C: " << endl;
    C cC;
 
    cout << "Constructing D: " << endl;
    D cD;

    return 0;
}