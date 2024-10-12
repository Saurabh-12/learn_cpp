#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <Queue_Thread_Safe.cpp>


using namespace std;

//Example 
int func(int a)
{
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"This is time taking function" <<std::endl;
    return a*a; 
}

class ThreadPools {
private:
    int m_threads;
    vector<thread>threads;
    queue<function<void()>>tasks;
    mutex mtx;
    condition_variable cv;
    bool stop;

public:
    explicit ThreadPools(int numThreads):m_threads(numThreads), stop(false)
    {
        for(int i = 0; i<m_threads; i++)
        {
            threads.emplace_back([this]
            {
                function<void()>task;
                while(1){
                  unique_lock<mutex>lock(mtx);
                  cv.wait(lock,[this] {
                    return !task.empty()|| stop;
                  });
                  if(stop)
                    return;
                  task = move(task.front());
                  tasks.pop();
                  lock.unlock();
                  task();
                }
            });
        }
    }

    ~ThreadPools(){
      unique_lock<mutex> lock(mtx);
      stop = true;
      lock.unlock();
      cv.notify_all();

      for(auto& th: threads)
      {
        th.join();
      }
    }

    template<class F, class... Args>
    auto ExecuteTask(F&& f, Args&&... args)-> future<decltype(f(args...))>
    {
        using return_type = decltype(f(args...));
        auto task = make_shared<packaged_task<return_type()>>(bind(fprward<F>
                    (f),forward<Args>(args)...));

        future<return_type> res =task->get_future();

        unique_lock<mutex>lock(mtx);
        tasks.emplace([task]()-> void {(*task)()});
        lock.unlock();
        cv.notify_one();
        return res;
    }

};


