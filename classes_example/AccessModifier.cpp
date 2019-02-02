#include <iostream>

class DateClass // members are private by default
{
    int m_year; //private by default, can only be accessed by other members
    int m_month;
    int m_day;

    //Although class members are private by default,
    //we can make them public by using the public keyword:
  public:
    int mm_year;
    int mm_month;
    int mm_date;
    //The public keyword, along with the following colon, is called an access specifier.
    //Access specifiers determine who has access to the members that follow the specifier
    //C++ provides 3 different access specifier keywords: public, private, and protected
  public:
    void setDate(int month, int day, int year) // public, can be accessed by anyone
    {
        // setDate() can access the private members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print() // public, can be accessed by anyone
    {
        std::cout << m_month << "/" << m_day << "/" << m_year;
    }
    //Rule: Make member variables private, and member functions public, unless you have a good reason not to.

    // Note the addition of this function
    void copyFrom(const DateClass &d)
    {
        // Note that we can access the private members of d directly
        m_month = d.m_month;
        m_day = d.m_day;
        m_year = d.m_year;
    }
};

int main()
{
    DateClass date;
    //date.m_month = 10; // error
    //date.m_day = 14; // error
    //date.m_year = 2020; // error

    date.mm_month = 10;
    date.mm_date = 14;
    date.mm_year = 2018;

    date.setDate(10, 14, 2020); // okay, because setDate() is public
    date.print();               // okay, because print() is public
    std::cout << "\n";

    DateClass copy;
	copy.copyFrom(date); // okay, because copyFrom() is public
	copy.print();
    std::cout << "\n";

    return 0;
}