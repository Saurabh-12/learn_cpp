#include <iostream>

class Point3D
{
    double m_x;
    double m_y;
    double m_z;

  public:
    void setValues(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << "< " << m_x << ", " << m_y << ", " << m_z << " >\n";
    }

    // We can use the fact that access controls work on a per-class basis here
    // to directly access the private members of Point3d parameter p
    bool isEqual(const Point3D &p)
    {
        return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
    }
};

int main()
{
    Point3D point1;
    point1.setValues(1.0, 2.0, 3.0);

    Point3D point2;
    point2.setValues(1.0, 2.0, 3.0);

    if (point1.isEqual(point2))
        std::cout << "point1 and point2 are equal\n";
    else
        std::cout << "point1 and point2 are not equal\n";

    Point3D point3;
    point3.setValues(3.0, 4.0, 5.0);

    if (point1.isEqual(point3))
        std::cout << "point1 and point3 are equal\n";
    else
        std::cout << "point1 and point3 are not equal\n";

    return 0;
}