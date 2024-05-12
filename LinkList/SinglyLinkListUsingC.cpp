# include <stdio.h>
# include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
}* first = NULL;


void addElementInSLL(int arr[], int size){
    int i;
    struct Node *t,*last;

    first = (struct Node *) malloc(sizeof(struct Node));
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for (i = 1; i < size ; i++){
        t = (struct Node *) malloc(sizeof(struct Node));
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void printSLLElement ( struct Node * next){
    while ( next != NULL)
    {
        printf("%d ", next -> data);
        next = next -> next; 
    }
}


int main() {
    printf("Hello Saurabh \n");

    struct Node *temp;
    int A[]={3,5,7,10,25,8,32,2};
    int size = sizeof(A)/sizeof(A[0]);

    addElementInSLL(A,size);

    printSLLElement(first);

    return 0;
}