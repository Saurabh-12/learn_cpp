#include <iostream>
#include <set>
#include <vector>
#include<algorithm>


using namespace std;


// Function to remove duplicate elements
// This function returns new size of modified array.
int removeDuplicateWithoutUsingExtraArray(int arr[], int n)
{

    if (n==0 || n==1)
        return n;
 
    // To store index of next unique element
    int j = 0;
    for (int i=0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];
 
    arr[j++] = arr[n-1];
 
    return j;
}

// Function to remove duplicate using extra Array
int removeDuplicate(int arr[], int n){
    int temp[n];
    int j = 0;

    if (n == 0 || n == 1)
        return n;

    for (int i = 0 ;i < n-1; i++)
    {
        if(arr[i] != arr[i+1])
          temp[j++] = arr[i];
    }
    //Add the last element in temp array
    temp[j++] = arr[n-1];

//// Modify original array
    for(int i = 0; i <j; i++)
    {
        arr[i] = temp[i];
    }
    //return unique element size of array
    return j;
}

int removeDuplicateUsingSet(int arr[], int n){
    if ( n <=1)
        return n;
    set<int> uniqueElements;

    for (int i = 0; i < n; ++i) {
        uniqueElements.insert(arr[i]);
    }

    int j = 0;
    for (auto it = uniqueElements.begin(); it != uniqueElements.end(); ++it) {
        arr[j++] = *it;
    }
 
    return uniqueElements.size();
}

// remove duplicate using vector
int removeDuplicateUsingVector(int arr[], unsigned size, int val) {
    vector<int>nums;
    for(unsigned i = 0 ; i <size; i++)
       nums.push_back(i);

      // remove element that is matching with val
    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());

    // update the original array
    for(unsigned i = 0; i<nums.size(); i++)
      arr[i] = nums[i];

    return nums.size();
}

void bubbleSort(int arr[], int size)
{
    int temp = 0;

    for (int i = 0; i<size; i++)
    {

        for ( int j = 0; j <size-1; j++) {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    } 
}

int main () {

    int arr[] {1, 2, 2, 2, 4, 5, 4, 7, 8, 7, 3, 6, 4, 7, 2};
    for (auto aa : arr)
        cout<<aa<<" ";
    printf("\n");
    int size = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, size);

        for (auto aa : arr)
        cout<<aa<<" ";
    printf("\n");

   // size = removeDuplicate(arr,size);
   //size = removeDuplicateWithoutUsingExtraArray(arr, size);
   //size = removeDuplicateUsingSet(arr, size);
   size = removeDuplicateUsingVector(arr,size, 2);

    for (int i = 0; i <size; i++)
     cout<<arr[i]<<" ";
    printf("\n");

    

    return 0;
}