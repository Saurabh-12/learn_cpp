# include <iostream>

int main()
{

int K = 12432;
//std::cout<<"Hello Saurabh"<<std::endl;
std::cout << " K " << K << std::endl;

int x = 5; // this is an initialization
x = x - 2; // this is an assignment
std::cout << " X " << x << std::endl; // #1
 
int y = x;
std::cout << " y " << y << std::endl; // #2
 
// x + y is an r-value in this context, so evaluate their values
std::cout << " X+Y " << x + y << std::endl; // #3
 
std::cout << " x " << x << std::endl; // #4
 
int z;
std::cout<< " z " << z << std::endl; // #5
return 0;
}
