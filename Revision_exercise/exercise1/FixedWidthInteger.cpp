#include<iostream>
#include<cstdint>

void doSomething(unsigned int x)
{
    // Run some code x times
    std::cout<<" X "<<x<<std::endl;
}
 

int main(int argc, char const *argv[])
{
    /* code */
   //Rule: Avoid int8_t and uint8_t.
   // If you do use them, note that they are often treated like chars.
    int8_t myint = 65;
    std::cout<<myint<<"\n";

    int16_t intValue = 65;
    std::cout<<intValue<<std::endl;

    doSomething(-1);

    return 0;
}
