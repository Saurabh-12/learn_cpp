# include <iostream>
# include <vector>
# include <algorithm>


using namespace std;

int heightChecker(vector<int> &heights)
{
    int count = 0;
    int size = heights.size();
    vector<int> result;

    for (int kk : heights)
        result.push_back(kk);
    sort(heights.begin(), heights.end());

    for (int i = 0; i < size; i++){
        if (heights[i] != result[i])
            count++;
    }

    return count;
}

int main() {

    vector<int> height {1,1,4,2,1,3};

    int result = heightChecker(height);
    cout <<"Wrong Heights: "<<result<<endl;

    return 0;
}