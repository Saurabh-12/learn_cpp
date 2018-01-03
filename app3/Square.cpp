#include "Square.h"  // square.h is included once here

int getSquareSides(int sides)
{
    return sides;
}

int getSquareArea(int sides)
{
    return sides*sides;
}

int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides(sideLength);
}