#include <iostream>
#include <string>

class Rectangle
{
  private:
    double m_length = 1.0; // m_length has a default value of 1.0
    double m_width = 1.0;  // m_width has a default value of 1.0

  public:
    Rectangle()
    {
        // This constructor will use the default values above since they aren't overridden here
    }

    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
};

class Ball
{
  private:
    std::string m_color = "black";
    double m_radius = 10.0;

  public:
    // Default constructor with no parameters
    Ball()
    {
    }

    // Constructor with only color parameter (radius will use default value)
    Ball(const std::string &color)
    {
        m_color = color;
    }

    // Constructor with only radius parameter (color will use default value)
    Ball(double radius)
    {
        m_radius = radius;
    }

    // Constructor with both color and radius parameters
    Ball(const std::string &color, double radius)
    {
        m_color = color;
        m_radius = radius;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
    Rectangle x; // x.m_length = 1.0, x.m_width = 1.0
    x.print();

    Ball def;
    def.print();

    Ball blue("blue");
    blue.print();

    Ball twenty(20.0);
    twenty.print();

    Ball blueTwenty("blue", 20.0);
    blueTwenty.print();

    return 0;
}