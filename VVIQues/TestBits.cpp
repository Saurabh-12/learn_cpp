// This C++ program toggles the first and the last bit of a number
#include <iostream>
#include <cmath>
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
int main(){
   int n = 113;
   cout << "input number = 113" << endl;
   if(n == 1){
      cout << "0";
      return 0;
   }
   toggle_first_bit(n);  // function call to toggle first bit
   toggle_last_bit(n); // function call to toggle last bit
   cout << "Number after Toggle First and Last Bits of a Number: "<<n;
   return 0;
}