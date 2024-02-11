#include<iostream>

class Point{
	int m_x;
	int m_y;

	public:
	Point(int x, int y) : m_x(x), m_y(y)
	{
	}

	Point(const Point & pt)
	{
		m_x = pt.m_x;
		m_y = pt.m_y;
	}
};

int main()
{
	Point p1(10,20);
	Point p2(p1);

	if (p1 == p2)
	{
		std::cout<<"both points are equals"<<'\n';

	}
	else {
		std::cout<<"Not equals"<<'\n';
	} 	
	return 0;
}
