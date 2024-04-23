# include <iostream>
# include <vector>

using namespace std;

int thirdMax(vector<int> &nums)
{
    int size = nums.size();
    vector<int> result;
    if (size <= 0)
        return 0;
    if (size >= 1 && size < 3)
        return nums[size - 1];

    for (int i = 0; i < size; i++)
    {
        if (nums[i] != nums[i + 1])
            result.push_back(nums[i]);
    }
    //result.push_back(nums[size - 1]);

    if (result.size() < 3)
        return max(result[0], result[1]);
    else
        return result[2];
}

int main () {

    //vector<int> abc {2,2,3,1};
    //vector<int> abc {5,2,2};
    vector<int> abc {1,1,1};
    int result = thirdMax(abc);
    cout<<"third Max: "<<result<<endl;


    return 0;
}