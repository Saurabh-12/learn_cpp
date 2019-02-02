#include<iostream>
#include<string>

//The need for dynamic_cast
//When dealing with polymorphism, we’ll often encounter cases where we have a pointer to a base class, 
//but we want to access some information that exists only in a derived class

class Base
{
    protected:
    int m_value;

    public:
    Base(int value) : m_value(value)
    {

    }

    virtual ~Base()
    {

    }
};

class Derived : public Base
{
    protected:
    std::string m_name;

    public:
    Derived(int value, std::string name): Base(value), m_name(name)
    {

    }

    const std::string& getName()
    {
        return m_name;
    }
};

Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
		return new Derived(1, "Apple");
	else
		return new Base(2);
}

int main()
{
    	Base *b = getObject(true);
 
	// how do we print the Derived object's name here, having only a Base pointer?
     // use dynamic cast to convert Base pointer into Derived pointer
     Derived *d = dynamic_cast<Derived*>(b);
     std::cout<< "The name of the Derived is: "<<d->getName()<<"\n";

     //dynamic_cast failure
     //we’ve made quite a dangerous assumption: that b is pointing to a Derived object. 
     //What if b wasn’t pointing to a Derived object? It will fail.
     //if a dynamic_cast fails, the result of the conversion will be a null pointer.

      if (d) // make sure d is non-null
            std::cout << "The name of the Derived is: " << d->getName() << '\n';
//Rule: Always ensure your dynamic casts actually succeeded by checking for a null pointer result.

	delete b;

    return 0;
}