// This C++ program toggles the first and the last bit of a number
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;
// this function flips the last bit of the number
// it uses the concept that a log(n) bits are used in the binary expansion of a number n
void toggle_last_bit(int& n){
   int r = log2(n); // value of r indicates the count of last bit of n
   int k; // generate a number with log(n) where only the last bit is 1 using the left shift operator
   k = 1 << r;
   n = n ^ k; // toggle the last bit of n by computing n XOR k
}

// this function flips the first bit of the number by computing n XOR 1
void toggle_first_bit(int& n){
   n = n ^ 1;
}

int countBits(int num) {
   int count = 0;
   while (num)
   {
      num = num / 2;
      count++;
   }
   return count;
}


int countSetBit(int num)
{
   int count = 0;
   while (num)
   {
      num &= num-1;
      count++;
   }
   return count;
}

void toggleLastBit(int& num) {
   num = num ^ ( 1 << (countBits(num)-1));
}

//check at given position bit is set or unset in a number
bool checkAtGivenPositionBitSrtOrUnset(const int num, const int pos) {
     int newNum = num >> (pos-1);
     return (newNum & 1 == 1 ? 1:0 );
}

long int convertDecimalToBinary(int num)
{
   long int a = 1, bin =0, rem;
   while(num > 0)
   {
      rem = num %2;
      bin = bin + rem *a;
      num = num /2;
      a = a *10;
   }
   return bin;
}

int main(){
   int n = 212;
   cout << "input number = 212 " << bitset<16>(212)<<endl;

   toggle_first_bit(n);  // function call to toggle first bit
   toggleLastBit(n); // function call to toggle last bit

   cout << "Number after Toggle First and Last Bits: "<<n<<" "<<bitset<16>(n)<<endl;

   cout << "set bit count of 3 "<<countSetBit(3)<<endl;

   cout << "count no of bits in 212 "<<countBits(212)<<endl;

   cout << "Check bit is set or not on 5th position for number 57 "<<" binary of 57 "<<bitset<16>(57)<<endl;
   
   if(checkAtGivenPositionBitSrtOrUnset(57,5))
       cout << "5th position for number 57 is set"<<endl;
   else 
     cout <<"5th position for number 57 is not set"<<endl;

   cout << "convert 212 into binary : "<<convertDecimalToBinary(212)<<endl;

   return 0;
}