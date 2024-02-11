#include<iostream>
#include<string>

struct Emplyoee
{
    short id;
    int age;
    double wage;
    std::string fName;

};
void printEmployeeInfo(Emplyoee employee)
{
    std::cout << "ID:   " << employee.id << "\n";
    std::cout << "Age:  " << employee.age << "\n";
    std::cout << "Wage: " << employee.wage << "\n";
    std::cout << "Name: " << employee.fName << "\n";
}

struct Rectangle
{
    double length;// = 1.0;// non-static member initialization, supported in c++11
    double width;// = 1.0;

};

int main()
{
    std::cout<<"welcome Saurabh"<<"\n";
    Emplyoee jp = {1,29,12.00,"JayPraksh Rawat"};
    std::cout <<jp.fName<<"\n";

    //compile with c++11 otherwise gives following CTE
    //warning: extended initializer lists only available with -std=c++11 or -std=gnu++11
    //Emplyoee kp {2,34, 67890.87,"Krishna Pratap"};

    Rectangle x;
    std::cout<<"Rectangle Length "<< x.length<<"\n";
    x.length = 2.45;
    std::cout<<"Rectangle Length "<< x.length<<"\n";

    Rectangle y = {2.6,3.5};
    std::cout<<"Rect Width and Length "<<y.length<<" "<<y.width<<"\n";

    Emplyoee joe = { 14, 32, 24.15 ,"Joe Kurdarsan"};
    Emplyoee frank = { 15, 28, 18.27, "Frank Hunduston" };
 
    // Print Joe's information
    printEmployeeInfo(joe);
 
    std::cout << "\n";
 
    // Print Frank's information
    printEmployeeInfo(frank);

    return 0;
}
