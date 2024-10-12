#include<iostream>
#include <future>
#include <chrono>
#include <ThreadPools.cpp>

using namespace std;

int main(){
  cout<< "Thread Pool Started \n";
  
  ThreadPools myPool(16);
  
  future<int>res = pool.ExecuteTask(Func,2);
  pool.ExecuteTask([](){
           cout<<"This is from Lambda Function \n";
           this_thread::SLEEPfor(chrono::milliseconds(2000));
       });
  cout<<" result is : " <<res.get();

  return 0;
}