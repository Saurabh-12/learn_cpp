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
int count= 1;


void sharedResourceAccess(int i) {
    mtx.lock();
    cout << "Thread " << i << std::endl;
    mtx.unlock();
}

void resetIntAndPrint(int i)
{
    int n = 0; // shared variable
    while (n <= 10)
    {
        // new block to release the lock at the end of each turn
        unique_lock<mutex> l(mtx);
        cout << "Thread " << i << std::endl;
        n++;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cv.notify_one();
    }
}
void print1() {
    int n = 10;
    unique_lock<std::mutex> locker(mtx);
  while (n>0) {
    cout << "1" << endl;
    count = 1;
    n--;
    cv.wait(locker,[](){ return (count == 1); });
    locker.unlock();
    cv.notify_all();
  }
}

void print0() {
    int n = 10;
    unique_lock<std::mutex> locker(mtx);
  while (n>0) {
    cout << "0" << endl;
    count = 0;
    cv.wait(locker,[](){ return (count == 0); });
    locker.unlock();
    cv.notify_all();
  }
}

void PrintOdd()
{
    for( ; ; )
    {
    std::unique_lock<std::mutex> locker(mtx);
    cv.wait(locker,[](){ return (count%2 == 1); });
    cout<< "From Odd:    " <<  count << endl;
    count++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    locker.unlock();
    cv.notify_all();
    }

}

void PrintEven()
{
    for( ; ; )
    {
    std::unique_lock<std::mutex> locker(mtx);
    cv.wait(locker,[](){return (count%2 == 0);});
    cout<< "From Even: " << count << endl;
    count++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    locker.unlock();
    cv.notify_all();
    }
}

struct OddEven {
    int x = 1;
    std::mutex m;
    std::condition_variable cond;
};

void printTask(OddEven &oe, bool odd)
{
    for (bool running{true}; running; ) {
        std::unique_lock<std::mutex> mlock(oe.m);
        oe.cond.wait(mlock, [&oe, odd] {
            return (oe.x & 1) == odd;
        });
        cout <<" "<< oe.x << std::endl;
        oe.x++;
        running = oe.x < 10;
        oe.cond.notify_all();
    }
}

int main () {

   // thread t1 (PrintOdd);
    //thread t2 (PrintEven);
    //join
    OddEven oe;
    thread t1(printTask, std::ref(oe), true);
    thread t2(printTask, std::ref(oe), false);
    t1.join();
    t2.join();

    return 0;
}