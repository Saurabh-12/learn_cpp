#include<iostream>
void foo(int *&p)
{

}

int main()
{

    int *p; // Create an uninitialized pointer (that points to garbage)
    foo(p); // Trick compiler into thinking we're going to assign this a valid value
	    
    std::cout << *p <<"\n"; // Dereference the garbage pointer

    char *mchar;
    int *mint;

    struct Something
    {
        int nX, nY, nZ;
    };

    Something *msth;

    std::cout << sizeof(mchar) << '\n'; // prints 4
std::cout << sizeof(mint) << '\n'; // prints 4
std::cout << sizeof(msth) << '\n'; // prints 4

char ch = 'a';
void *ptr = &ch;
std::cout<<ptr <<"\n";



    return 0;
}