# include <iostream>
# include <cmath>
# include <bitset>

# define INT_SIZE sizeof(int) * 8;
using std::cout; 
using std::cin;
using std::endl;
using std::bitset;

int reverseBits(int n) {
    int reverse = 0;

    while (n > 0) {
        reverse <<= 1;
        reverse |= n & 1;
        n >>= 1;
    }
    return reverse;
}

void checkNumberPowerOfTwo(int num) {
    if((num & (num-1)) == 0)
    cout << num << " is a power of 2" << endl;
  else
    cout << num << " is not a power of 2" << endl;
}

void checkNumberPowerOf2(int num) {
    if ( num == 1 || (num ^ 1) == (num + 1))
        cout << num << " is a power of 2" << endl;
    else
        cout << num << " is not a power of 2" << endl;
}

int checkAllBitIsSet(int num)
{
    while (num)
    {
        if((num & 1) == 0)
          return 0; // LSB is 0 retun false
        num = num >> 1; // Right shift to check the next bit
    }
    return 1; // If all bits are 1, return true 
}

bool isAllBitSet(int num) {
    int r = 0;
    while (num)
    {
        r = num % 2 ;
          if ( r == 0)
            return false;
        num = num/2;
    }
    return true;
}

void printNumberHaveAllSetBit(int num) {
    for(int i = 1; i<num;i++)
    {
        if(isAllBitSet(i))
           cout<<i<<" has all set bits" <<bitset<8>(i)<<endl;
       //if (checkAllBitIsSet(i))
       //    cout << i << " has all set bits" << bitset<8>(i) << endl;
    }
}

int main() {
    int n;
   // cin >> n;
    //cout << "Input number " << n <<" in bits "<< bitset<16>(n) << endl;
    //n = reverseBits(n);
    //cout << "After Reverse Number : "<<n<<" In Bits "<<bitset<16>(n)<<endl;

    checkNumberPowerOfTwo(1024);
    cout << "My Method "<< endl;
    checkNumberPowerOf2(1024);

    cout<<"All set bits Number from 1 to 50"<<endl;
    printNumberHaveAllSetBit(100);
    //cout<<" 4 kaa ^ "<<~(4^4)<<endl;


    return 0;
}
