#ifndef CREATURE_H
#define CREATURE_H
#include<iostream>
#include<string>
#include"Point2D.h"

class Creature
{
    private:
    std::string m_name;
    Point2D m_Location;

    public:
    Creature(const std::string name, const Point2D location)
    :m_name(name), m_Location(location)
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Creature &creature)
    {
        out<<creature.m_name<<" is at "<<creature.m_Location;
        return out;
    }
    
    void moveTo(int x, int y)
    {
        m_Location.setPoint(x, y);
    }
    
};

#endif