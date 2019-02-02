#include <iostream>
#include <vector>

class MyClass
{
  private:
    static std::vector<char> s_mychars;

  public:
    class Init
    {
      public:
        Init() // the _init constructor will initialize our static variable
        {
            s_mychars.push_back('a');
            s_mychars.push_back('e');
            s_mychars.push_back('i');
            s_mychars.push_back('o');
            s_mychars.push_back('u');
        }
    };
// we'll use this static object to ensure the _init constructor is calle
    private:
	static Init s_initializer; 

    public:
    static std::vector<char>getCharVector(){return s_mychars;}
};

std::vector<char> MyClass::s_mychars; // define our static member variable
// define our static initializer, which will call the _init constructor,
// which will initialize s_mychars
MyClass::Init MyClass::s_initializer;

int main()
{
    std::cout<<" Vector size "<< MyClass::getCharVector().size()<<"\n";

    return 0;
};
