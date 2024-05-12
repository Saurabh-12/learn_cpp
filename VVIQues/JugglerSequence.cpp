#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

vector<long long> jugglerSequence(long long n)
{
    vector<long long> result;
    while (n != 1)
    {
        if (n % 2 == 0) {
            n = pow(n, 0.5);
        } else {
            n = pow(n, 1.5);
        }
     result.push_back(n);
    }
    //result.push_back(1);
    return result;
}


vector<long long> jugglerSequence2(long long n) {
    vector<long long>result {n};
    int i = 0;
    while(result.back()!= 1) {
        if (result[i]% 2 == 0) {
            result.push_back(sqrt(result[i]));
        } else {
            result.push_back(result[i] *sqrt(result[i]) );
        }
        i++;
    }
    return result;
}

vector<long long> jugglerSequence3(long long n) {
    vector<long long>ans;
    ans.push_back(n);

    while(n != 1) {
        if ( n % 2 == 0)
            n = sqrt(n);
        else
         n = sqrt(n) * sqrt(n)* sqrt(n);
      ans.push_back(n);
    }
    return ans;
}

int main()
{
    int num = 9;
    vector<long long> result = jugglerSequence(num);
    for(auto i : result)
       cout <<i<<" ";
    cout<<endl;

    return 0;
}