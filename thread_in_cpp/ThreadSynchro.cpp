#include <iostream>
#include <thread>
#include <condition_variable>
#include<mutex>

using namespace std;

/*
Mutexes (Mutual Exclusion)
Mutexes provide a mechanism for mutual exclusion, allowing only one thread to access a shared resource at a time
*/
condition_variable cv;
mutex mtx;


void sharedResourceAccess(int i) {
    mtx.lock();
    cout << "Thread " << i << std::endl;
    mtx.unlock();
}

void resetIntAndPrint(int i) {
    int n = 0; // shared variable
    while (n <= 100) {
        // new block to release the lock at the end of each turn
      unique_lock<mutex> l(mtx);
            // wait if it is not your turn and n<=100
      while (n%3!=i%3 && n<=100) cv.wait(l);

      if (n <= 100)
      {
          cout << "Thread " << i << std::endl;
          n++;
      }
      cv.notify_all();
    }
}

int main () {

    thread t1 (resetIntAndPrint, 1);
    thread t2 (sharedResourceAccess, 2);
    //join
    t1.join();
    t2.join();

    return 0;
}