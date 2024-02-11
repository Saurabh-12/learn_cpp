#include<iostream>

int main()
{
    enum Color
    {
        RED,
        BLUE
    };

    enum Fruit
    {
        BANANA,
        APPLE,
        MANGO
    };

 // Color and RED can be accessed in the same scope (no prefix needed)
    Color color = RED;
    std::cout<<"Color::Red "<<color<<"\n";
    
    // Fruit and BANANA can be accessed in the same scope (no prefix needed)
    Fruit fruit = BANANA; 
 
    if (color == fruit) // The compiler will compare a and b as integers
        std::cout << "color and fruit are equal\n"; // and find they are equal!
    else
        std::cout << "color and fruit are not equal\n";
    
    return 0;
}
