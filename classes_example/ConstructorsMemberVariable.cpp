#include <iostream>

class Something
{
  private:
    int m_Value1;
    double m_Value2;
    char m_Value3;

  public:
         Something()
    {
        // These are all assignments, not initializations
        m_Value1 = 1;
        m_Value2 = 2.2;
        m_Value3 = 'c';
    }

/*     Something() : m_Value1(1), m_Value2(2.2), m_Value3('c') // directly initialize our member variables
    {
        // No need for assignment here
    }
 */

   //explicit Something(int val) : m_Value1(val) {}

    void print(Something smt)
    {
        std::cout << "Something(" << smt.m_Value1 << ", " << smt.m_Value2 << ", " << smt.m_Value3 << ")\n";
    }

    Something(int value1, double value2, char value3 = 'c')
        : m_Value1(value1), m_Value2(value2), m_Value3(value3) // directly initialize our member variables
    {
        // No need for assignment here
    }
};

void getData(Something smt){
    smt.print(smt);  
}

int main()
{
    Something smt;
    smt.print(smt);
    Something something2(4, 9.2); // value1 = 1, value2=2.2, value3 gets default value 'c'
    something2.print(something2);

    return 0;
}