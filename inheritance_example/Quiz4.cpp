#include<iostream>


class Base
{
    protected:
    int m_value;

    public:
    Base(int x ) : m_value(x)
    {
        std::cout<<"Base Constructor\n";
    }

    ~Base()
    {
        std::cout<<" Base Destructor \n";
    }

void print() { std::cout << "Base: Value: " << m_value << '\n';  }

};

class Derived : public Base
{
    public:
    Derived(int x) : Base(x)
    {
        std::cout<<"Derived Constructor\n";
    }

    ~Derived()
    {
        std::cout<<"Derived destructor \n";
    }

void print() { std::cout << "Derived: Value: " << m_value << '\n'; }

};

class D2 : public Derived
{
    public:
    D2(int x):Derived(x)
    {
        std::cout<<"D2 constructor \n";
    }

    ~D2()
    {
        std::cout<<"D2 distructor\n";
    }
// note: no print() function here
};

int main()
{
    D2 d(5);
	d.print();

    return 0;
}