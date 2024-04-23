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
      std::string value;

    public:
        //Singletons should not be cloneable
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
        cout<< " Hello from SingletonExample "<<value<<endl;
    }

};
// initializing instancePtr with NULL
SingletonExample* SingletonExample ::instance = NULL; 

void threadFunc1() {
    this_thread::sleep_for(chrono::seconds(1));
    SingletonExample* singleton = SingletonExample ::getInstance();
    singleton -> getData();
    singleton -> setValue("thread function 1");
    singleton -> setData(18);
    singleton -> getData();
    singleton -> printHello();
    printf("\n");
}

void threadFunc2() {
    this_thread::sleep_for(chrono::seconds(1));
    SingletonExample* singleton = SingletonExample::getInstance();
    cout << " Data "<<singleton -> getData()<<endl;
    singleton -> setValue("Thread Function 2");
    singleton -> setData(11);
    cout << "Data after set: "<<singleton -> getData()<<endl;
    singleton -> printHello();
    printf("\n");
}


int main () {

    thread t1(threadFunc1);
    thread t2(threadFunc2);
    t1.join();
    t2.join();
    
    SingletonExample* gfg = SingletonExample ::getInstance();
    cout << " Data "<<gfg -> getData()<<endl;
    gfg -> setValue("Main Thread Function 1");
    gfg -> setData(22);
    cout <<" Data after set: "<<gfg -> getData()<<endl;
    gfg -> printHello();
    printf("\n");
    cout << "Address of gfg: "<<gfg<<endl;\
    printf("\n");

    SingletonExample* gfg1 = SingletonExample ::getInstance();
    cout << " Data "<<gfg1 -> getData()<<endl;
    gfg -> setValue("Main Thread Function 2");
    gfg -> setData(33);
    cout <<" Data after set: "<<gfg1 -> getData()<<endl;
    gfg -> printHello();
    printf("\n"); 
    cout << "Address of gfg1: "<<gfg1<<endl;
    printf("\n");

    return 0;
}
