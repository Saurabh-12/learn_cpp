#include<iostream>


class Animal
{
    protected:
    std::string m_name;
    const char *m_speak;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string name, char *speak): m_name(name), m_speak(speak)
    {

    }

public:
std::string getName() const { return m_name;}
const char *speak() { return m_speak;}


};

class Dog :public Animal
{
    public:
    Dog(std::string name): Animal(name, "woof")
    {
        
    }

};

class Cat : public Animal
{
    public:
    Cat(std::string name): Animal(name, "Meow")
    {

    }

};

int main()
{
    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
 
    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (int iii=0; iii < 6; iii++)
        std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';

    return 0;
}