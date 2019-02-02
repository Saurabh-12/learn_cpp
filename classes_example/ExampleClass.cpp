#include <iostream>
#include <string>

class Employees
{
  public:
    std::string m_Name;
    int m_Id;
    double m_Wage;

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_Name << "  Id: " << m_Id << "  Wage: $" << m_Wage << '\n';
    }
};

int main()
{
    std::cout << "Welcome \n";

    // Declare two employees
    Employees Alex{"Alex Raounda ", 231, 123.78};
    Employees Joe{"Joe Kunfa ", 431, 786.54};

    // Print out the employee information
    Alex.print();
    Joe.print();

    return 0;
}