#include <iostream>
#include <bitset>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;
using std::bitset;

int main()
{

    int x = 212;


cout<<"Number x "<< x<<" : " <<bitset<16>(x)<<endl;

int b = x >> 7;

cout<<"Number x after 7 right shift "<<b<< " : " <<bitset<8>(b)<<endl;

int c = 212 << 7;
cout<<"Number x after 7 Left shift "<<c<< " : " <<bitset<16>(c)<<endl;

//int y = ((113<<1)>>1)^1;
cout<<"113: "<<bitset<16>(113)<<endl;
int y = (113<<1);
cout<<"Number 113 after 1 left shift "<<y<< " : " <<bitset<16>(y)<<endl;
int yy = y>>1;
cout<<"Number 113 after 1 right shift "<<yy<< " : " <<bitset<16>(yy)<<endl;
int yyy = yy^1;
cout<<"Number 113 after xor 1 "<<yyy<< " : " <<bitset<16>(yyy)<<endl;

// Toggle first and last bit of a number
cout<<"Number x "<<113<<" : "<< bitset<8>(113)<<" after toggle first and last bit "<<yyy<<" : "<< " : " <<bitset<8>((113>> 1)^1)<<endl;

int z = 9 | (1 <<2);
cout <<"9 "<<z<<endl;

cout <<"15 "<<(15 & (~(1<<2)))<<endl;

cout <<"15 "<<(11 ^(1<<2))<<endl;

cout<<"Toggle First Bit of Number 4 :100 "<<(4 ^1)<<endl;


//count total number of bits in a number
unsigned int num = 10;
int Bitcount = log2(10);
//create number using left sgift
int k = 1 << Bitcount;
cout << "Number of bits in 10 is "<<k<<endl;

cout << "57 >> 4: "<<(57 >>4) << endl;






    return 0;
}