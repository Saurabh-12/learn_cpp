#ifndef PERSON_H
#define PERSON_H
#include<string>

class Person
{
    public:
    std::string m_name;
    int m_age;

    Person(std::string name = "", int age = 0): m_name(name),m_age(age)
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }


};
#endif