#include <iostream>

class MinMax
{
  private:
    int m_max;
    int m_min;

  public:
    MinMax(int max, int min)
    {
        m_max = max;
        m_min = min;
    }

    int getMax() { return m_max; }
    int getMin() { return m_min; }

    friend MinMax operator+(const MinMax &m1, const MinMax &m2);
    friend MinMax operator+(const MinMax &m, int value);
    friend MinMax operator+(int value, const MinMax &m);
};

MinMax operator+(const MinMax &m1, const MinMax &m2)
{
    // Get the minimum value seen in m1 and m2
    int min = m1.m_min < m2.m_min ? m1.m_min : m2.m_min;

    // Get the maximum value seen in m1 and m2
    int max = m1.m_max > m2.m_max ? m1.m_max : m2.m_max;

    return MinMax(min, max);
}

MinMax operator+(const MinMax &m, int value)
{
    // Get the minimum value seen in m and value
    int min = m.m_min < value ? m.m_min : value;

    // Get the maximum value seen in m and value
    int max = m.m_max > value ? m.m_max : value;

    return MinMax(min, max);
}

MinMax operator+(int value, const MinMax &m)
{
    // call operator+(MinMax, int)
    return m + value;
}

int main()
{
    MinMax m1(10, 15);
    MinMax m2(8, 11);
    MinMax m3(3, 12);

    MinMax mFinal = m1 + m2 + 5 + 8 + m3 + 16;

    std::cout << "Result: (" << mFinal.getMin() << ", " << mFinal.getMax() << ")\n";

    return 0;
}