#include<iostream>
using namespace std;

int divideInt(int a, int b);

int main()
{
int x = 5, y = 2;
cout << divideInt(x,y);

x = 3, y = 0;
cout<< divideInt(x,y);

return 0;
}

int divideInt(int a, int b)
{

return a/b;

}


