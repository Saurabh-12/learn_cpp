# include <iostream>
# include <vector>
# include <algorithm>


using namespace std;


/*
Given an array of integers of length n and an integer k, find all the unique combinations in array
where the sum of the combination is equal to k. Each number can only be used once in a combination
*/

void findCombinations(vector<int>& arr, int size, int k, vector<int>& current, int start, vector<vector<int>>& result) {
    if (k == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < size; ++i) {
        if (k - arr[i] < 0) {
            continue;
        }
        current.push_back(arr[i]);
        findCombinations(arr, size,k - arr[i], current, i + 1, result);
        current.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>& arr, int size, int k) {
    vector<vector<int>> result;
    vector<int> current;

    sort(arr.begin(), arr.end());
    findCombinations(arr, size, k, current, 0, result);
    return result;
}

int main() {

    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int k = 8;
    int size = arr.size();

   // int n = 6, k1 = 35;
    //vector<int> arr1 = { 5, 10, 15, 20, 25, 30 };

    int n = 5, k1 = 7;
    vector<int> arr1 =  { 1, 2, 3, 3, 5 };

    vector<vector<int>> result = combinationSum(arr1, n, k1);

    cout << "Unique combinations with sum " << k << " are:" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }


    return 0;
}