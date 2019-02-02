#include <iostream>

class Accumulator
{
  private:
    int m_value;

  public:
    Accumulator() { m_value = 0; }
    void add(int value) { m_value += value; }
    int getValue() { return m_value; };

    // Make the reset() function a friend of this class
    friend void reset(Accumulator &accumulator);
};

class Value
{
  private:
    int m_value;

  public:
    Value(int value) { m_value = value; }
    friend bool isEqual(const Value &value1, const Value &value2);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator &accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

bool isEqual(const Value &value1, const Value &value2)
{
    return (value1.m_value == value2.m_value);
}

int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    acc.add(8);
    acc.add(3);
    std::cout << "Add : " << acc.getValue() << "\n";
    reset(acc); // reset the accumulator to 0
    std::cout << "Add Value after reset: " << acc.getValue() << "\n";

    Value v1(23);
    Value v2(24);
    std::cout << " V1 == v2 " << isEqual(v1, v2) << "\n";

    return 0;
}