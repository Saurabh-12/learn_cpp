#include <iostream>

class ABC
{
  public:
    static int s_Value;
};

class IDGenerator
{
  private:
    static int m_id;

  public:
    static int getNextID();
};
// Here's the definition of the static member outside the class.
//Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::m_id = 1;

// Here's the definition of the static function outside of the class.
//Note we don't use the static keyword here.
int IDGenerator::getNextID() { return ++m_id; };

int ABC::s_Value = 3;

int main()
{
    ABC ab;
    ABC abc;

    std::cout << ab.s_Value << "\n";
    std::cout << abc.s_Value << "\n";

    abc.s_Value = 2;

    std::cout << ab.s_Value << "\n";
    std::cout << abc.s_Value << "\n";

    for (int count = 0; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';

    return 0;
}