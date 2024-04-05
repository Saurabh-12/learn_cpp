# include <iostream>
#include <thread>


using namespace std;


void Hello() {
    cout<<"Welcome to c++ multithreading world"<<endl;
}


int main() {

    thread t (Hello);
    t.join();

    return 0;
}