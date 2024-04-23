# include <iostream>
# include <thread>
# include <chrono>

using namespace std;

class ScopedThread {
    thread t;

    public:
        explicit ScopedThread(std::thread t_) : t(std::move(t_)) {
             t.join();
             if (!t.joinable()) 
                throw std::logic_error("No thread");
        }

     ~ScopedThread() {
        t.join();
     }

     ScopedThread (ScopedThread const &) = delete;
     ScopedThread& operator=(ScopedThread const&) = delete;

};

void doSomething(int& i) {
    ++i;
    printf(" %d : ", i);
    printf("\n");
}

struct Func
{
    int& i;

    Func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<100;++j)
        {
            doSomething(i);
        }
    }
};

void do_something_in_current_thread() {
    int num = 10;
    cout<<"print num Value: "<<num<<endl;
    while(num) {
        num = num/10;
    } 
    //int k = 10/0;
    cout<<"print num Value: "<<num<<endl;
}

void f()
{
    int some_local_state = 1;

    ScopedThread t(thread t (Func(some_local_state)));

    do_something_in_current_thread();
}


int main () {
    printf("Main thread started\n");
    printf("\n Main thread calling function f() \n");

    f();

    printf("Main thread continue...and waiting for 10 sec");
    this_thread::sleep_for(chrono::seconds(12));
    cout << "Main thread wait completed"<<endl;
    return 0;
}