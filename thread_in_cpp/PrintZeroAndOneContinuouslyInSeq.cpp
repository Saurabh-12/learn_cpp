#include <iostream>
#include <thread>
#include <mutex>
#include<condition_variable>

using namespace std;

mutex mtx;
bool isReady = true;
condition_variable cv;
int num = 0;

void printNumber(int i)
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []{ return isReady; });
        cout << " " << i << endl;
        //num++;
        isReady != isReady;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        //cv.notify_one();
        lock.unlock();
        cv.notify_all();
    }
}


void printZero(int i){
    unique_lock<mutex> lk(mtx);
    while(true)
    {
        if(i == 0)
        {
            cv.wait (lk);
        }
        else
        {
            cout << " " << i << endl;
            //lk.unlock();
            cv.notify_one();
        }
    }
}


void printOne(int i){
    unique_lock<mutex> lk(mtx);
    while(true)
    {
        if(i == 1)
        {
            cv.wait (lk);
        }
        else
        {
            cout << " " << i << endl;
            //lk.unlock();
            cv.notify_one();
        }
    }
}

int main () {

    thread t1(printNumber, 1);
    thread t2(printNumber,0);

    // Start the Seq. by signaling the first thread to start the print
    cv.notify_one();

    t1.join();
    t2.join();

    return 0;
}