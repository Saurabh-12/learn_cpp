#include<iostream>
#include<string>

class MyString
{
    private:
    std::string m_String;

    public:

    MyString(char) = delete; // any use of this constructor is an error

    // explicit keyword makes this constructor ineligible for implicit conversions
   explicit MyString(int x)  // allocate string of size x
    {
        m_String.resize(x);
    }

    MyString(const char *string) // allocate string to hold string value
    {
        m_String = string;                
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString &s);


};

std::ostream& operator<<(std::ostream& out, const MyString &s)
{
    out<<s.m_String<<"\n";
}

int main()
{
	//MyString x = 'x'; // use copy initialization for MyString
    //MyString str('x');  // Allowed: initialization parameters may still be implicitly converted to match
	//std::cout << str;
    MyString x('x'); // compMyString x('x'); // compile error, since MyString(char) is deletedile error, since MyString(char) is deleted
	return 0;
}