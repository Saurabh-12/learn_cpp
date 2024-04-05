#include<iostream>



using namespace std;


void swap(int *a, int *b) {

int temp = *a;

*a = *b;

*b = temp;

}

void bubbleSort(int *arr, const int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}



int main() {

int a[] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

printf("Before Sorting: \n");
for (int aa : a) {

cout << aa << " ";

}
printf("\n");
int Size = sizeof(a) / sizeof(a[0]);
bubbleSort(a, Size);

printf("After Sorting: \n");
for (int aa : a) {

cout << aa << " ";

}
printf("\n");


return 0;

}