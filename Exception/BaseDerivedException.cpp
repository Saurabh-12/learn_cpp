#include<iostream>

class Base
{
    public:
    Base() {}

};

class Derived : public Base
{
    public:
    Derived() {}
};


int main(int argc, char const *argv[])
{
       try
    {
        throw Derived();
    }
    catch (Derived &derived)
    {
        std::cerr << "caught Derived";
    }
    catch (Base &base)
    {
        std::cerr << "caught Base";
    }


    return 0;
}