# include <iostream>
# include <vector>
# include <set>
# include <algorithm>

using namespace std;

// Brute force approach O(n^2)

bool containDuplicate(vector<int>& nums) {
    int size = nums.size();
    int isDuplicate (false);
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++) {
            if (nums[i] == nums[j])
                isDuplicate = true;
        }
    }
    return isDuplicate;
}

// Better approach O(n)
bool containDuplicates(vector<int>& nums) {
    int size = nums.size();
    set<int> mySet(nums.begin(), nums.end());
    return mySet.size() < size;
}

// Better approach O(nlogn)
bool checkDuplicates(vector<int>& nums){
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < size; i ++){
        if (nums[i] == nums[i-1])
            return true;
    }
    return false;
}


int main() {
    
    vector<int> num {8,3,9,2,5,6,9,7,2,1,4};
    bool result = checkDuplicates(num);
    cout << "Duplicate: "<<result<<endl;

    return 0;
}