#include <iostream>
#include <vector>

using namespace std;

// Better approach O(n);

void moveZeroes(vector<int>& nums) {

        if (nums.size() <= 0)
             return;

        int left = 0;
        int right = 0;

     while (right < nums.size()) {
        if (nums[right] != 0) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
}

}

// Brute-force approach O(n^2)

void moveZeroesUsingLoop(vector<int>&nums) {
    int size = nums.size();
    int count = 0;
    for (int i = 0; i < size; i++){
        if (nums[i] != 0){
            nums[count++] = nums[i];
        }
    }

    for (int i = count ; i < size; i++){
        nums[i] = 0;
    }
}



int main() {

    vector<int>arr {0,1,0,3,12};
    for(int kk:arr)
      printf("%d ",kk);
    printf("\n");

    //moveZeroes(arr);
    moveZeroesUsingLoop(arr);

    for(int mm : arr)
       cout<<mm<<" ";
    cout<<endl;

    return 0;
}