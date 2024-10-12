# include<iostream>
# include<vector>
# include<unordered_map>


using namespace std;


/*
LongestSubsequence
Given an integer array a[] of size n, find the length of the longest subsequence
such that the absolute difference between adjacent elements is 1.

Example 1:
Input:
n = 7
a[] = {10, 9, 4, 5, 4, 8, 6}
Output: 
3
Explaination: 
The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, 
where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed.


Example 2:
Input: 
n = 5
a[] = {1, 2, 3, 4, 5}
Output: 
5
Explaination: 
All the elements can be included in the valid subsequence.

*/

int longestSubseq(int n, vector<int> &arr)
{
    // code here
    /*        int count (0);
            for ( int i = 0 ; i < n ; i++) {

                if ( abs(arr[i]- arr[i+1]) == 1){
                    count++;
                }
            }

            return count;*/

    unordered_map<int, int> mp;
    int maximum = 0;
    int b, c;

    for (auto i : arr)
    {
        b = i - 1;
        c = i + 1;
        mp[i] = max(mp[b], mp[c]) + 1;
        maximum = max(maximum, mp[i]);
    }

    return maximum;
}

// recursive solution
int longestSubseqRecur(int n, vector<int> &arr) {
    /*
    int solve(int idx,int prev,vector<int>&a,int n){
        if(idx>=n){
            return 0;
        }
        int not_take=solve(idx+1,prev,a,n);
        int take=0;
        if(prev==-1 || abs(a[idx]-a[prev])==1){
            take=1+solve(idx+1,idx,a,n);
        }
        return max(take,not_take);
        
    }
    int longestSubseq(int n, vector<int> &a) {
        // code here
        return solve(0,-1,a,n);
    }
    */
}

int main() {

    int n = 5;
    vector<int> arr {1, 2, 3, 4, 5};
    cout << longestSubseq(n, arr) << endl;
    return 0;
}
