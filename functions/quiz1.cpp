#include<iostream>

struct Employee
{
    std::string Name;
    int age ;
    float salary;

};




int sumValueUptoN(const int number)
{
    int sum;

    for(int index = 0; index<=number; index++)
    {
        sum+=index;
    }
 return sum;
}

std::string printEmployeeName(Employee &employee)
{
    std::string mName;

    mName = employee.Name;
    
    return mName;
}

int main()
{
    std::cout<<" Sum upto 10 : "<<sumValueUptoN(10)<<"\n";

    Employee emp = {"Saurabh", 32, 560000.89};
    std::cout<<"Employee Name : "<<printEmployeeName(emp)<<"\n";

    return 0;
}