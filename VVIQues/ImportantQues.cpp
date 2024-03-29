#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int countSetBitsInInt(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;  // Right shift n by 1 bit
    }
    return count;
}

int countSetBitsKernighan(int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        count++;
    }
    return count;
}

void printNumberOneToNHavingFirstAndLastBitsSet(int n) {
    int power_2 = 1, num; 
      
    // first number is '1'     
    cout << power_2 << " "; 
      
    while (1)     
    { 
        // obtaining next perfect power of 2 
        power_2 <<= 1; 
          
        // toggling the last bit to convert  
        // it to as set bit 
        num = power_2 ^ 1; 
          
        // if out of range then break; 
        if (n < num) 
            break; 
              
        // display     
        cout << num << " ";     
    }         
}

void printNunmberHaveFirstNLastBitSet (int n)
{
   cout << 1;
    for(int i = 3; i <= n; i++) {
        if (!((i-1) & (i-2))) {
            cout << " " << i;
        }
    }
}

int toggle_first_bit(int n) {
    return n ^ 1;
}

int toggle_last_bit(int n) {
   int r = log2(n); // value of r indicates the count of last bit of n
   int k; // generate a number with log(n) where only the last bit is 1 using the left shift operator
   k = 1 << r;
   n = n ^ k; // toggle the last bit of n by computing n XOR k
   return n;
}

void toggleFirstAndLastBit(int n) {
    if (n ==1) {
        cout << 0;
        return;
    }
    n =  toggle_first_bit(n);
    n = toggle_last_bit(n);

    cout << n <<endl;
}

int main() {

cout<<"kya hai yah"<<endl;
int a = 9; // 1001+
int kk = a & 1 ;
cout<<"kk = "<<kk<<endl;

int mm = a >> 1 ;

cout<<"mm = "<<mm<<endl;

cout<<"countSetBitsInInt(9) = "<<countSetBitsInInt(9)<<endl;

cout << " 2nd Approach " << endl;

cout << "countSetBitsKernighan(7) = " << countSetBitsKernighan(7) << endl;

cout << "Numbers in the range 1 to " << 25 << " having first and last bits set:\n";
printNumberOneToNHavingFirstAndLastBitsSet(25);
cout << endl;

cout << "2nd Approach to print numbers having first and last bits set:\n";
printNunmberHaveFirstNLastBitSet(25);
cout << endl;

cout << "Toggle first and last digit of a number 57 = 24 and  245 = 60" << endl;
toggleFirstAndLastBit(57);
cout << endl;
toggleFirstAndLastBit(245);
cout << endl;
cout << " 1<<7 = " << (1<<7) << endl;
cout << " 212>>7 = " << (212 >>7) << endl;



    return 0;
}
