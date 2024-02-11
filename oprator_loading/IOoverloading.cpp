#include<iostream>
class Points
{
    private:
    double m_x, m_y, m_z;

    public:
    Points(double x = 0.0, double y = 0.0, double z = 0.0)
    {
        m_x = x;
        m_y = y;
        m_z = z;

    }

    friend std::ostream & operator<<(std::ostream &out, const Points &p);
    friend std::istream & operator>>(std::istream &in, Points &p);

};

std::ostream & operator<<(std::ostream &out, const Points &p)
{
     // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out<<"Point( "<<p.m_x<<", "<<p.m_y<<", "<<p.m_z<<" )";
    return out;
}

std::istream & operator>>(std::istream &in, Points &p)
{
    in >> p.m_x;
    in >> p.m_y;
    in >> p.m_z;
    return in;
}

int main()
{
    std::cout<<"Welcome saurabh \n";
    Points point1(2.0, 3.5, 4.0);
    Points point2(6.0, 7.5, 8.0);
    std::cout<<point1<<" "<<point2<<"\n";

    std::cout << "Enter a point: \n";
    Points point;
    std::cin >> point;
    std::cout << "You entered: " << point << '\n';

    return 0;
}