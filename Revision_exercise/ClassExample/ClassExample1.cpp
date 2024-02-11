#include<iostream>


class Rectangles
{
    private:
    double m_length = 1.0;
    double m_width = 1.0;

    public:
 
    // note: No default constructor provided in this example
 
    Rectangles(double length, double width)
        : m_length(length), m_width(width)
    {
        // m_length and m_width are initialized by the constructor 
        //(the default values aren't used)
    }
 
    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }

};

int main(int argc, char const *argv[])
{
    Rectangles x; // will not compile, no default constructor exists, 
    //even though members have default initialization values
    
    return 0;
}
