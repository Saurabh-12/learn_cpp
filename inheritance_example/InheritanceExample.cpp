#include <iostream>
#include "BaseballPlayer.cpp"
#include "Employee.cpp"

int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe;
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class

    Employee frank(20.25, 12345);
    frank.m_name = "Frank"; // we can do this because m_name is public
    frank.printNameAndSalary();

    return 0;
}