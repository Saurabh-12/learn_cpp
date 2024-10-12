# Multithreading support was introduced in C+11. 
# Prior to C++11, we had to use POSIX threads or p threads library in C
#C++ 11 provided  std::thread. The thread classes and related functions

# std::thread is the thread class that represents a single thread in C++
# To start a thread, we simply need to create a new thread object and 
# pass the executing code to be called (i.e, a callable object) 
# into the constructor of the object. Once the object is created a new thread is launched 
# which will execute the code specified in callable.

## A callable can be either of the three
   - A function pointer
   - A function object
   - A lambda expression
After defining callable, pass it to the constructor.


