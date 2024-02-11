#include <iostream>

class Cents
{
  private:
    int m_cent;

  public:
    Cents(int cent) : m_cent(cent)
    {
    }

    int getCent() const { return m_cent; }

    // add Cents + Cents using a friend function
    friend Cents operator+(const Cents &c1, const Cents &c2);

    // subtract Cents - Cents using a friend function
    friend Cents operator-(const Cents &c1, const Cents &c2);

    //Overloading operators for operands of different types

    // add Cents + int using a friend function
    friend Cents operator+(const Cents &c1, int value);

    // add int + Cents using a friend function
    friend Cents operator+(int value, const Cents &c1);
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
    // we can access m_cents directly because this is a friend function
    return Cents(c1.m_cent + c2.m_cent);
}

// note: this function is not a member function!
Cents operator-(const Cents &c1, const Cents &c2)
{
    // use the Cents constructor and operator-(int, int)
    // we can access m_cents directly because this is a friend function
    return Cents(c1.m_cent - c2.m_cent);
}

// note: this function is not a member function!
Cents operator+(const Cents &c1, int value)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cent + value);
}
 
// note: this function is not a member function!
Cents operator+(int value, const Cents &c1)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cent + value);
}


int main()
{
    Cents cents1(9);
    Cents cents2(6);
    Cents centsSum = cents1 + cents2;
    std::cout << "I have " << centsSum.getCent() << " cents." << std::endl;

    Cents centsSubs = cents1 - cents2;
    std::cout << "I have " << centsSubs.getCent() << " cents." << std::endl;

    Cents c1 = Cents(4) + 6;
	Cents c2 = 6 + Cents(4);
 
	std::cout << "I have " << c1.getCent() << " cents." << std::endl;
	std::cout << "I have " << c2.getCent() << " cents." << std::endl;

    return 0;
}