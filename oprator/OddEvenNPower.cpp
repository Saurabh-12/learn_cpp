#include <iostream>
#include <cmath>


bool checkEvenNumber(int number){
    return (number%2)==0;
}

int main(){

    std::cout << "Enter base no : "<<"\n";
    double base;
    std::cin >> base;
    std::cout << "Enter Exponent No: "<<"\n";
    double expo; 
    std::cin >> expo;
    std::cout <<base<<"^"<<expo<< " = "<<pow(base, expo)<<"\n";
    std::cout << "........................................"<<"\n";

    std::cout << "Enter a number to check even odd" << "\n";
    int x;
    std::cin >> x;
    if(checkEvenNumber(x))
           std::cout << x << " is even "<<"\n";
    else
       std::cout << x << " is odd "<<"\n";


    return 0;
}