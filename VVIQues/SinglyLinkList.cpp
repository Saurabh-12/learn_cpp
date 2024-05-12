# include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}

};

class SLL {
    private:
     Node *head;

    public :
     SLL(): head(nullptr) {}

     void add(int data) {
        Node *newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
        } else {
            Node * current = head;
            while(current -> next != nullptr) {
                current = current -> next;
            }
            current -> next = newNode;
        }
     }

     void print() {
        Node * current = head;
        while( current != nullptr) {
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << endl;
     }

};

int main () {

    SLL mySLL;

    //Add data
    mySLL.add(10);
    mySLL.add(15);
    mySLL.add(20);

// print data
  mySLL.print();

    return 0;
}