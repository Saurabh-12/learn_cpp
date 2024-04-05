#include <iostream>
#include <algorithm>

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

    return 0;
}