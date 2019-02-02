#include<iostream>
#include<string>

//class identifier
enum ClassID
{
	FRUIT,
	MANGO
	// Others can be added here later
};

class Fruit
{
    protected:
    int m_fruitType;

    public:
    Fruit(int fruitType) : m_fruitType(fruitType)
    {
    }

    virtual ~Fruit() {}
	virtual ClassID getClassID() { return FRUIT; }
};

class Mango : public Fruit
{
    protected:
    std::string m_name;

    public:
    Mango(int fruitType, std::string name) : Fruit(fruitType), m_name(name)
    {
    }

    std::string& getName() { return m_name; }
	virtual ClassID getClassID() { return MANGO; }
};

Fruit* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Mango(1, "Mango");
	else
		return new Fruit(2);
}

int main()
{
    	Fruit *f = getObject(true);
 
	if (f->getClassID() == MANGO)
	{
		// We already proved b is pointing to a Derived object, so this should always succeed
		Mango *m = static_cast<Mango*>(f);
		std::cout << "The name of the Fruit is: " << m->getName() << '\n';
	}
 
	delete f;

    return 0;
}
