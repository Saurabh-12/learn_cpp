#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "First example thread in cpp";
}

int main()
{
    std::cout << "1st print from  Main thread " << '\n';
    std::thread mThread(&thread_function); // thread starts running
    //mThread.join();                        // main thread waits for the thread t to finish
    mThread.detach();
    std::cout<<" mThread.joinable() "<<mThread.joinable()<<'\n';
    if(mThread.joinable())
    {
       mThread.join(); //Once a thread detached, 
       //we cannot force it to join with the main thread again
    }
    std::cout << " 2nd Print from Main thread"
              << "\n";

    return 0;
}