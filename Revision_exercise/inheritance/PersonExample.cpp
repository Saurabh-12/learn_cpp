#ifndef PERSONEXAMPLE_H
#define PERSONEXAMPLE_H

#include<iostream>
#include<string>

class PersonExample
{
    public:
    std::string m_Name;
    int m_Age;

    PersonExample(std::string name = "", int age = 0)
    :m_Name(name), m_Age(age) { }

    std::string getName() const { return m_Name;}
    int getAge() const { return m_Age;}

};
#endif