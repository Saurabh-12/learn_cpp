#include <iostream>
#include <cassert>

class Fractions
{
  private:
    int m_numerator;
    int m_denominator;

  public:
    Fractions() //default constructor{
    {
        m_numerator = 0;
        m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fractions(int numerator, int denominator=1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
    Fractions frac; // Since no arguments, calls Fraction() default constructor
    std::cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';

int x(5); // Direct initialize an integer
Fractions fiveThirds(5, 3); // Direct initialize a Fraction, calls Fraction(int, int) constructor
std::cout<<fiveThirds.getValue()<<"\n";

    return 0;
}