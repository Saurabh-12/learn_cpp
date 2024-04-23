# include <iostream>
# include <thread>
# include <mutex>
# include <condition_variable>
# include <chrono>


using namespace std;

const int MAX_NUM = 100;

mutex mtx;
condition_variable cv;
int count = 1;

void printNumber(int threadID) {

    while(true) {

        if(count > MAX_NUM) {
            break;
        }

        //Since we are entering the critical section we take lock on mutex.
        // Reason for using unique_lock is that it will unlock and get the lock
        // as per the need. We dont have to explicitly call mutex unlock.
        unique_lock<mutex> lock(mtx);
        if ((threadID == 1 && count % 2 == 1) || (threadID == 2 && count % 2 == 0)) 
        {
            std::cout << "  Thread " << threadID << ":" << count<<std::endl;
            count++;
            cv.notify_all(); // And we notify the thread waiting for its turn.
        }else
        {
          cv.wait(lock); // And we wait for notification
        }
    }
}

void printZeroOne(int threadId) {
    while(true) {

        if(count > MAX_NUM) {
            break;
        }

        unique_lock<mutex> lock(mtx);
        if (threadId == 1 && count % 2 == 1) {

            cout << "Thread-" << threadId << "  : 1 " <<endl; 
            printf("\n");
            count++;
            this_thread::sleep_for(chrono::seconds(1));
            cv.notify_all();

        } else if (threadId == 2 && count % 2 == 0) {
            cout << "Thread-" << threadId << "  : 0 " <<endl; 
            printf("\n");
            count++;
            this_thread::sleep_for(chrono::seconds(1));
            cv.notify_all();
        } else {
            cv.wait(lock);
        }
    }
}


void printEven() {
    while (true) {
        if (count > MAX_NUM) {
            break;
        }
        unique_lock<mutex>lock(mtx);
        if (count % 2 == 0) {
            cout << "Even Number: "<<count<<endl;
            count++;
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        //this_thread::sleep_for(chrono::milliseconds(500));
        // Edit - Not really needed as unique_lock will take care.
        //lock.unlock(); // Release the lock
        //std::this_thread::yield(); // Yield the CPU to the other thread
    }

}

void printOdd()
{
    while (true)
    {
        if (count > MAX_NUM)
        {
            break;
        }
        unique_lock<mutex> lock(mtx);
        if (count % 2 == 1)
        {
            cout << "Odd Number: " << count << endl;
            count++;
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        
        // Edit - Not really needed as unique_lock will take care.
        // lock.unlock(); // Release the lock
        // std::this_thread::yield(); // Yield the CPU to the other thread
    }
}

void printZero() {
    while (true) {
        if (count > MAX_NUM)
             break;
        unique_lock<mutex> lock(mtx);

        if ( count % 2 == 0) {
            cout << "Thread-1 : "<<0<<endl;
            count++;
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

}

void printOne() {

    while (true) {
        if (count > MAX_NUM)
           break;
        unique_lock<mutex> lock(mtx);
        if ( count % 2 == 1) {
            cout << "thread-2 : "<<1<<endl;
            count++;
            printf("\n");
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

}


int main () {

    //thread t1(printNumber,1);
    //thread t2(printNumber,2);

    //thread t1(printZeroOne, 1);
    //thread t2(printZeroOne, 2);

    //thread t1 (printEven);
    //thread t2 (printOdd);
    thread t1 (printOne);
    thread t2 (printZero);
    t1.join();
    t2.join();

    return 0 ;
}