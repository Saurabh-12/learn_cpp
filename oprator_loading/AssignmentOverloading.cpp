#include<iostream>

class Fruit
{
    private:
    std::string m_name;
    int m_Type = 1; // 1 = juicy, 0 = non juicy 

    public:
    Fruit(std::string name = "Mango", int type = 1)
    {
        m_name = name;
        m_Type = type;
    }

    	// Copy constructor
	Fruit(const Fruit &copy) :
		m_name(copy.m_name), m_Type(copy.m_Type)
	{
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

            // Overloaded assignment
        Fruit& operator= (const Fruit &fruit);
 
	friend std::ostream& operator<<(std::ostream& out, const Fruit &f1);
};

std::ostream &operator<<(std::ostream &out, const Fruit &f1)
{
    bool type = f1.m_Type ? 1 : 0;
    if (type)
        out << "Fruit: " << f1.m_name << " is juicy"
            << "\n";
    else
        out << "Fruit: " << f1.m_name << " is not juicy "
            << "\n";

    return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fruit& Fruit::operator= (const Fruit &fruit)
{
    // do the copy
    m_name = fruit.m_name;
    m_Type = fruit.m_Type;
 
    // return the existing object so we can chain this operator
    return *this;
}

int main()
{
    Fruit orange("Guva", 0);
    Fruit f;
    f = orange; // calls overloaded assignment
    std::cout << f;

    Fruit f1("Mango", 1);
    Fruit f2("Grapes",1);
    Fruit f3("Banana", 0);
    std::cout<<f1;
    std::cout<<f2;
    std::cout<<f3;
std::cout<<"...................................\n";
    f1 = f2 = f3; //chained assignment
    std::cout<<f1;
    std::cout<<f2;
    std::cout<<f3;
 
    return 0;
}