#include<iostream>
#include<set>

int main()
{
    std::set<int> myset;

    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);

    std::set<int>::const_iterator itr;  // declare an iterator
    itr = myset.begin(); // assign it to the start of the set

    while (itr != myset.end()) // while it hasn't reach the end
    {
        std::cout << *itr << " "; // print the value of the element it points to
        ++itr; // and iterate to the next element
    }
    
    std::cout<<'\n';

    return 0;
}