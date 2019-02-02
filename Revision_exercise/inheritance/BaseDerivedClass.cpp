#include<iostream>

class BaseClass
{
    private:
    int base_Id;

    public:
    BaseClass(int id = 0) : base_Id(id) 
    { 
        std::cout<<"Base Class Parameter Constructor"<<"\n";
    }



};

class DerivedClass : public BaseClass
{
    private:
    int derived_Id;

    public:
    DerivedClass(int id = 0):derived_Id(id)
    {
        std::cout<<"Derived class Parameter"<<"\n";
    }

};


int main()
{
    DerivedClass derivedObj;

    return 0;
}