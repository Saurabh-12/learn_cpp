#include<iostream>
#include<vector>

void printStack(const std::vector<int> &stack)
{
    for (const auto &element : stack)
        std::cout << element << " ";

    std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
    std::vector<int> stack;

//Because resizing the vector is expensive, we can tell the vector to allocate 
//a certain amount of capacity up front using the reserve() function
    stack.reserve(5); // Set the capacity to (at least) 5

    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(5);
    printStack(stack);

    stack.push_back(1);
    printStack(stack);
    std::cout <<" Top: " << stack.back()<<"\n"; //back() returns the last element

    stack.pop_back(); // pop_back() back pops an element off the stack
	printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    std::cout<<"                           \n";
    //Vectors may allocate extra capacity
	std::vector<int> v = { 0, 1, 2, 3, 4 };
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';
	
	v.push_back(5); // add another element
	std::cout << "size: " << v.size() << "  cap: " << v.capacity() << '\n';

    return 0;
}