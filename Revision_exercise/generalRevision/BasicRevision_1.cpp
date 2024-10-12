#include <iostream>
#include<string>



using namespace std;

int main () {

    auto age = 0;

    cout <<"Enter Age "<<endl;
    cin >>age;
    cout << "Input for age is : "<<age;
    cout <<endl;

    int number[8];

    number[0] = 1;
    number[7] = 9;

    cout <<number[0]<<number[7]<<endl;

   auto numbers = {1,2,3,4,5,6,7,8};
   auto sum = 0;
   for(auto i :numbers)
       sum+=i;
    cout<<"sum "<<sum<<endl;

    string name1 = "Saurabh ";
    string name2 = "Sharma";
    cout<<name1+name2<<endl;


    return 0;
}