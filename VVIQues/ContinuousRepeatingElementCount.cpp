#include <iostream>

using namespace std;


int continuousRepeatingElementCount(int arr[], int n) {
    int count = 0;
    int i = 0;
    while (i < n) {
        if (arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        else {
            i++;
            count = 0;
        }
    }
    return ++count;
}



int main() {
    int arr[] = {1,1, 0,1,1,1};
    int size = sizeof(arr) / (sizeof(arr[0])-1);

    cout << "The count of continuous repeating elements is " << continuousRepeatingElementCount(arr, size) << endl;
}