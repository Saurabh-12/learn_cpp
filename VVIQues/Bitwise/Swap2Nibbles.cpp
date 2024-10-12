# include <iostream>
# include <bitset>

using namespace std;



/*
Given a number n, Your task is to swap the two nibbles and find the resulting number. 

A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. 
For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. 
This byte can be divided into two nibbles: 1001 and 0110.

Example 1:

Input: n = 100
Output: 70
Explanation: 100 in binary is 01100100, two nibbles are (0110) and (0100). I
f we swap the two nibbles, we get 01000110 which is 70 in decimal.

Example 2:

Input: n = 129
Output: 24
Explanation: 129 in binary is 10000001, two nibbles are (1000) and (0001). 
If we swap the two nibbles, we get 00011000 which is 24 in decimal.

*/

int swapNibbles(int n)
{
    // code here
    cout << "Given number is : " << n;
    cout << " Converting Number into Binary : "<<bitset<8> (n)<<endl;
    //doing rightshift 4 times to remove  first half LSB"
    int n1 = n >> 4;
    cout << "First Half : "<<n1;
    cout << " Converting First Half into Binary : "<<bitset<8> (n1)<<endl;
    //doing leftshift 4 times to remove  second half USB"
    int n2 = n << 4;// & 255;
    cout << "Second Half : "<<n2;
    cout << " Converting Second Half into Binary : "<<bitset<8> (n2)<<endl;
    //masking it with 255 to remove the extra bits
    int n3 = n2 & 255;
    cout << "Second Half after masking : "<<n3;
    cout << " Converting Second Half after masking into Binary : "<<bitset<8> (n3)<<endl;
    //Adding the two nibbles
    int result = n1 + n3;
    cout << "Result : "<<result;
    cout << " Converting Result into Binary : "<<bitset<8> (result)<<endl;

    return (n >> 4) + (n << 4 & 255);
}


int main() {

    int n = 100;

    int result = swapNibbles(n);



    return 0;
}