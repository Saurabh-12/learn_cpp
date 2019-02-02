#include <iostream>

int main()
{
    enum class Color
    {
        RED,
        BLUE
    };

    enum class Fruit
    {
        APPLE,
        ORANGE,
        BANANA

    };

    Color color = Color::RED; // note: RED is not directly accessible any more,
                              //we have to use Color::RED

    if (color == Color::RED)  // this is okay
        std::cout << "The color is red!\n";
    else if (color == Color::BLUE)
        std::cout << "The color is blue!\n";

    Fruit fruit = Fruit::BANANA; // note: BANANA is not directly accessible any more,
                                //we have to use Fruit::BANANA

    //compile error here, as the compiler doesn't know
    //how to compare different types Color and Fruit
    /**
    if (color == fruit)
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";
*/
    return 0;
}