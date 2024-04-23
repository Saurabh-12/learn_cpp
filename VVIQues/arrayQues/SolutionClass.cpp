# include<iostream>
# include<vector>
# include<algorithm>

using namespace std;

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        // Your code goes here;
        int count = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int>countArr;
        for (int i = 0; i < q ; i++) {
            int search = a[query[i]];
            
            for (int j = 0; j < n ; j++) {
                
                if (b [j] <= search)
                   count++;
            }
            
            countArr.push_back(count);
            count = 0;
        }
        
        return countArr;
    }

        int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        for(int kk :arr) {
            cout<<kk<<" ";
        }
        printf("\n");
        int max = 0;
        
        for(int i = 0; i < k ; i++) {
            arr.pop_back();
        }

        for(int kk :arr) {
            cout<<kk<<" ";
        }
        printf("\n");

        max = abs(arr[arr.size()-1]-arr[0]);
        
        return max;
    }

    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        int count = 0;
        int j = 0;
        
        for (int i = 1 ; i < n-1 ; i++)
        {
            int val = i * arr[i];
              if( val == 0)
                 continue;
                 
                 j= i+1;
                 
                while(j < n) {
                   if (val > j * arr[j])
                     count++;
                   j++;
                }
        }
        
        return (count);
    }
};


int main () {
/*
n = 3
a[] = {4,1,2}
b[] = {1,7,3}
q = 2
query[] = {0,1}
*/

int n = 4;
vector<int>a {1,1,5,5};
vector<int>b {0,1,2,3};
int q = 4;
vector<int>query {0,1,2,3};
vector<int>result;

Solution obj;
result = obj.countElements(a, b, n, query,q);

for (auto i : result)
   cout<<i<<" "<<endl;

vector<int>arr2 {7,5,9,7,6,4,6,3,10,4};
int arr2Size = 10;
int arr2k = 23;
cout << " int maxDiff : "<<obj.minimizeDifference(arr2Size,arr2k,arr2)<<endl;

//count pair example
vector<int>arr3 {};
int n = ;



    return 0;
}