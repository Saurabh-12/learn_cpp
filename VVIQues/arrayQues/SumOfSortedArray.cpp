# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

// sorting take nlog n time and squre takes n, So overall time complexity is O(nlogn)
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;

    for (int i = 0; i < nums.size() ; i++){
        nums[i] = nums[i]*nums[i];
    }

    sort(nums.begin(), nums.end());

    return nums;
}

// Using two pointer technique, T.C. O(n);

vector <int> sortedArraySqure(vector<int>& nums){
        int n = nums.size();
        vector<int>square;
        int p1 = 0;
        int p2 = n-1;

        while( p1 <= p2){
            if(abs(nums[p1]) > abs(nums[p2])){
                square.push_back(nums[p1] * nums[p1]);
                p1++;
            } else {
                square.push_back(nums[p2] * nums[p2]);
                p2--;
            }
        }


/*         for(int i = 0;i < n ; i++){
            if(abs(nums[p1]) > abs(nums[p2])){
               square.push_back(nums[p1] * nums[p1]);
               //square.insert(square.begin()+i, nums[p1] * nums[p1]);
                p1++;
            } else {
                square.push_back(nums[p2] * nums[p2]);
                //square.insert(square.begin()+i, nums[p1] * nums[p1]);
                p2--;
            }
        } */
        return square;
}


int main () {

    vector<int> arr {-4,-1,0,3,10};

//print array
for(int kk:arr)
{
    printf("%d ",kk);
}
printf("\n");

vector<int> result = sortedArraySqure(arr); //sortedSquares(arr);

//print array
for(int kk:result)
{
    printf("%d ",kk);
}
printf("\n");



    return 0;
}