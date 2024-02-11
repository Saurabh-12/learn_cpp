#include <iostream>

class A
{
  public:
    A(int x) { std::cout << "A " << x << "\n"; }
};

class B
{
  private:
    A m_a;

  public:
    B(int y)
        : m_a(y - 1) // call A(int) constructor to initialize member m_a
    {
        std::cout << "B " << y << "\n";
    }
};

class RGBA
{
  private:
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

    //Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha
  public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }

    //r=0 g=127 b=127 a=255

    void print()
    {
        std::cout << "r " << static_cast<int>(m_red) << " g " << static_cast<int>(m_green)
                  << " b " << static_cast<int>(m_blue) << " a " << static_cast<int>(m_alpha) << "\n";
    }
};

int main()
{
    B b(5);

    RGBA teal(0, 127, 127);
    teal.print();

    return 0;
}