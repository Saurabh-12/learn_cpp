#include<iostream>

void foo(int a, int b = 10)
{
	std::cout<<"a "<<a<<" b "<<b<<'\n';
}

int main()
{
	foo(5,10);

	return 0;
}
