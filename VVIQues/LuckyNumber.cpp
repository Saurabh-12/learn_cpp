#include<iostream>

using namespace std;

bool isLuckyNumber(int n) {
    bool arr[10];

    for (int i = 0; i < 10 ; i++)
    {
        arr[i] = false;
    }


    while (n>0)
    {
        int last_digit = n % 10;
        if (arr[last_digit])
           return false;
        arr[last_digit] = true;
        n = n / 10;
    }
    return true;
}

/* Returns 1 if n is a lucky no.
otherwise returns 0*/
bool isLucky(int n)
{
    static int counter = 2;
 
    if (counter > n)
        return 1;
    if (n % counter == 0)
        return 0;
 
    /*calculate next position of input no.
      Variable "next_position" is just for
    readability of the program we can
    remove it and update in "n" only */
    int next_position = n - (n / counter);
 
    counter++;
    return isLucky(next_position);
}

// Driver program to test above function.
int main()
{
    int arr[] = {1291, 897, 4566, 1232, 80, 700};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    for (int i=0; i<n; i++)
        isLuckyNumber(arr[i])? cout << arr[i] << " is Lucky \n":
                         cout << arr[i] << " is not Lucky \n";

    
   int x = 13;
 
    // Function call
    if (isLucky(x))
        cout << x << " is a lucky no."<<std::endl;
    else
        cout << x << " is not a lucky no."<<endl;

    return 0;
}