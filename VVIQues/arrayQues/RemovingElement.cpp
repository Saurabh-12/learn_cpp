#include <iostream>
# include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
        
       // nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        //return nums.size();
        int left = 0;
        int right = 0;
        
     while (right < nums.size()) {
        if (nums[right] != val) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
        
    return left;
        
    }


int main () {

    vector<int> nums {2,3,3,2};
    int val = 3;

    int size = removeElement(nums,val);

    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    printf("\n");


    return 0;
}