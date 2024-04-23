#include <iostream>
#include <algorithm>
#include <set>
#include<vector>

using namespace std;


void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while(i <n1)
      arr3[k++] = arr1[i++];
    
    while( j < n2)
      arr3 [k++] = arr2[j++];
    
    //sort(arr3, arr3+k);
    
}


void sortAndMergeArrays(int arr1[], int arr2[], int n1, int n2,int arr3[]) {
    int i = 0, j = 0, k= 0;

    // traverse both array and check its order and then insert in 3rd Array

    while (i <n1 && j < n2) {

        if ( arr1[i] < arr2[j])
           arr3[k++] = arr1[i++];
        else 
         arr3[k++] = arr2[j++];
    }

        // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}

    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int>s;
        for(int i=0;i<n;i++) s.insert(arr1[i]);
        for(int i=0;i<m;i++) s.insert(arr2[i]);
        return vector<int>(begin(s),end(s));
    }

void merge2Vector(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> mergedVec;
    int k = 0;
    int i = 0, j = 0;
    
    if (m <= 1 && n <= 0)
        return;
    if (m <= 0 && n <= 1)
    {
        nums1.at(i) = nums2.at(j);
        return;
    }

    if (m == 1 && n == 1)
    {
        if ((nums1[i] < nums2[j]))
        {
            mergedVec.push_back(nums1[i]);
            i++;
        }
        else
        {
            mergedVec.push_back(nums2[j]);
            j++;
        }
    }

    // Merge the vectors while both have elements remaining
    while (i < m && j < n)
    {
        if ((i < m && nums1[i] < nums2[j]))
        {
            mergedVec.push_back(nums1[i]);
            i++;
        }
        else
        {
            mergedVec.push_back(nums2[j]);
            j++;
        }
    }
    // Add remaining elements from vec1
    while (i < m)
    {
        mergedVec.push_back(nums1[i]);
        i++;
    }

    // Add remaining elements from vec2
    while (j < n)
    {
        mergedVec.push_back(nums2[j]);
        j++;
    }

    for (int i = 0; i < mergedVec.size(); i++)
        nums1.at(i) = mergedVec.at(i);
}

int main () {

    int arr1[] = {1, 11, 22, 33};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    int arr2[] = {2, 20, 16, 8,40};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
 
    int arr3[n1+n2];
    //mergeArrays(arr1, arr2, n1, n2, arr3);
    sortAndMergeArrays(arr1, arr2, n1, n2, arr3);
 
    cout << "Array after merging" <<endl;
    for (int i=0; i < n1+n2; i++)
        cout << arr3[i] << " ";
    
    printf("\n");

    //vector<int>nums1 {1,2,3,0,0,0};
    //vector<int>nums2 {2,5,6};
    vector<int>nums1 {1,0};
    vector<int>nums2 {2};
    merge2Vector(nums1,1,nums2,1);
    for (int kk : nums1)
        cout<<kk<<" ";
    printf("\n");


    return 0;
}