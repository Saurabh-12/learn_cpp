#include<iostream>

class Fruits
{
    private:
    int m_FruitType;

public:
    Fruits(int fruitType = 0)
    {
        m_FruitType = fruitType;
    }

    int getFruitType() const
    {
        return m_FruitType;
    }

};

// note: this function is not a member function nor a friend function!
Fruits operator+(const Fruits &c1, const Fruits &c2)
{
	// use the Cents constructor and operator+(int, int)
        // we don't need direct access to private members here
	return Fruits(c1.getFruitType() + c2.getFruitType());
}

int main()
{
    Fruits fruit1(6);
	Fruits fruit2(8);
	Fruits fruitSum = fruit1 + fruit2;
	std::cout << "I have " << fruitSum.getFruitType() << " fruits type. " << std::endl;

    return 0;
}