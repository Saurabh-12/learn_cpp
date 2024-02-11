#include <iostream>
#include <string>

enum COLOR
{
    COLOR_BLACK,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_WHITE,
    COLOR_MAGENTA
};

enum ItemType
{
    ITEMTYPE_SWORD,
    ITEMTYPE_TORCH,
    ITEMTYPE_POTION
};

std::string getItemName(ItemType itemType)
{

    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
    if (itemType == ITEMTYPE_TORCH)
        return std::string("Torch");
    if (itemType == ITEMTYPE_POTION)
        return std::string("Potion");
    //Just in case we add a new item in the future and forget to update this function
    return std::string("???");
}

int main()
{
    COLOR paint = COLOR_WHITE;
    COLOR house(COLOR_BLUE);

    std::cout << "color_white " << paint << "\n";
    std::cout << "color_black " << COLOR_BLACK << "\n";

    ItemType itemType(ITEMTYPE_TORCH);
    std::cout << "You are carrying a " << getItemName(itemType) << "\n";

    int inputColor;
    std::cout << "Enter color code"
              << "\n";
    std::cin >> inputColor;

    std::cout << "inputColor " << inputColor << "\n";

    COLOR COLOR_BLACK = static_cast<COLOR>(inputColor);
    //COLOR_BLACK = color;

    std::cout << "color_white " << paint << "\n";
    std::cout << "color_black " << COLOR_BLACK << "\n";

    return 0;
}
