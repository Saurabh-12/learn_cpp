#include<iostream>

class Base
{
    //private:     // derived class did not access it. 
    protected:
    int m_value;

    public:
    Base(int value): m_value(value)
    {
        std::cout<<"Base \n";
    }

    ~Base()
    {
        std::cout<<"Base Distructor \n";
    }

    void print() { std::cout << "Base: " << m_value << '\n';  }

};

class Derived : public Base
{
    public:
    Derived(int x):Base(x)
    {
        std::cout<<"Derived \n";
    }

    ~Derived()
    {
        std::cout<<"Derived Distructor: ";
    }

    void print() { std::cout << "Derived: " << m_value<< '\n'; }

};

int main()
{
    Derived d(5);
	d.print();

    return 0;
}
