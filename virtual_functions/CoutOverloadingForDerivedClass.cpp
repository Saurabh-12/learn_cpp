#include <iostream>

class Base
{
  public:
    Base()
    {
    }

    /*     virtual void print() const
    {
        std::cout<<"Base: "<<"\n";
    }

    friend std::ostream& operator<<(std::ostream &out, Base & b)
    {
        out<<"Base";
        return out;
    } */

    // Here's our overloaded operator<<
    friend std::ostream &operator<<(std::ostream &out, Base &b)
    {
        // Delegate printing responsibility for printing to member function print()
        return b.print(out);
    }

    // We'll rely on member function print() to do the actual printing
    // Because print is a normal member function, it can be virtualized
    virtual std::ostream& print(std::ostream &out) const
    {
        out << "Base";
        return out;
    }
};

class Derived : public Base
{
  public:
    Derived()
    {
    }

	// Here's our override print function to handle the Derived case
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}

/*     friend std::ostream &operator<<(std::ostream &out, Derived &d)
    {
        out << "Derived ";
        return out;
    } */
};

int main()
{
    Derived d;
    Base &b = d;
    //b.print(); // will call Derived::print()

    //std::cout << "b is a ";
    //b.print(); // messy, we have to break our print statement to call this function
   // std::cout << '\n';

    Base b1;
    std::cout << b1 << '\n';

    Derived d1;
    std::cout << d1 << '\n';// note that this works even with no operator<< that explicitly handles Derived object

    Derived d2;
    Base &b2 = d2;
    std::cout << b2 << '\n';

    return 0;
}