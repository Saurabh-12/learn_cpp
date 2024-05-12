#include <iostream>

using namespace std;

bool divisorGame(int n)
{
    return n % 2 == 0 ? true : false;
}


int main () {
    int n = 1000000003;
    cout << divisorGame(n);
    printf("\n");


    return 0;
}