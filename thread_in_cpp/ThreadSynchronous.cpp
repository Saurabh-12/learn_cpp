#include <iostream>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

// Define the queue to be used for communication between the producer and consumer threads.
queue<int> q;

// Define the condition variable to be used for signaling between the producer and consumer threads.
condition_variable cv;

// Define the mutex to be used for protecting the queue.
mutex mtx;

// Define the producer thread function.
void producer() {
  // Continuously produce data and add it to the queue.
  while (true) {
    // Lock the mutex.
    lock_guard<mutex> lock(mtx);

    // Produce a new data item.
    int data = rand() % 100;

    // Add the data item to the queue.
    q.push(data);

    // Notify the consumer thread that new data is available.
    cv.notify_one();

    // Unlock the mutex.
  }
}

// Define the consumer thread function.
void consumer() {
  // Continuously consume data from the queue.
  while (true) {
    // Lock the mutex.
    lock_guard<mutex> lock(mtx);

    // Wait for new data to be available.
    cv.wait(lock, []() { return !q.empty(); });

    // Consume the data item from the queue.
    int data = q.front();
    q.pop();

    // Unlock the mutex.

    // Process the data item.
    cout << "Consumed data item: " << data << endl;
  }
}

int main() {
    // Create the producer and consumer threads.
thread producer_thread(producer);
thread consumer_thread(consumer);

// Start the producer and consumer threads.
producer_thread.join();
}