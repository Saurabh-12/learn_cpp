#include<iostream>
#include<typeinfo>

int main()
{
    std::cout<<"Saurabh Sharma...\n";
    int x(5);
    int y(5);

    std::cout<<"x "<<x<<" y "<<y<<"\n";
    std::cout<< "Address: of x "<<&x<<" Address: of Y "<<&y<<"\n";
    std::cout<<"Valu od address x "<<*&x<<" Value of address Y "<<*&y<<"\n";

    std::cout<<typeid(&x).name()<<"\n";

    int iValue = 5;
double dValue = 7.0;
 
int *iPtr = &iValue; // ok
double *dPtr = &dValue; // ok
//iPtr = &dValue; // wrong -- int pointer cannot point to the address of a double variable
//dPtr = &iValue; // wrong -- double pointer cannot point to the address of an int variable
std::cout<< "Adress of iValue   "<<&iValue<<"\n";
std::cout<<" *iptr  "<<iPtr<<"\n";

    return 0;
    }