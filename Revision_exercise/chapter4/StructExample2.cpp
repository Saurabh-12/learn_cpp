#include<iostream>

struct Employee
{
    short id;
    int age;
    double wage;

};

void printEmployeeInfo(Employee emp)
{
    std::cout << "ID:   " << emp.id << "\n";
    std::cout << "Age:  " << emp.age << "\n";
    std::cout << "Wage: " << emp.wage << "\n";
}

int main()
{

    Employee joe = { 14, 32, 24.15 };
    Employee frank = { 15, 28, 18.27 };
 
    // Print Joe's information
    printEmployeeInfo(joe);
 
    std::cout << "\n";
 
    // Print Frank's information
    printEmployeeInfo(frank);

    return 0;
}