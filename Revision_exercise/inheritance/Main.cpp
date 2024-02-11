#include<iostream>
#include"PersonExample.cpp"
#include"BaseballPlayer.cpp"

int main(int argc, char const *argv[])
{
     // Create a new BaseballPlayer object
    BaseballPlayer joe;
    // Assign it a name (we can do this directly because m_name is public)
    joe.m_Name = "Joe";
    // Print out the name
    std::cout << joe.getName() << '\n'; // use the getName() function we've acquired from the Person base class
    return 0;
}
