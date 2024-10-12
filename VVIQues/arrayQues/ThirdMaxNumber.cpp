#include <iostream>
#include <vector>

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
    // result.push_back(nums[size - 1]);

    if (result.size() < 3)
        return max(result[0], result[1]);
    else
        return result[2];
}

/*
Given an integer array a[] of size n, find the highest element of the array.
The array will either be strictly increasing or strictly increasing and then strictly decreasing.
arr = {1 2 3 4 5 } o/p = 5
arr = {1 2 3 4 5 6 5 4 3 2 1} o/p = 6
*/

int findPeakElement(vector<int> &a)
{ // sort(a.begin(), a.end());
    // return a[size-1];

    int size = a.size();
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] > a[mid + 1])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return a[start];
}

int main()
{

    // vector<int> abc {2,2,3,1};
    // vector<int> abc {5,2,2};
    vector<int> abc{1, 1, 1};
    int result = thirdMax(abc);
    cout << "third Max: " << result << endl;

    // vector<int>arr {1,2,3,4,5};
    vector<int> arr{1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    int peakElement = findPeakElement(arr);
    cout << "peak: " << peakElement << endl;

    return 0;
}
