#include <iostream>

# define MAX 100

using namespace std;

class StackUsingArray {

int top = 0;
int arr[MAX];

public:

StackUsingArray() {
    top = -1;
}

bool push(int x);
int pop();
int peek();
bool isEmpty();

};

bool StackUsingArray::push(int x) {
    if (top >= MAX-1) {
        cout << "Stack overflow" << endl;
        return false;
    } else {
        arr[++top] = x;
        cout << "Push operation " << x << endl;
        return true;
    }
}

int StackUsingArray :: pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return 0;
    } else 
        return arr[top--];
}

int StackUsingArray :: peek() {
    if (top < 0) {
        cout << "Stack underflow" << endl;
        return 0;
    } else
        return arr[top];
}

bool StackUsingArray :: isEmpty() {
    return top < 0;
}


//driver code

int main() {
    StackUsingArray stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    printf("\n Pop operation: ");

    cout << "Pop Operation 1 "<<stack.pop() << endl;
    cout << "Pop Operation 2 "<<stack.pop() << endl;

    printf("\n Peek operation: ");

    cout << "Peek Elements "<<stack.peek() << endl;

    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
    cout<<endl;

    return 0;
}