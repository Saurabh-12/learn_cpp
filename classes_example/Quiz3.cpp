#include <iostream>

class Ball
{
  private:
    std::string m_color;
    double m_radius;

    public:
/*     Ball()
    {
        m_color = "Black";
        m_radius = 10.0;

    } */

/*     Ball(std::string color)
    {
        m_color = color;
        m_radius = 10.0;
    } */

/*     Ball(double radius)
    {
        m_radius = radius;
        m_color = "Black";
    } */

    Ball(std::string color = "Black", double radius = 10.0)
    {
        m_color = color;
        m_radius = radius;

    }

    Ball(double radius)
    {
        m_color = "Black";
        m_radius = radius;
    }

    void print()
    {
        //color: black, radius: 10
        std::cout<<"Color: "<<m_color <<", radius: "<<m_radius<<"\n";
    }
};

int main()
{
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