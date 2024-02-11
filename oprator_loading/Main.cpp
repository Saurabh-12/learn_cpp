#include<iostream>
#include"Rupee.h"

int main()
{
    Rupee rupee1(6);
	Rupee rupee2(8);
	Rupee rupeeSum = rupee1 + rupee2; // without the prototype in rupee.h, this would fail to compile
	std::cout << "I have " << rupeeSum.getRupee() << " rupeeses." << std::endl;

    return 0;
}

