# include <iostream>
# include <cmath>

using namespace std;
/*
Implement pow(x, n) % M.
In other words, for a given value of x, n, and M, find  (xn) % M.
example :
Input:
x = 2, n = 6, m = 10
Output:
4
Explanation:
26 = 64. 64 % 10 = 4.
*/

long long int PowMod(long long int x, long long int n, long long int M)
{
    // Code here
    if (n == 0)
        return 1;
    if (n == 1)
        return x % M;

    long long temp = PowMod(x, n / 2, M);
    
    temp = (temp * temp) % M;

    if (n % 2 == 0)
        return temp;
    else
        return (temp * x) % M;
}

int main () {

    int result = pow(10,3);
    cout << result<<endl;   


    return 0;
}