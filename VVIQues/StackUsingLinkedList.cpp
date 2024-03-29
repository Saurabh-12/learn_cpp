# include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *Link;

    Node(int x)
    {
        data = x;
        Link = NULL;
    }
};

class StackUsingLinkedList {
    Node *Top;

    public:
    StackUsingLinkedList() {
        Top = NULL;
    }
    void push(int x) {
        Node *temp = new Node(x);
        if (!temp)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        temp->Link = Top;
        cout << "Pushed element is " << temp->data << endl;
        Top = temp;
    }

    bool isEmpty() {
        return Top == NULL;
    }

int peek() {

    if( ! isEmpty() ) {
        return Top->data;
    } else 
        return 0;
}
    void pop() {
        if(Top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = Top;
        cout << "Popped element is " << temp->data << endl;
        Top = Top->Link;
        delete temp;
    }

    void display() {
        Node *temp = Top;
        while(temp!= NULL) {
            cout << temp->data << " ";
            temp = temp->Link;
        }
        cout << endl;
    }
};


// Driver code
int main () {

    StackUsingLinkedList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    cout << "\nDisplaying Stack " << endl;
    stack.display();

    cout <<"\nPoping 2 elements from stack " << endl;
    stack.pop();
    stack.pop();

    cout << "\nDisplaying Stack Top element " <<stack.peek()<< endl;

    cout << "\nDisplaying Stack " << endl;
    stack.display();
    
    return 0;
}

