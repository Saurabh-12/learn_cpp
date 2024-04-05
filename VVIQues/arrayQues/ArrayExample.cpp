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

void separateOddEven(int *arr, const int size) {

    int i = 0 , j = size;

    while (i <j) {
        if(arr[i] % 2 == 0)
           i++;
        else if (arr[j] % 2 != 0)
           j--;
        else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
}

void separateOddEvenUsingForLoop (int arr[], int size) {
    for (int i = 0; i < size ; i++)
    {
        if (arr[i] % 2 == 0) {
            continue;
        }
        for ( int j = i+1; j < size; j++) {
            if (arr[j] % 2 == 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
        }
    }
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

    //separateOddEven(arr,end);
    separateOddEvenUsingForLoop(arr,end);
    for (int aa : arr)
        std::cout << aa << " ";
    printf("\n");

    return 0;
}