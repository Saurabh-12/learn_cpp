#include <iostream>
#include<string>

using namespace std;

// Example of a function pointer
void print(int x); // Function prototype
void (*f)(int);   // Function pointer declaration

template <typename T>
T addition(T a, T b);

template <typename T>
T (*fAdd)(T, T);

void func(char b, void (*fp)(float), int i);
void func1(float f);

template <typename T, typename U>
T add(T a, U b) {
    return a + b;
}

template <typename T, typename U>
T subs(T a, U b) {
    return a - b;
}

template <typename T, typename U>
T div(T a, U b) {
    return a / b;
}

template <typename T, typename U>
T mul(T a, U b) {
    return a * b;
}

template <typename T, typename U>
T (*fArray[4])(T, U) = {add, subs, mul, div};

int main()
{

    f = print; // Assign the function print to the function pointer f
    f(10);     // Call the function using the function pointer

    // printing the address of the main function
    printf("The address of main function is %p\n", main);
    // printing the address of the print function
    printf("The address of print function is %p\n", print);

    // function pointer to a template function
    fAdd<int> = addition<int>;
    cout << "Addition of 10 and 20 " << fAdd<int>(10, 20) << endl;

    fAdd<double> = addition<double>;
    cout << "Addition of 10.1 and 20.2 " << fAdd<double>(10.1, 20.2) << endl;

    fAdd<char> = addition<char>;
  cout << "Addition of '#' and '$' gives character = " << fAdd<char>('#', '$') << endl;

  // Passing a function's address as a argument to other function
  func('a', func1, 10);
  // Pass a pointer containing function's address as an argument to other function
  void (*p)(float) = func1;
  func('b', p, 20);

  // Arrays of function pointers
  float (*fArray[4])(float, int) = {add, subs, mul, div};

  int i, b;
  float a;
  printf("Enter the two number a and b\n");
  scanf("%f %d", &a, &b);

  string operation[] = {"Addition", "Substraction", "Multiplication", "Division"};

  for (i = 0; i < 4; i++) {
    //printf("%p:  %f\n", operation[i], (*fArray[i])(a, b));
    cout << operation[i] << " of " << a << " and " << b << " is " << (*fArray[i])(a, b) << endl;
  }

  return 0;
}


void print(int x) {
    cout << x << endl;
}

template <typename T>
T addition(T a, T b) {
    return a + b;
}

void func(char b, void (*fp)(float), int i) {
    printf("func called from main() \n");
    printf("The value of char is %c\n", b);
    printf("The value of int is %d\n", i);
    //fp(8.5);
    (*fp)(9.5);//calling the func1 indirectly using pointer

}

void func1(float f) {
    printf("func1 called from func() \n");
    printf("The value of float is %.3f\n", f);
}