#include<iostream>
#include "Person.cpp"

class Employee : public Person
{
  public:
    double m_hourlySalary;
    long m_employeeID;

    Employee(double hourly_salary, long employeeID)
    {
        m_hourlySalary = hourly_salary;
        m_employeeID = employeeID;
    }

    void printNameAndSalary() const
    {
        std::cout << m_name << ": " << m_hourlySalary << '\n';
    }
};