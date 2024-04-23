#include<iostream>
#include<thread>


using namespace std;

/*
passing arguments to the callable object or function is fundamentally as simple as passing additional 
arguments to the std::thread constructor

But it’s important to bear in mind that by default, the arguments are copied into internal storage, 
where they can be accessed by the newly created thread of execution, and then passed to the callable object 
or function as rvalues as if they were temporaries

This is done even if the corresponding parameter in the function is expecting a reference. 
Here’s an example

*/

void testFunction(int i,string const& s);


   /*
    This is particularly important when the argument supplied is a pointer to an automatic variable, as follows :

    In this case, it’s the pointer to the local variable buffer that’s passed through to the new thread and 
    there’s a significant chance that the oops function will exit before the buffer has been converted to a std::string 
    on the new thread, thus leading to undefined behavior.
    */

void oops(int some_param)
{
    char buffer[1024];

    sprintf(buffer, "%i", some_param);

    std::thread t(testFunction, 3, buffer);

    t.detach();
}

// the solution is to cast to std::string before passing the buffer to the std::thread constructor
//std::thread t(f,3,std::string(buffer));
//std::thread t(f,3,std::ref(buffer));
/*
In this case, the problem is that we were relying on the implicit conversion of the pointer to the buffer into the std::string 
object expected as a function parameter, but this conversion happens too late because the std::thread constructor copies 
the supplied values as is, without converting to the expected argument type
*/



int main() {

    /*
    This creates a new thread of execution associated with t , which calls testFunction(3,”hello”) .
    Note that even though testFunction takes a std::string as the second parameter, the string literal is passed as a
    char const* and converted to a std::string only in the context of the new thread
    */
    thread t(testFunction, 3, "Hello");

    string data = "Hello";
    thread t(testFunction, 3, std::ref(data));



    return 0;
}