#include <iostream>

enum class Animal
{
    Pig,
    Chicken,
    Goat,
    Cat,
    Dog,
    Ostrich
};

std::string getAnimalName(Animal animal)
{
    std::string name;

    switch (animal)
    {
    case Animal::Pig:
        name = "A pig has ";
        break;

    case Animal::Cat:
        name = "A cat has ";
        break;

    case Animal::Chicken:
        name = "A chicken has ";
        break;

    case Animal::Dog:
        name = "A dog has ";
        break;

    case Animal::Goat:
        name = "A goat has ";
        break;

    case Animal::Ostrich:
        name = "A ostrich has";
        break;

    default:
        name = "Unknown Animal";
        break;
    }
    return name;
}

void printNumberOfLegs(Animal animal)
{
    std::cout << getAnimalName(animal);

    switch (animal)
    {
    case Animal::Cat:
    case Animal::Dog:
    case Animal::Goat:
    case Animal::Pig:
        std::cout << "4 ";
        break;
    case Animal::Chicken:
    case Animal::Ostrich:
        std::cout << "2 ";
        break;
    default:
        std::cout << "so undefined ";
    }
    std::cout << "legs. \n";
}

int main()
{
    printNumberOfLegs(Animal::Cat);
    printNumberOfLegs(Animal::Chicken);

    return 0;
}