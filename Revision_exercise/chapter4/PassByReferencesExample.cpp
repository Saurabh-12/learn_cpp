#include<iostream>

int doSomething(const int &ref)
{
    //ref = 4;
    return 2+ref;
}

int doThing(int &ref)
{
    //ref = 4;
    return 2+ref;
}


int main()
{
    std::cout<<" non const l value "<<doSomething(5)<<"\n";
    const int abc = 9;
    std::cout<<"const l value "<<doSomething(abc)<<"\n";

    std::cout<<"r value "<<doSomething(3*2+1)<<"\n";

 int xyz = 9;
    std::cout<<" non const l value "<<doThing(xyz)<<"\n";
    //std::cout<<"const l value "<<doThing(abc)<<"\n";
    //std::cout<<"r value "<<doThing(3*2+1)<<"\n";


    return 0;
}