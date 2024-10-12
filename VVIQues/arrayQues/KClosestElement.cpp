
#include<iostream>
#include<vector>

using namespace std;

/*
Given a array, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
Keep the following points in mind:

If x is present in the array, then it need not be considered.
If two elements have the same difference as x, the greater element is prioritized.
If sufficient elements are not present on the right side, take elements from the left and vice versa.

Example :

Input:
n = 13
arr[] = {12, 16, 22, 30, 35, 39, 42, 
         45, 48, 50, 53, 55, 56}
k = 4, x = 35
Output: 39 30 42 45
Explanation: 
First closest element to 35 is 39.
Second closest element to 35 is 30.
Third closest element to 35 is 42.
And fourth closest element to 35 is 45.


Example 2:

Input:
n = 5
arr[] = {1, 2, 3, 6, 10}
k = 3, x = 4
Output: 3 6 2
Explanation: 
First closest element is 3.
There are two elements 2 and 6 for which 
the difference with 4 is same i.e. 2.
So first take greatest number 6 
then the lower number 2.
*/


class Solution {
public:
    vector<int> printKClosest(vector<int>& arr, int n, int k, int x) {
        // Find the crossover point
        int id1 = findCrossOver(arr, 0, n - 1, x);
        
        // Initialize the second index
        int id2 = id1 + 1;
        
        // If x is present in the array, ignore it by decrementing id1
        if (arr[id1] == x) id1--;

        // Result vector to store the k closest elements
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            // If both indices are valid
            if (id1 >= 0 && id2 < n) {
                // Calculate the differences from x
                int val1 = x - arr[id1], val2 = arr[id2] - x;
                // Choose the closer value or the greater value in case of tie
                if (val1 < val2) {
                    ans[i] = arr[id1];
                    id1--;
                } else {
                    ans[i] = arr[id2];
                    id2++;
                }
            } else if (id1 >= 0) { // If only id1 is valid
                ans[i] = arr[id1];
                id1--;
            } else { // If only id2 is valid
                ans[i] = arr[id2];
                id2++;
            }
        }
        
        return ans;
    }

private:
    int findCrossOver(vector<int>& arr, int low, int high, int x) {
        // Base case: x is greater than all elements
        if (arr[high] <= x) {
            return high;
        }
        // Base case: x is smaller than all elements
        if (arr[low] > x) {
            return low;
        }
        // Find the middle index
        int mid = (low + high) / 2;
        // Check if mid is the crossover point
        if (arr[mid] <= x && arr[mid + 1] > x) {
            return mid;
        } 
        // Recur to the right half if mid is less than x
        else if (arr[mid] < x) {
            return findCrossOver(arr, mid + 1, high, x);
        }
        // Recur to the left half if mid is greater than x
        return findCrossOver(arr, low, mid - 1, x);
    }
};


int main () {


vector<int> arr {12, 16, 22, 30, 35, 39, 42, 
         45, 48, 50, 53, 55, 56};
int size = arr.size();
int k = 4;
int x = 35;

Solution sol;
vector<int> ans = sol.printKClosest(arr,size,k,x);
for(auto kk : ans) cout<<kk<<" ";
printf("\n");


    return 0;
}