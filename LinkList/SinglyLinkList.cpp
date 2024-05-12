# include <iostream>
#include <climits>


using namespace std;

class Node {
 public:
    int data;
    Node * next; 
};

Node* addAtBeginning(Node *head,int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = head;
    return newNode;
}

Node* addAtEnd(Node *head, int data){
    if(head == nullptr) {
        return addAtBeginning(head, data);
    } else {
        Node * current = head;
        while(current -> next != nullptr){
            current = current -> next;
        }
        Node *newNode = new Node();
        newNode -> data = data;
        newNode -> next = nullptr;
        current -> next = newNode;
        return head;
    }
}

int length(Node *head) {
    int count = 0;
    while(head != nullptr) {
        count++;
        head = head -> next;
    }
    return count;
}

Node* addAtPosition(Node *head, int data, int position) {
    if (position == 0) {
        return addAtBeginning(head,data);
    } else {
        Node *current = head;

        for (int i = 1; i <position-1; i++){
            current = current -> next;
        }

        if (current == nullptr){
            cout << "Position is out of bounds" << endl;
        } else {
            Node *temp =  new Node();
            temp -> data = data;
            if (position == 1) {
                temp -> next = head;
                head = temp;
            } else {
                temp -> next = current -> next;
                current -> next = temp;
            }
        }
        return head;
    }
}

Node* deleteAtBeginning(Node* head){
    if (head == nullptr)  {
        cout << "List is empty" << endl;
    } else {
        Node *temp = head;
        head = head -> next;
        delete(temp);
    }
    return head;
}

Node* deleteAtEnd(Node* head){
    if(head == nullptr){
        cout << "List is empty" <<endl;
    } 
    // if only one element
    else if (head -> next == nullptr){
        delete head;
        head = nullptr;
    } else {
        Node* secondLast = head;
        while(secondLast -> next -> next!= nullptr){
            secondLast = secondLast -> next;
        }
        delete(secondLast -> next);
        secondLast -> next = nullptr;
    }
    return head;
}

Node* deleteAtPosition(Node *head, int pos) {
    int count = 0;
    if (pos == 1) {
        return deleteAtBeginning(head);
    } else if (pos == length(head)){
        return deleteAtEnd(head);
    } else if ( pos <= 0 || pos > length(head)){
        cout << "Position is out of bounds" << endl;
        return head;
    } else {
        Node* current = head;
        Node *prev = nullptr;
        for ( int i = 1; i < pos; i++){
            prev = current;
            current = current -> next;
        }
        prev -> next = current -> next;
        delete(current);
        return head;
    }
}

// delete every Kth node from start
// Example : k = 2 then delete 2, 4,6,8..... 
Node* deleteEveryKthNode(Node* head, int k) {
    if ( head == nullptr || head -> next == nullptr){
        return head;
    }
    if ( k== 1) 
       return nullptr;
    int inc = 1;
    Node *temp = head;
    while( temp != nullptr){
        inc++;
        if (inc == k){
            inc = 1;
            temp -> next = temp -> next -> next;
        }
        temp = temp -> next;
    }
    return head;
}

Node* reverseSLL(Node* head){
    if ( head == nullptr || head -> next == nullptr) {
        return head;
    } else {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while(current != nullptr) {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
}

// delete every kth node from end
Node *deleteEveryKthNodeFromEnd(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    // first reverse the list
    head = reverseSLL(head);
    // now delete every kth element from end
    head = deleteEveryKthNode(head,k);
        // first reverse the list
    head = reverseSLL(head);
    return head;
}

// Sum all element in SLL
int sumOfAllElement(Node * head) {
    int sum = 0;
    while (head != nullptr) {
        sum += head ->data;
        head = head -> next;
    }
    return sum;
}

// find the maximum element in SLL
int maxElement(Node *head) {
    int max = INT_MIN;
    while ( head != nullptr) {
        if (head -> data > max){
            max = head -> data;
        }
        head = head -> next;
    }
 return max;
}

// reverse SLL using recusion
Node* reverseSLLRecursive(Node* head) {
    if (head == nullptr || head -> next == nullptr) {
        return head;
    } else {
        Node *newHead = reverseSLLRecursive(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return newHead;
    }
}

// search for an element in SLL
bool find(Node *head, int data) {
    Node *current = head;
    while(current != nullptr) {
        if (current -> data == data){
            return true;
        }
        current = current -> next;
    }
    return false;
}

void display(Node *head) {
    Node * current = head;
    while(current != nullptr) {
        cout << current -> data << " ";
        current = current -> next;
    }
    cout << endl;
}

int main() {
    int A[] = {3, 5, 7, 10, 15};

    // add at beginning
    Node *head = nullptr;
    head = addAtBeginning(head, A[0]);
 
    // Create a Linked List
    for (int i=1; i<sizeof(A)/sizeof(A[0]); i++){
        head = addAtEnd(head, A[i]);
    }

    // Add element at position 4
    head = addAtPosition(head,12,5);

    // Length of SLL
    int size = length(head);
    cout << "length of the SLL is : "<<size<<endl;

    // Display Linked List
    display(head);
    printf("\n");

    // Delete element at beginning
  //  head = deleteAtBeginning(head);
   // display(head);
   // printf("\n");

    // delete element at end
    //head = deleteAtEnd(head);
    //display(head);

    //delete element at position 3
   // head = deleteAtPosition(head,3);
   //head = reverseSLL(head);

   //head = reverseSLLRecursive(head);
   //display(head);

   // search for an element in SLL
   bool found = find(head, 12);
   if (found) {
    cout << "Element 12 found"<<endl;
   } else {
    cout << "Element 12 not found "<<endl;
   }
   printf("\n");

   // sum 
   int sum = sumOfAllElement(head);
   cout << "Sum of All element in SLL is : " << sum <<endl;
   printf("\n");

   // max
   int max = maxElement(head);
   cout << "Max Element in SLL is : " << max << endl;
   printf("\n");

   // delete every 2nd element
   //head = deleteEveryKthNode(head,2);
   head = deleteEveryKthNodeFromEnd(head,2);
   display(head);

    return 0;
}