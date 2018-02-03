#include <iostream>

int readNumber(){
    std::cout << "Enter a number."<<std::endl;
    int x;
    std::cin >>x;
    return x;
}
void writeNumber(int y){
    std::cout << " The answer is "<<y<<std::endl;
}