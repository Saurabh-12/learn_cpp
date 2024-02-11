#include<iostream>
#include<cmath>

int getPowerOfNumber(int x, int y) {
    int z = 1;
    while (y > 0) {
        z *= x;
        y--;
    }
    return z;
}

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    // number of door is 100;
    int n = 100;
    cout<<"number of door open after 100 times toggling"<<endl;
    cout << sqrt(n) << endl;

    cout<< "Value of 8^3 = "<<getPowerOfNumber(8,3)<<endl;
    cout <<"power of 2^0 = "<<pow(2,-1)<<endl;

    return 0;
}