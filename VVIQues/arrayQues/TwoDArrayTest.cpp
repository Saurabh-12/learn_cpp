#include<iostream>
#include<vector>
#include<climits>


using namespace std;

    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int mini = INT_MAX;
        int count = 0;
        int ans  = 0;
        
        for (int i = 0; i < n ; i ++) {
            count = 0;
            
            for (int j = 0 ; j < m ; j++) {
                if(a[i][j]) 
                  count++;
            }
            
            ans = count < mini ? i :ans;
            mini = min(mini,count);
        }
        
        return ans+1;
        
    }



int main () {

    int min = INT_MAX;

    printf("INT_MAX = %d\n", INT_MAX);

    int n = 4,m = 4;
    vector<vector<int>> a { {1, 1, 1, 1},{1, 1, 0, 0}, {0, 0, 1, 1},{1, 1, 1, 1} };

    int ans = minRow(n,m,a);

    cout <<"ans : "<<ans<<endl;




    return 0;
}