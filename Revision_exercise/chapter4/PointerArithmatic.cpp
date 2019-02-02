#include<iostream>

int main()
{
    int value(7);
    int *intPtr = &value;
    int *intPtr2;

    *intPtr2 = 9;

    std::cout<<"intPtr "<<intPtr<<"  *intPtr "<<*intPtr<<"\n";
    std::cout<<"intPtr2 "<<intPtr2<<"  *intPtr2 "<<*intPtr2<<"\n";

    std::cout << intPtr << '\n';
    std::cout << intPtr+1 << '\n';
    std::cout << intPtr+2 << '\n';
    std::cout << intPtr+3 << '\n';

    char c = 'Q';

    std::cout<<c<<"\n";

    return 0;
}