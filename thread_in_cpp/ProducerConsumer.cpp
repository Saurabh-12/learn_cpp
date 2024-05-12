#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <queue>

using namespace std;

mutex mtx;
condition_variable cv;
queue<int>buffer;
int buffer_size = 10;

void producer() {
    for (int i = 0 ; i < 20; i ++){
        unique_lock<mutex>lock(mtx);
        cv.wait(lock,[]{return buffer.size() < buffer_size;});
        buffer.push(i);
        cout <<"Produce: "<<i<<endl;
        lock.unlock();
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}


void consumer() {
    for (int i = 0; i <20; i++){
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });
        int val = buffer.front();
        buffer.pop();
        cout << "Consumed: "<<val<<endl;
        lock.unlock();
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}


int main() {

    thread producerThread(producer);
    thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}