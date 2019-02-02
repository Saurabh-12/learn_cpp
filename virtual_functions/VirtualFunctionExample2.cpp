#include <iostream>
#include <string>

class Animal
{
  private:
    std::string m_name;

  protected:
    Animal(std::string name) : m_name(name)
    {
    }

  public:
    const std::string getName() { return m_name; }
    virtual const char *speak() { return "????"; }
};

class Cat : public Animal
{
  public:
    Cat(std::string name) : Animal(name)
    {
    }

    virtual const char *speak() { return "meow"; }
};

class Dog : public Animal
{
  public:
    Dog(std::string name) : Animal(name)
    {
    }

    virtual const char *speak() { return "woof"; }
};

void report(Animal &animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat("Fred");
    Dog dog("Garbo");

    report(cat);
    report(dog);

    Cat fred("Fred"), misty("Misty"), zeke("Zeke");
    Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
    
    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    Animal *animal[] = {&fred, &misty, &zeke, &garbo, &pooky, &truffle};
    for(int i = 0; i<6; i++)
    std::cout<<animal[i]->getName()<<" says "<<animal[i]->speak()<<"\n";

    return 0;
}