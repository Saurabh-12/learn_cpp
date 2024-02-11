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

int main() {
    int n;
    cin >> n;
    cout << "Input number " << n <<" in bits "<< bitset<16>(n) << endl;
    n = reverseBits(n);
    cout << "After Reverse Number : "<<n<<" In Bits "<<bitset<16>(n)<<endl;
    return 0;
}
