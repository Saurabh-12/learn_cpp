# include<iostream>
# include <climits>


using namespace std;


/*
Given a sorted array arr[] of positive integers. 
The task is to find the closest value in the array to the given number k. 
The array may contain duplicate values.

Note: If the difference with k is the same for two values in the array return the greater value.

example : 
size  = 7
keyValue  = 4
arr[] = {1, 2, 3, 5, 6, 8, 9}
Output:
5
Explanation:
The absolute difference of 4 is 1 from both 3 and 5. 
According to the question, we have to return greater value, which is 5.

*/

int findClosest(int n, int k, int arr[]) {
    int diff = INT_MAX;
    int closeValue = arr[0];
    for (int i = 0; i < n; i++){
        if (abs(k -arr[i]) <= diff) {
            diff =  min(abs(k-arr[i]),diff);
            closeValue = max(closeValue,arr[i]);        }
    }

    return closeValue;
}

int main() {

    int arr[] = {1, 2, 3, 5, 6, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int keyValue =  4;

    for (auto kk : arr) {
        cout << kk << " ";
    }
    printf("\n");

    cout << "Closest Value of given key : "<<keyValue<< " is : " << findClosest(size, keyValue, arr)<<endl;
    printf("\n");


    return 0;
}