#include<queue>
#include<mutex>
#include<condition_variable>

template<typename T>
class Queue_Thread_Safe {
private:
    std::queue<T> q;            // Underlying queue to store elements
    std::condition_variable cv; // Condition variable for synchronization
    std::mutex mtx;             // Mutex for exclusive access to the queue

public:
    //push element in queue
    void push(T const& val) {
        std::lock_guard<std::mutex>lock(mtx);
        q.push(val);
        cv.notify_one();// Notify one waiting thread that data is available
    }

    // Pops and returns the front element of the queue
    T pop(){
        std::unique_lock<std::mutex>ulock(mtx);
        cv.wait(ulock,[&]{return !q.empty();});//Wait until the queue is not empty
        T front = q.front();                      
        q.pop();                                  
        return front; 
    }

};