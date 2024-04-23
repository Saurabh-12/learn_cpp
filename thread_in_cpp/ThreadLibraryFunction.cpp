#include <iostream>
#include<thread>

using namespace std;


int main() {

    //This function returns an indication of the number of threads that can truly run concurrently 
    //for a given execution of a program. On a multicore system it might be the number of CPU cores
    //This is only a hint, and the function might return 0 if this information isn’t available

    unsigned supportedThreadCount = thread::hardware_concurrency();

    cout << "Supported thread count: "<<supportedThreadCount<<endl;

    //get current thread id 
    auto threadId = this_thread::get_id();
    cout<<"thread Id: " << threadId<<endl;
    printf("\n");


    return 0;
}