#include <iostream>
#include <thread>
#include <mutex>
#include<condition_variable>
#include<queue>


using namespace std;

mutex mtx;
//queue<int> buffer;
int i = 0;
int num = 10;
condition_variable cv;


void producer() {
    {
        lock_guard<mutex> lock(mtx);
        // buffer.push(1);
        while (num > 0)
        {
            if (i == 0)
                i = 1;
            cout << i << endl;
            num--;
            cv.notify_one();
        }
    }
}

void consumer() {
    {
        lock_guard<mutex>lock(mtx);
        while(num >0 ){
        if( i == 1)
           i = 0;
        cout<<i<<endl;
        num--;
        cv.notify_one();
        }
    }
}

int main () {

    std::thread producerThread(producer);
    std::thread consumerThread(consumer);
    producerThread.join();
    consumerThread.join();

    return 0;
}

