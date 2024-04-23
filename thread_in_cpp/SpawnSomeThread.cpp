# include <iostream>
# include <thread>
# include <chrono>
# include <vector>

using namespace std;

void doSomeWork(unsigned id) {
    cout <<"Thread Id: "<<id<<" created and now executing it"<<endl;

    //mimics thread is doing some heavy operation
    this_thread::sleep_for(chrono::seconds(1));

    cout<<" Thread Id: "<<id<<" is finished. Exit now"<<endl;

}

void spawnsThread() {
    vector<thread> threads;

    for (unsigned i = 1; i<21; i++){
        threads.push_back(thread(doSomeWork,i));
    }

    for(auto& entity:threads) {
        entity.join();
    }
}


int main() {

    cout<<"Main thread started and now calling SpawnsThread function"<<endl;

    spawnsThread();

    cout<<"Main thread is now doing some other work"<<endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout<<"Main thread is done. Exiting now"<<endl;

    return 0;
}