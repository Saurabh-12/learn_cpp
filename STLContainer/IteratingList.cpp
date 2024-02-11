#include<iostream>
#include<list>


int main()
{
    std::list<int> mList;

    for(int i = 0; i < 6; i++)
    {
        mList.push_back(i);
    }
    
    std::list<int> ::const_iterator itr;  //// declare an iterator
    itr = mList.begin(); // assign it to the start of the list

    while(itr != mList.end())   //// while it hasn't reach the end
    {
      std::cout<<*itr<<" " ;// print the value of the element it points to
      itr++;  // and iterate to the next element
    }
    
    std::cout << '\n';

    return 0;
}