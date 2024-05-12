# include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_map>

using namespace std;

// Brute force approach O(n^2)
vector<int> twoElementSumInArray(vector<int>&arr, int target){
    int size = arr.size();
    vector<int>result;
    for(int i = 0; i < size; i++){
        for (int j = i+1; j <size; j++){
            if (arr[i]+arr[j] == target){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
    }
    return result;
}

// better approach O(nlogn). sorting take O(nlogn) and two pointers technique take O(n)
vector<int> twoSum(vector<int>& arr, int target) {
    int size = arr.size();
    vector<int> result;

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = size-1;

    while(left < right){
        if(arr[left]+arr[right] == target){
            result.push_back(left);
            result.push_back(right);
            break;
        } else if (arr[left]+arr[right] < target){
            left++;
        } else {
            right--;
        }
    }
    return result;
}

// better approach O(n) without sorting and two pointers technique

vector<int> twoSumUsingMap(vector<int>&arr, int target) {
    int size = arr.size();
    unordered_map<int,int>indices;

    for (int i = 0; i < size; i++){
        int complement = target - arr[i];
        if(indices.find(complement) != indices.end()) {
            //found two numbers that sum to target
            return {indices[complement],i};
        }
        //store the current index of the element
        indices[arr[i]] = i;
    }
    return {};
}

int main () {
    //vector<int> arr {3,2,4,6,8,5,7};
   // int target = 6;
   // vector<int>result = twoElementSumInArray(arr,target);
   vector<int> arr {2,7,11,15,18,19};
   int target = 9;
   //vector<int>result = twoSum(arr,target);
   vector<int> result = twoSumUsingMap(arr,target);

    cout <<"Two indexes having sum "<<target<<" are: ";
    for (int kk : result)
      cout <<kk<<" ";
    cout << endl;


    return 0;
}
