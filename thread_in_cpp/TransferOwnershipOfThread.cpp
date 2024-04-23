# include <iostream>
#include<thread>


using namespace std;

/*
Suppose you want to write a function that creates a thread to run in the background,but passes ownership of the 
new thread back to the calling function rather than waiting for it to complete.

Or maybe you want to do the reverse: create a thread and pass ownership in to some function that should wait for it to complete

In either case, you need to transfer ownership from one place to another
*/


/*
This is where the move support of std::thread comes in . Many resource-owning types in the C++ Standard Library, such as
std::ifstream and std::unique_ptr , are movable but not copyable, and std::thread is one of them
*/

void some_function();

void some_other_function();



int main() {

    thread t1(some_function);

    thread t2 = std::move(t1); // ownership is transferd to t2 using move

    t1 = thread(some_other_function); // A new thread is started and associated with a temporary std::thread object
                                      // The subsequent transfer of ownership into t1 doesn’t require a call to std::move() to
                                      //explicitly move ownership, because the owner is a temporary object—moving from 
                                      //temporaries is automatic and implicit

    thread t3; // t3 is default-constructed, which means that it’s created without any associated thread of execution
    t3 = std::move(t2); // Hence explicit call to std::move() is used to transfer the ownership because t2 is a named object

    t1 = std::move(t3); // this assignment will terminate program Because in this case t1 already had an associated thread 
                        //(which was running some_other_function ), so s td::terminate() is called to terminate the program

    return 0;
}