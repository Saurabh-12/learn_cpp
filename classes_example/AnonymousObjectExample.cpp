#include <iostream>

/*
 * In C++, anonymous objects are primarily used either to pass or return values without having to create lots of temporary variables to do so. Memory allocated dynamically is also done so anonymously (which is why its address must be assigned to a pointer, otherwise we’d have no way to refer to it).

* However, it is worth noting that anonymous objects are treated as rvalues (not lvalues, which have an address). This means anonymous objects can only be passed or returned by value or const reference. Otherwise, a named variable must be used instead.

 * It is also worth noting that because anonymous objects have expression scope, they can only be used once. If you need to reference a value in multiple expressions, you should use a named variable instead.
 */

int add(int x, int y)
{
    // an anonymous object is created to hold and return the result of x + y
    return x + y;
}

void printValue(int value)
{
    std::cout << value;
}

class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents)
    {
        m_cents = cents;
    }

    int getCents() const { return m_cents; }

    void print(const Cents &cents)
    {
        std::cout << cents.getCents() << " cents \n";
    }
};

void print(const Cents &cents)
{
   std::cout << cents.getCents() << " cents";
}

/* Cents add(const Cents &c1, const Cents &c2)
{
    Cents sum = Cents(c1.getCents() + c2.getCents());
    return sum;
} */

Cents add(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents() + c2.getCents()); // return anonymous Cents value
}

int main()
{
    std::cout << add(5, 3) << "\n";

    // the expression 5 + 3 is evaluated to produce the result 8,
    // which is placed in an anonymous object. A copy of this anonymous object
    //is then passed to the printValue() function, (which prints the value 8) and
    //then is destroyed.
    printValue(5 + 3);
    std::cout << " \n";

    //Anonymous class objects
    Cents cents(5); // normal variable
    cents.print(cents);
    print(Cents(6)); // Note: Now we're passing an anonymous Cents value;

    Cents cents1(6);
    Cents cents2(8);
    //Cents sum = add(cents1, cents2);
   // std::cout << "I have " << sum.getCents() << " cents." << std::endl;

// print anonymous Cents value
   std::cout << "I have " << add(cents1, cents2).getCents() << " cents." << std::endl; 
   

    return 0;
}