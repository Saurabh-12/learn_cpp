#include<iostream>
#include<string>
using namespace std;

void doPrintName(string name){
std::cout<<"Your Name "<<name<<std::endl;
}

void doStringOperation(string name1, string name2){
    string name3 = name2;
    std::cout<<name3<<std::endl;
    std::cout<<name1<<name2<<std::endl;
    name3 = name1+name2;
    int len = name3.size();
    std::cout<<"name: "<<name3<<std::endl;
    std::cout<<len<<std::endl;
}

int return5(){
    return 5;
}

int add(int x, int y){
    return x+y;
}

int multiply(int p, int q){
    return p*q;
}

int main(){
    string names = "Saurabh";
    std::cout << "Please Enter a Number"<< std::endl;
    int x;
    std::cin >>x;
    std::cout <<" You entered "<<x <<std::endl;
    std::cout<<"Please enter your Name"<<std::endl;
    std::cin>>names;
    doPrintName(names);
    string name1 = "Kumar ", name2 = "Saurabh";
    doStringOperation(name1, name2);
    std::cout<<return5()<<std::endl;

    std::cout << add(4, 5) << std::endl; // within add(), x=4, y=5, so x+y=9
    std::cout << multiply(2, 3) << std::endl; // within multiply(), z=2, w=3, so z*w=6
 
    // We can pass the value of expressions
    std::cout << add(1 + 2, 3 * 4) << std::endl; // within add(), x=3, y=12, so x+y=15
 
    // We can pass the value of variables
    int a = 5;
    std::cout << add(a, a) << std::endl; // evaluates (5 + 5)
 
    std::cout << add(1, multiply(2, 3)) << std::endl; // evaluates 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << std::endl; // evaluates 1 + (2 + 3)

    return 0;
}