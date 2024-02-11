#include<iostream>
#include<cmath>

int main(int argc, char const *argv[])
{
    double x;
    tryAgain:    //this is a statement label
    std::cout<<"Enter postive number"<<"\n";
    std::cin>>x;

    if(x<0.0)
       goto tryAgain; //this is the goto statement

std::cout << "The sqrt of " << x << " is " << sqrt(x) << std::endl;
    
    return 0;
}
