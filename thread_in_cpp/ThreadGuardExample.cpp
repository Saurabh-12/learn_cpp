# include <iostream>
#include <thread>
#include <stdexcept>

using namespace std;


class ThreadGuard {
     thread& t;

    public:
    //Explicit Keyword in C++ is used to mark constructors to not implicitly convert types in C++
    //It is optional for constructors that take exactly one argument and work on constructors(with a single argument)
    // since those are the only constructors that can be used in typecasting.
      explicit ThreadGuard(thread& _t): t(_t) {}

      ~ThreadGuard(){
        if(t.joinable())
           t.join();
      }

      /*
      It is called when a new object is created from an existing object, as a copy of the existing object
      It creates a separate memory block for the new object.
      C++ compiler implicitly provides a copy constructor, if no copy constructor is defined in the class.
      Hence delete copy constructor , prevent compiler to provide implicitly copy constructor
      */
      ThreadGuard(ThreadGuard const&) = delete;



      // delete assignment operator
      /*
       = operator is called when an already initialized object is assigned a new value from another existing object. 
       It does not create a separate memory block or new memory space
       C++ compiler implicitly provides A bitwise copy of assignment(=), if the Assignment operator is not overloaded
       delete assignment operator prevent compiler to provide implicitly assignment (=) operator 
      */
      ThreadGuard& operator = (ThreadGuard const &) = delete;

      /*
      example 
      Test t1, t2;
      t2 = t1;  => Assignment operator called
      Test t3 = t1;  => Copy constructor called
      */

};

void do_something(int& i) {
    ++i;
    cout<<"i "<<i<<endl;
}

struct Func {
    int& i;

    Func (int& i_):i(i_) {}

 void operator()()
    {
        for(unsigned j=0;j<100;++j)
        {
            do_something(i);
        }
    }

};

void doSomethingInCurrentThread() {
    int num = 10;
    cout<<"print num Value: "<<num<<endl;
    while(num) {
        num = num/10;
    } 
    //int k = 10/0;
    cout<<"print num Value: "<<num<<endl;
}

void f()
{
    int some_local_state;
    Func my_func(some_local_state);
    thread t(my_func);
    ThreadGuard g(t);

    doSomethingInCurrentThread();
}

int main () {
    f();

    return 0;
}