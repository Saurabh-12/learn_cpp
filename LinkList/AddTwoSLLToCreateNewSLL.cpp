# include <iostream>
# include <cmath>

using namespace std;

struct Node {
    long long int data;
    Node * next;
    Node(int val) : data(val),next(nullptr) {};
};

Node *AddElement(Node* head, int data){
    Node*newNode = new Node(data);
    if(head == nullptr){
        head = newNode;
    } else {
        Node *current = head;
        while(current -> next != nullptr)
            current = current -> next;
        current -> next = newNode;
    }
    return head;
}

Node *reverseSLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    else
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
}

Node *rev(Node *head) {
    Node *cur = head;
    Node *prev = NULL;
    Node *after = NULL;
    while (cur != NULL)
    {
        after = cur->next;
        cur->next = prev;
        prev = cur;
        cur = after;
    }
    return prev;
}

void printSLL(Node* head){
    while (head != nullptr)
    {
        cout << head -> data <<" -> ";
        head = head -> next;
    }
    printf("\n");
}

int lengthSLL(Node* head) {
    int count = 0;
    while( head != nullptr){
        count++;
        head = head -> next;
    }
    return count;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummyHead = new Node(0);
    Node* curr = dummyHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;
        
        curr->next = new Node(sum);
        curr = curr->next;
    }

    Node* result = dummyHead->next;
    delete dummyHead;
    return result;
}

int main () {

    Node* sll1 = nullptr;
    Node* sll2 = nullptr;

//0 1 2 2 9 2 3
//0 0 0 0 0 0 0
    sll1 = AddElement(sll1,0);
    sll1 = AddElement(sll1,1);
    sll1 = AddElement(sll1,2);
    sll1 = AddElement(sll1,2);
    sll1 = AddElement(sll1,9);
    sll1 = AddElement(sll1,2);
    sll1 = AddElement(sll1,3);

    printSLL(sll1);
    printf("Length of SLL 1 : %d",lengthSLL(sll1));
    printf("\n");

//6 4 5 5 2 5 7 4 7 9   for such range we have to use long long int
//0 0 0 0 0 0 0
    sll2 = AddElement(sll2,6);
    sll2 = AddElement(sll2,4);
    sll2 = AddElement(sll2,5);
    sll2 = AddElement(sll2,5);
    sll2 = AddElement(sll2,2);
    sll2 = AddElement(sll2,5);
    sll2 = AddElement(sll2,7);
    sll2 = AddElement(sll2,4);
    sll2 = AddElement(sll2,7);
    sll2 = AddElement(sll2,9);

    printSLL(sll2);
    printf("Length of SLL 2 : %d\n",lengthSLL(sll2));

    /* //Creating number from ssl1
    //first get multiplayer
    long long int multi1 = pow(10,(lengthSLL(sll1)-1)) ;
    long long int num1 = 0;
    while(sll1 != nullptr) {
        num1 += sll1 -> data * multi1;
        multi1 /= 10;
        sll1 = sll1 -> next;
    }
    cout <<"Number from SLL1: "<<num1<<endl;


    //Creating number from ssl2
    //first get multiplayer
    long long int multi2 = pow(10,(lengthSLL(sll2)-1)) ;
    long long int num2 = 0;
    while(sll2 != nullptr) {
        num2 += sll2 -> data * multi2;
        multi2 /= 10;
        sll2 = sll2 -> next;
    }
    cout <<"Number from SLL2: "<<num2<<endl;

    //Adding two numbers
    long long int sum = num1+num2;
    cout << " Sum of num1 and num2 is: "<<sum<<endl;

    // create a SLL using this sum
    Node* sll3 = nullptr;
    if (sum ==0){
        sll3 = AddElement(sll3,0);
    } else {
        while(sum > 0){
        long long int rem = sum%10;
        sll3 =  AddElement(sll3,rem);
        sum /= 10;
        }
    }
    // reverse sll3
    sll3 = reverseSLL(sll3);
    printSLL(sll3);
 */
   
   //reverse both SLL
   sll1 = reverseSLL(sll1);
   sll2 = reverseSLL(sll2);

   //Adding two SLL
   Node* result = addTwoNumbers(sll1, sll2);
   result = reverseSLL(result);
   printSLL(result);



    return 0;
}