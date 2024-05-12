#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char ch) : data(ch), next(nullptr) {}
};

void addVowelConsonants(Node *&head,Node *&tail,int data){
    if(head==NULL){
         Node *newNode=new Node(data);
         head=newNode;
         tail=newNode;
    }else{
        Node *newNode=new Node(data);
         tail->next=newNode;
         tail=newNode;
    }
}

void printSLL(Node* head){
    while(head != nullptr) {
        cout << head ->data<<" -> ";
        head = head -> next;
    }
    printf("\n");
}

bool isVowel(char data) {
    return( data=='a')|| (data=='e') || (data=='i') || (data=='o') || (data=='u');
}

// function that arrange Vowels and Consonants in SLL
Node* arrangeVowelConsonants(Node* head) {
    //first approach using vector
    vector<char>vow;
    vector<char>cons;
    while ( head != nullptr){
        if(isVowel(head -> data)){
            vow.push_back(head -> data);
        }else{
            cons.push_back(head -> data);
        }
        head = head -> next;
    }

    // Now create new SLL by traversing vectors
    // First Add Vowels and then Consonants in SLL
    Node* vowHead = nullptr;
    Node* vowTail = NULL;
    for(auto ch : vow) {
        addVowelConsonants(vowHead,vowTail,ch);
    }
    for ( auto ch : cons) {
        addVowelConsonants(vowHead,vowTail,ch);
    }

    return vowHead;
}

// 2nd Approach using Two pointer Technique to arrange vowels and consonants
Node* arrangeVowelConsonantsUsingTwoPointer(Node* head) {
    Node *vows = new Node('1');
    Node *v = vows;

    Node *cons = new Node('1');
    Node *c = cons;

    while(head != nullptr){
        if(isVowel(head -> data)){
            v -> next = new Node(head -> data);
            v = v -> next;
        } else {
            c -> next = new Node(head -> data);
            c = c -> next;
        }
        head = head -> next;
    }

    v -> next = cons -> next;
    return vows -> next;
}



int main() {

    // Add characters to SLL 
    //a -> b -> c -> d -> e -> f -> g -> h -> i 
    // a -> b -> a -> b -> d -> e -> e -> d 

    Node* head = nullptr;
    Node* tail = nullptr;
    addVowelConsonants(head,tail,'a');
    addVowelConsonants(head,tail,'b');
    addVowelConsonants(head,tail,'a');
    addVowelConsonants(head,tail,'b');
    addVowelConsonants(head,tail,'d');
    addVowelConsonants(head,tail,'e');
    addVowelConsonants(head,tail,'e');
    addVowelConsonants(head,tail,'d');
    addVowelConsonants(head,tail,'i');
    

    printSLL(head);

    // arrange vowels and consonants
   // head = arrangeVowelConsonants(head);
    head = arrangeVowelConsonantsUsingTwoPointer(head);
    printSLL(head);



    return 0;
}