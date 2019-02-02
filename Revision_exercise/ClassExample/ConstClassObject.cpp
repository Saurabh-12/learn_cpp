#include<iostream>

class Something
{
    private:
    int m_value;

    public:
    Something() : m_value(0) {};
    const int value1 = 20;

    void setValue(int value){ m_value = value;};
    int getValue(){ return m_value;};

};

int main()
{
    const Something something;
    //something.m_value = 5; // compiler error: violates const
    //something.setValue(5); // compiler error: violates const

   // something.getValue();  // comile error const object canot call non constant function
   Something::value1;


    return 0;
}