#include <iostream>
#include "Cents.h"
 
int main()
{
	Cents cents1(6);
	Cents cents2(8);
	Cents centsSum = cents1 + cents2; // without the prototype in Cents.h, 
    //this would fail to compile
	std::cout << "I have " << centsSum.getCent() << " cents." << std::endl;
 
	return 0;
}