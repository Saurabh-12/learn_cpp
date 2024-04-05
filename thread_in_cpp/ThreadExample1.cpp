#include <iostream>
#include <thread>
#include <stdexcept>

using namespace std;



void do_something(int& i) {
    ++i;
    cout<<"i "<<i<<endl;
}

struct Func {
    int& i;

    Func (int& i_):i(i_) {}

 void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }

};

void doSomethingInCurrentThread() {
    int num = 10;
    cout<<"print num Value: "<<num<<endl;
    while(num) {
        num = num/10;
    } 
    //int k = 10/0;
    cout<<"print num Value: "<<num<<endl;
}


void oops() {
    int localVariable = 0;
    Func myFunc (localVariable);
    thread my_thread(myFunc);
    //my_thread.detach();
  // my_thread.join();

    try
    {
        doSomethingInCurrentThread();
    }
    catch(const exception& e)
    {
        my_thread.join();
        //throw;
        cout << "Exception " << e.what() << endl;
    }

    my_thread.join();


}



int main () {
    cout<<"First print of main before oops Func call"<<endl;
    oops();
    cout << "Second Print of main after oops Func call"<<endl;

    return 0;
}