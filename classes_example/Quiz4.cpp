#include<iostream>

class Vector3d;

class Point3d
{
    private:
    double m_x, m_y, m_z;

    public:
    Point3d(double x= 0, double y = 0,double z = 0)
    :m_x(x), m_y(y), m_z(z)
    {

    }
    
    	void print()
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

// so we can use Vector3d here
    void moveByVector(const Vector3d v);
       // note: we can't define this function here, because Vector3d hasn't been declared yet (just forward declared)

};


class Vector3d
{

};