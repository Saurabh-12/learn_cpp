#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//container with max water
int maxWaterArea(vector<int>& height) {
    //two pointer
    int left = 0;
    int right = height.size()-1;
    int maxArea = 0;

    while (left < right)
    {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(currentArea, maxArea);
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

// Find sum of two element to match the given target. if Array is sorted 
vector<int>TwoElementSumToMatchTarget(vector<int>& targetArr, int target) {
    vector<int>result;
    //take 2 pointer
    int left = 0;
    int right = targetArr.size()-1;
    while(left <right) {
        int sum = targetArr[left] + targetArr[right];
        if(sum == target){
            return {left+1, right+1};
        } else if (sum >target){
            right --;
        } else {
            left++;
        }
    }

    return {-1,-1};
}

// find sum of two element to match target , if Array is not sorted 
vector <int>twoElementSum(vector<int> & arr , int target){
    unordered_map<int, int>index;
    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];

        if (index.find(complement) != index.end()){
            return { index[complement], i};
        }
        index[arr[i]] = i;
    }
    return {-1,-1};
}



int main() {

    /*
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    */
   vector<int>arr = {1,8,6,2,5,4,8,3,7};
   cout<<"Max Area: "<<maxWaterArea(arr);
   cout<<endl;

   //Two Sum II — Input Array Is Sorted
   /*
   Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2.
We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3.
We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2.
We return [1, 2].
   */
    vector<int>arr1 = {2,7,11,15};
    vector<int>result = twoElementSum(arr1,9);//TwoElementSumToMatchTarget(arr1,9);
   cout<<"Target Sum index [ "<< result[0] << " , "<< result [1] <<" ]"<<endl;

   return 0;
}