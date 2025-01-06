#include <iostream>
#include <stack>

// Function to insert an element at the bottom of the stack
void insertAtBottom(std::stack<int>& st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }

    // Remove the top element
    int top = st.top();
    st.pop();

    // Recursively call to reach the bottom
    insertAtBottom(st, item);

    // Restore the top element
    st.push(top);
}

// Function to reverse the stack
void reverseStack(std::stack<int>& st) {
    if (st.empty()) {
        return;
    }

    // Remove the top element
    int top = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the removed element at the bottom
    insertAtBottom(st, top);
}

// Function to print the stack (helper function)
void printStack(std::stack<int> st) {
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << "\n";
}

int main() {
    std::stack<int> st;

    // Push elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    std::cout << "Original Stack: ";
    printStack(st);

    // Reverse the stack
    reverseStack(st);

    std::cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
