#include<iostream>
#include<cassert>


class Fractions
{
    private:
    int m_numerator;
    int m_denominator;

    public:
    Fractions(int numo = 0, int deno = 1)
    :m_numerator(numo),m_denominator(deno)
    {
        assert(deno != 0);
    }

    // Copy constructor
    Fractions(const Fractions &fraction):m_numerator(fraction.m_numerator),m_denominator(fraction.m_denominator)
    // Note: We can access the members of parameter fraction directly, because we're inside the Fraction class
    {
        // no need to check for a denominator of 0 here since fraction must already be a valid Fraction
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    friend std::ostream& operator<<(std::ostream& out, const Fractions &f1 );
};

std::ostream& operator<<(std::ostream& out, const Fractions &f1)
{
    out<<f1.m_numerator<<"/"<<f1.m_denominator<<"\n";

    return out;
}

int main()
{
	Fractions fiveThirds(5, 3); // Direct initialize a Fraction, calls Fraction(int, int) constructor
	Fractions fCopy(fiveThirds); // Direct initialize -- with Fraction copy constructor
	std::cout << fCopy << '\n';
//elision
    Fractions sixThirds(Fractions(6, 3));
	std::cout << sixThirds;
}