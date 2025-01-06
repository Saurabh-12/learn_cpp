#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Task {
public:
    std::string name;
    int priority;

    Task(std::string n, int p) : name(std::move(n)), priority(p) {}
};

class Scheduler {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void runNextTask() {
        if (!tasks.empty()) {
            std::cout << "Running task: " << tasks.front().name << std::endl;
            std::rotate(tasks.begin(), tasks.begin() + 1, tasks.end());
        }
    }
};

int main() {
    Scheduler scheduler;
    scheduler.addTask({"Task1", 1});
    scheduler.addTask({"Task2", 2});
    scheduler.addTask({"Task3", 3});

    for (int i = 0; i < 5; ++i) {
        scheduler.runNextTask();
    }

    return 0;
}