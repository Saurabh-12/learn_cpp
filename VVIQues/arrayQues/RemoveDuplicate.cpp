# include <iostream>
# include<algorithm>
# include<unordered_map>
# include<unordered_set>

using namespace std;

//sort Elements in array then compare adjascent elements
int removeDuplicates(int *arr, int size) {
    //sort(arr,arr+size);
    if (size <=1) return size;
    int j = 0;
    for ( int i = 0; i < size; i++) {
        if (arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
    return j;
}

// Without sorting using unordered_map
int removeDuplicatesWithoutSorting(int *arr, int size) {
    if (size <=1) return size;
    int j = 0;
    unordered_map<int,int> myMap;
    for (int i = 0; i < size; i++) {
        if (myMap.find(arr[i]) == myMap.end()) {
            myMap[arr[i]] = 1;
            arr[j++] = arr[i];
        }
    }
    return j;
}

// Without sorting using Set
int removeDuplicatesWithoutSortingUsingSet(int *arr, int size) {
    if (size <=1) return size;
    int j = 0;
    unordered_set<int>myset;
    for (int i = 0; i <size; i++) {
        if (myset.find(arr[i]) == myset.end()) {
            myset.insert(arr[i]);
            arr[j++] = arr[i];
        }
    }
    return j;
}

// count duplicates element in array
// first sort thec array then count the number of duplicates element
int countDuplicates(int *arr, int size) {
    if (size <=1) return size;

    //sort(arr,arr+size);

    int count = 0;
    for(int i = 0; i < size-1; i++) {
        if(arr[i] == arr[i+1])
           count++;
    }

    return count;
}

unordered_map<int,int>countDuplicateswithMap(int *arr, int size) {
    //if (size <= 1) return;
    unordered_map<int,int>myMap;
    for (int i = 0; i <size; i++) {
        if(arr[i] == arr[i+1])
           myMap[arr[i]]++;
    }

    return myMap;
}






int main () {

    int arr[] {1,3,4,4,3,3,2,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+size);
    for(auto i :arr) cout<<i<<" ";
    cout<<endl;

    // removing duplicates
    //int newSize = removeDuplicatesWithoutSortingUsingSet(arr,size);
    //for(int i = 0 ; i< newSize; i++) cout<<arr[i]<<" ";

    int count = countDuplicates(arr,size);
    cout << "the count of duplicates is: "<<count<<endl;
    cout<<endl;

    unordered_map<int,int> myMapcount = countDuplicateswithMap(arr,size);
    for(auto i : myMapcount) cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;

}