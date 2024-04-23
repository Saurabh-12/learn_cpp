# include <iostream>
# include <thread>
#include <chrono>

using namespace std;

/*
The move support in std::thread means that ownership can readily be transferred out of a function, 
as shown in the following example
*/
thread func1() {

    void some_function();
    return thread(some_function);
}

thread func2() {
    void some_other_function(int);
    thread t (some_other_function, 42);
    return t;
}


/*
  if ownership should be transferred into a function, it can accept an instance of std::thread by value as one of the parameters
  Examples given below
*/

void func3(std::thread t) {
    //do some operation
     this_thread::sleep_for(std::chrono::seconds(3));
    if (t.joinable())
         t.join();
    printf("this func3 is take thread as argument by value");
    printf("\n");
}

void func4()
{
    void some_function(); // template of function that need to pass in thread

    func3(std::thread(some_function)); // func3 that take thread as an argument pass by value , thread start execution and then join it with main thread to finish gracefully.

    std::thread t(some_function);  // creation of temporary thread object with callable function, it start execution and finish gracefully by line No 46 

    func3(std::move(t)); // temp thread t passed as argument to func3 using move semantics. Now Func3 join this thread and finish it gracefully.
}

int main() {

    cout << "Main thread or main function call start"<<endl;
    std::thread t1=func1();
    t1.join();

    std::thread t2=func2();
    t2.join();

    cout<< "Now main thread calling func4 "<<endl;
    func4();

   //this_thread::sleep_for(chrono::seconds(5));
   printf("Main thread or main function call finished\n");

    return 0;
}


void some_function() {
    //print number 1 to 10 with 500 ms delay
    for (int i = 1; i <11; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    //this_thread::sleep_for(chrono::milliseconds(500));
}

void some_other_function(int num) {
    printf("Value passed in %s  is  %d  ", __func__,num);
    printf("\n");
    // reverse the number
    int reverse = 0;
    int reminder = 0;
    while (num >0) {
        reminder = num % 10;
        reverse = (reverse *10) + reminder;
        num =  num/10;
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    printf("Reverse of given number is : %d ",reverse);
    printf("\n");
}