#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto partition_point = std::partition(data.begin(), data.end(), 
        [](int n) { return n % 2 == 0; });

    std::rotate(data.begin(), partition_point, data.end());

    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}