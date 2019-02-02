#include <iostream>

class Date
{
private:
    int m_year = 1900;
    int m_month = 1;
    int m_day = 1;
 
public:
    Date(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
 
    // No implicit constructor provided because we already defined our own constructor
};

class A
{
  public:
    A()
    {
        std::cout << "class A \n";
    }
};

class B
{
    A a;

  public:
    B()
    {
        std::cout << "Class B \n";
    }
};

int main()
{
    B b;

    // error: Can't instantiate object because default constructor doesn't exist 
    //and the compiler won't generate one
    //Date date; 

    Date today(2020, 10, 14); // today is initialized to Oct 14th, 2020

    return 0;
}