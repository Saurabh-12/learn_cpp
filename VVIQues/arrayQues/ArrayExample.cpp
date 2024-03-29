#include <iostream>


void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reverseArrayRecursive(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArrayRecursive(arr, start + 1, end - 1);
}

int main () {


    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for ( int aa : arr) {
        std::cout << aa << " ";
    }
    std::cout << "\n";

    int start = 0;
    int end = sizeof(arr)/sizeof(arr[0]) - 1;
    printf("%d %d\n", start, end);
    //reverseArray(arr, start, end);
    reverseArrayRecursive(arr, start, end);
    for ( int aa : arr) {
        std::cout << aa << " ";
    }
    std::cout << "\n";

    return 0;
}