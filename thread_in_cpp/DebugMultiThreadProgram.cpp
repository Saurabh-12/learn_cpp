#include <thread>
#include <iostream>
#include <vector>
#include <string>

int count = 0;

void doSomeWork(int threadID) {

    std::cout << "The doSomeWork function is running on threadID: " <<threadID<<std::endl;
    int data = count++;
    // Pause for a moment to provide a delay to make
    // threads more apparent.
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::string str = std::to_string(data);
    std::cout << "The function called by the worker thread has ended. " + str<< std::endl;
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {

        threads.push_back(std::thread(doSomeWork, i));
        std::cout << "The Main() thread calls this after starting the new thread" << std::endl;
}

for (auto& thread : threads) {
    thread.join();
}

return 0;
}