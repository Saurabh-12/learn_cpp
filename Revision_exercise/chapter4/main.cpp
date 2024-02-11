#include<iostream>
#include"a.h"
#include"b.h"

int main()
{
	using namespace a;
	using namespace b;

	std::cout<<"print x"<<a::x<<" "<<b::x<<std::endl;
return 0;
}
