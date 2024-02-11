#include<iostream>
using namespace std;

int add(int a, int b)
{
return a+b;
}

int main()
{
int a = 5;

cout <<"sideeffect " <<add(a,a++) << endl;

int x = 1;
    x = x++;
    cout << x << endl;

return 0;
}

