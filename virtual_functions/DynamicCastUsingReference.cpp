#include<iostream>
#include<string>

class Game
{
    protected:
    int m_value;

    public:
    Game(int value) : m_value(value)
    {
    }

    virtual ~Game() {}

};

class Football : public Game
{
    protected:
    std::string m_name;

    public:
    Football(int value, std::string name): Game(value), m_name(name)
    {
    }

    const std::string& getName(){ return m_name;}

};

int main()
{
    Football footBall(1, "Football"); //create Football game
    Game &game = footBall;  // set base reference to object
    Football &f = dynamic_cast<Football&>(game); // dynamic cast using a reference instead of a pointer

    // we can access Football::getName through f
    std::cout << "The name of the Game is: " << f.getName() << '\n';


    return 0;
}