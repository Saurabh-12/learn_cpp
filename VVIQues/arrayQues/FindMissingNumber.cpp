# include <iostream>
# include <vector>
# include <algorithm>
# include <set>


using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int size = nums.size();

    set<int> distinctNums(nums.begin(), nums.end());

    vector<int> result;

    for (int i = 1; i < size + 1; i++)
    {
        if (!distinctNums.count(i))
            result.push_back(i);
    }

    return result;
}

vector<int> findMissingNumbers(vector<int> &nums)
{
    vector<int> result;

    // Mark visited elements by negating the value at the corresponding index
    for (int i = 0; i < nums.size(); ++i)
    {
        int index = std::abs(nums[i]) - 1;
        nums[index] = -std::abs(nums[index]);
    }

    // Find indices with positive values (missing numbers)
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > 0)
        {
            result.push_back(i + 1);
        }
    }
    return result;
}

int main() {

    vector<int> nums {4,3,2,7,8,2,3,1};
    vector<int> result = findMissingNumbers(nums);
    for ( int kk : result)
        cout<<kk<<" ";
    printf("\n");




    return 0;
}