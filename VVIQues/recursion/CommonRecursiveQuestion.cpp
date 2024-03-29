#include<iostream>
#include<stdio.h>


//find the HCF of two numbers using Euclid's algorithm
int hcf(int a, int b) {
    if (b == 0)
        return a;
    return hcf(b, a % b);
}

// find the prime factors of a number
void primeFactors(int n) {
    int i = 2;

    if (n == 1) 
       return;
    while (n % i != 0)
         i++;
    printf("%d ", i);
    primeFactors(n / i);
}

// power of a number using recursion
int power(int n, int p) {
    if (p == 0)
        return 1;
    return n * power(n, p - 1);
}

// improvement of power function
int power1(int m, int n)
{
    if (n == 0)
        return 1;
    
    if (n % 2 == 0)
        return power1(m * m, n / 2);
    
    return m * power1(m * m, (n - 1) / 2);
}

// fibonacci series using recursion
int fibonacci(int n) {
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fun(int n) {

    int x = 1, k;

    if (n == 1)
        return x;

    for (k = 1; k < n; ++k)

        x = x + fun(k) * fun(n - k);

    return x;
}

void count(int n)
{
    static int d = 1;

    printf("%d", n);

    printf("%d", d);

    d++;

    if (n > 1)
        count(n - 1);

    printf("%d", d);
}

int main() 
{

    printf("%d \n", hcf(12, 26));

    std::cout<<"prime factors of a number 45"<<std::endl;
    primeFactors(45);
    std::cout<<std::endl;

    std::cout<<"2^5 = "<<power(2, 5)<<std::endl;
    std::cout<<"2^8 = "<<power1(2, 8)<<std::endl;

    std::cout<<"func(5) "<<fun(5)<<std::endl;

    std::cout<<"count(3)"<<std::endl;
    count(3);
    return 0;
}