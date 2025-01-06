#include<iostream>
#include<vector>
#include <algorithm>


using std::cout, std::endl, std::cin, std::vector;


/*
std::rotate is a function in the C++ Standard Library that performs a left rotation on a range of elements. 
It’s part of the `<algorithm>` header and works with any container that provides bidirectional iterators
*/

void rotateVectorElement(vector<int>&num) {
    std::rotate(num.begin(), num.begin() + 2, num.end());
}

//Practical Applications of rotate : Implementing a Circular Buffer

class CircularBuffer
{

private:
    vector<int> buffer;
    size_t head = 0;
    size_t capacity;

public:
    CircularBuffer(size_t size) : buffer(size), capacity(size) {}

    void push(int val)
    {
        buffer[head] = val;
        head = (head + 1) % capacity;
    }

    void rotate()
    {
        std::rotate(buffer.begin(), buffer.begin() + 1, buffer.end());
    }

    void print()
    {
        for (int value : buffer)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

};

int
main()
{

    vector<int> num {1,2,3,4,5};

    cout<<"printing vector before rotation"<<endl;
    for(int i:num)
       cout<<i<<" ";
    cout<<endl;

    rotateVectorElement(num);
    cout<<"printing vector before rotation"<<endl;
    for(int i:num)
       cout<<i<<" ";
    cout<<endl;


    CircularBuffer cb(5);
    for (int i = 1; i <= 7; ++i) {
        cb.push(i);
        cb.print();
    }

}
