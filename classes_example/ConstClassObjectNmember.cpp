#include<iostream>
#include<string>


class Something2
{
private:
    std::string m_value;
 
public:
    Something2(const std::string &value="") { m_value= value; }
 
    const std::string& getValue() const { return m_value; } // getValue() for const objects
    std::string& getValue() { return m_value; } // getValue() for non-const objects
};

class Something
{
public:
    int m_value;
 
    Something(): m_value(0) { }
 
    void setValue(int value) { m_value = value; }
    int getValue() { return m_value ; }

    int getConstValue() const { return m_value; }
};


int main()
{
    const Something something; // calls default constructor
 
    //something.m_value = 5; // compiler error: violates const
   // something.setValue(5); // compiler error: violates const

   //std::cout << something.getValue();
   std::cout << something.getConstValue();

   	Something2 something1;
	something1.getValue() = "Hi"; // calls non-const getValue();
 
	const Something2 something2;
	something2.getValue(); // calls const getValue();


    return 0;
}