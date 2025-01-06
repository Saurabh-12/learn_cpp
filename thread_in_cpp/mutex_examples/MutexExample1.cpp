#include<iostream>
#include<mutex>
#include<thread>

using std::cout;
using std::endl;

std::mutex mtx;
std::timed_mutex timed_mtx;
std::recursive_mutex recur_mtx;
std::recursive_timed_mutex recur_timed_mtx;


void printEvenNumber(const int num){
    std::lock_guard<std::mutex> lock(mtx);
    for(int i = 0; i < num ; i+=2){
        cout<<i<<endl;
    }

}

void printOddNumber(const int num){
    std::lock_guard<std::mutex> lock(mtx);
    for(int i = 1; i < num ; i+=2){
        cout<<i<<endl;
    }

}

void tryLockingMutexForDuration() {

    if(timed_mtx.try_lock_for(std::chrono::seconds(1))){
        cout<<"Acquired lock within 1 seconds"<<endl;
    } else {
        cout << "Failed to acquire lock within 1 second!"<<endl;
    }
}

void recursiveFunction(int count){
    if (count <1) return;
    std::lock_guard<std::recursive_mutex>lock(recur_mtx);
    cout<<"cout: "<<count<<endl;
    recursiveFunction(count-1);
}

void timed_recursiveFunction(int count){
    if (recur_timed_mtx.try_lock_for(std::chrono::milliseconds(1)))
    {
        if (count < 1)
            return;
        std::lock_guard<std::recursive_mutex> lock(recur_mtx);
        cout << "cout: " << count << endl;
        recursiveFunction(count - 1);
    } else {
        cout<<"Failed to acquire lock!"<<endl;
    }
}



int main() {

    std::thread t1 (printEvenNumber,10);
    std::thread t2 (printOddNumber,10);
    std::thread t3 (tryLockingMutexForDuration);
    std::thread t4 (recursiveFunction,10);
    std::thread t5 (timed_recursiveFunction,5);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    

    return 0;
}