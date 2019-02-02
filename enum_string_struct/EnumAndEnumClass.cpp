#include<iostream>

//plain enum
enum Color
{
red,
blue,
green
};

//Another plain enum
enum Card 
{
red_card,
blue_card,
green_card
};

//enum class
enum class Animal
{
dog,
deer,
cat,
bird,
human
};

//Another enum class
enum class Mammal
{
kangaroo,
deer,
human 
};


void badNGoodEnumExample()
{
   // examples of bad use of plain enums:
    Color color = Color::red;
    Card card = Card::green_card;

    int num = color;    // no problem
std::cout<<"Color enum Num: "<<num<<"\n";

    if (color == Card::red_card) // no problem (bad)
        std::cout << "bad compare of Color and Card 1" << std::endl;

    if (card == Color::green)   // no problem (bad)
        std::cout << "bad compare of Color and Cad enum 2 " << std::endl;

    // examples of good use of enum classes (safe)
    Animal a = Animal::deer;
    Mammal m = Mammal::deer;

    int num2 = a;   // error
    if (m == a)         // error (good)
        std::out << "bad" <<std::endl;

    if (a == Mammal::deer) // error (good)
        std::cout << "bad" <<std::endl;

}

int main()
{

std::cout<<"Bad and good Enum example"<<"\n";

badNGoodEnumExample();

return 0;
}


