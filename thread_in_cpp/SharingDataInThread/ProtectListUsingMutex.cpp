# include<iostream>
#include<thread>
#include<mutex>
#include<algorithm>
#include<list>

using namespace std;

list<int>someList;
mutex mtx;

void addToList(int i) {
    lock_guard<mutex> gurad(mtx);
    someList.push_back(i);
}

bool listContainValue(int valueToFind) {
    lock_guard<mutex> guard(mtx);
    return find(someList.begin(), someList.end(), valueToFind) != someList.end();
}


int main() {
    printf("Main Thread function: %s  started \n",__func__);

cout<<"Main thread start adding elements in list using addToList function "<<endl;
    addToList(42);
    addToList(16);


cout<<"Main thread start searching elements in list using listContainValue function "<<endl;
cout<<"contains(1)="<<listContainValue(1)<<", contains(42)="<<listContainValue(42)<<std::endl;
cout<<"Main thread finished searching elements in list, Now doing some other task "<<endl;
this_thread::sleep_for(chrono::seconds(3));


    return 0;
}