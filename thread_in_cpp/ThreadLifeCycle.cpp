#include <iostream>
#include <thread>
#include <chrono>


using namespace std;

/*
we create a thread object t and pass it the function threadFunction. We then do something else in the main thread.
Because we do not call join or detach on the thread object t, the thread will continue to run in the background 
even after the main thread exits.

It is important to note that if the thread object t is not joined or detached before the main thread exits, 
the program will be terminated. This is because the thread object t will still be running and holding resources.

*/

void threadFunction(int id)
{
    cout << "Thread " << id <<" created. Executing threadFunction. " << std::endl;

    // Mimics a task being processed
    this_thread::sleep_for(std::chrono::seconds(3));

    cout <<"Thread " << id <<" finishing. Exiting threadFunction."<< std::endl;
}

int main () {
    printf("Main function or main thread is started , Now going to create 2 thread\n");

    thread t1 (threadFunction, 1);
    thread t2 (threadFunction, 2);

    printf("2 thread created, Main thread continue its to work\n");
    printf("\n");

     // Performing some main thread tasks
    this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Main function continues to execute parallel to threads." << std::endl;
    printf("\n");
    this_thread::sleep_for(std::chrono::seconds(1));


    // Joining threads - waiting for them to finish
    t1.join();
    std::cout << "\nThread 1 joined." << std::endl;
    t2.join();
    std::cout << "\nThread 2 joined." << std::endl;

    std::cout << "\nMain function finished. Program terminated." << std::endl;


    return 0;
}