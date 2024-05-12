# include <iostream>
# include <thread>
# include <chrono>
# include <mutex>
# include <string>
# include <condition_variable>


using namespace std;


class SingletonExample {

    private:
      static SingletonExample* instance;
      SingletonExample() {};
      int data = 0;
      string value;

    public:
        //Singletons should not be cloneable, copy constructore
        SingletonExample(const SingletonExample &other) = delete;

         //Singletons should not be assignable.
        void operator = (const SingletonExample &old) = delete;

    static SingletonExample* getInstance() {
        if(instance == NULL) {
            instance = new SingletonExample();
            return instance;
        } else {
            return instance;
        }
    }

    int getData() {
        return data;
    }

    string getString() {
        return value;
    }

    void setValue(string value) {
        this -> value = value;
    }

    void setData(int data) {
        this -> data = data;
    }

    //Some business logic 
    void printHello() {
        cout<<value<<endl;
    }

};
// initializing instancePtr with NULL
SingletonExample* SingletonExample ::instance = NULL; 

void threadFunc1() {
    this_thread::sleep_for(chrono::seconds(1));
    SingletonExample* singleton = SingletonExample ::getInstance();
    cout << "Address of Object in Thread 1: "<<singleton<<endl;
     cout << " Data thread 1 "<<singleton -> getData()<<endl;
     singleton -> setData(18);
    singleton -> setValue("thread function 1");
    cout << " Data set in thread 1 "<<singleton -> getData()<<endl;
    singleton -> printHello();
    printf("\n");
}

void threadFunc2() {
    this_thread::sleep_for(chrono::seconds(1));
    SingletonExample* singleton = SingletonExample::getInstance();
    cout << "Address of Object in Thread 2: "<<singleton<<endl;
    cout << " Data thread 2 "<<singleton -> getData()<<endl;
    singleton -> setData(11);
    singleton -> setValue("Thread Function 2");
    cout << "Data set in thread 2 : "<<singleton -> getData()<<endl;
    singleton -> printHello();
    printf("\n");
}


int main () {

    SingletonExample* sks = SingletonExample::getInstance();
    sks -> setValue("Saurabh Sharma");
    cout <<sks -> getString()<<endl;

    thread t1(threadFunc1);
    thread t2(threadFunc2);
    t1.join();
    t2.join();
    
    SingletonExample* gfg = SingletonExample ::getInstance();
    cout << " Data Main thread 1 "<<gfg -> getData()<<endl;
    gfg -> setValue("Main Thread 1");
    gfg -> setData(22);
    cout <<"Get Data after set in main thread 1: "<<gfg -> getData()<<endl;
    gfg -> printHello();
    printf("\n");
    cout << "Address of gfg: "<<gfg<<endl;
    printf("\n");

    SingletonExample* gfg1 = SingletonExample ::getInstance();
    cout << "Data Main thread 2: "<<gfg1 -> getData()<<endl;
    gfg -> setValue("Main Thread 2");
    gfg -> setData(33);
    cout <<" Data after set  in Main thread 2: "<<gfg1 -> getData()<<endl;
    gfg -> printHello();
    printf("\n"); 
    cout << "Address of gfg1: "<<gfg1<<endl;
    printf("\n");

    return 0;
}
