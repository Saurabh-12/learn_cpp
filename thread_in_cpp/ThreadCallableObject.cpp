#include<iostream>
#include<thread>

//Example 
void function_pointer_example()
{
    std::cout<<" Function Pointer Example"<<'\n';
}

// generic lambda, operator() is a template with two parameters
auto glambda = [](int a, int b) { 
    std::cout<<" a + b = "<<a+b<<'\n';
    return a+b; 
    };

// Define the class of function object
class Fn_object_class {
    public:
    // Overload () operator
    void operator()()
    {
        std::cout<<" Function object thread example"<<'\n';

    }
};


int main()
{
    //Thread 1
    std::thread t1(& function_pointer_example);
    t1.join();
//Thread 2
    std::thread t2(glambda,5,6);
    t2.join();
//Thread 3
   Fn_object_class fnObj;
   std::thread t3(fnObj);
   t3.join();

  return 0;
}