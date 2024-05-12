# include<iostream>
# include<queue>
# include<stack>


using namespace std;


struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

/*
Traversing a tree means visiting every node in the tree.
Linear data structures like arrays, stacks, queues, and linked list have only one way to read the data
But a hierarchical data structure like a tree can be traversed in different ways.

Preorder traversal(Parent → Left → Right)
   - Visit root node
   - Visit all the nodes in the left subtree
   - Visit all the nodes in the right subtree
display(root->data)
preorder(root->left)
preorder(root->right)

Inorder traversal (Left → Parent → Right)
   - First, visit all the nodes in the left subtree
   - Then the root node
   - Visit all the nodes in the right subtree
inorder(root->left)
display(root->data)
inorder(root->right)

Postorder traversal(Left → Right → Parent)
    - Visit all the nodes in the left subtree
    - Visit all the nodes in the right subtree
    - Visit the root node
postorder(root->left)
postorder(root->right)
display(root->data)

*/

// Building a Binary tree or creating a tree
Node *createTree() {
    Node* temp; 
    int data;
    printf("\nEnter 0 to exit\n");
    printf("\nEnter 1 for new Node\n");
    printf("\nEnter your choice\n");
    scanf("%d",&data);
    if (data == 0){
        return nullptr;
    } else {
        printf("\nEnter root Node data :  ");
        scanf("%d",&data);
        temp = new Node(data);
        printf("\nEnter left child of Node %d ", data);
        temp->left = createTree();
        printf("\nEnter right child of Node %d ", data);
        temp->right = createTree();
        return temp;
    }
}
// Using queue to create a Binary tree 
Node* createTreeUsingQueue() {
    queue<Node*> q;
    Node* p;
    Node* temp;
    Node* root;
    int data;

    cout << "Enter root Node data: " << flush;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p->data << " : " << flush;
        cin >> data;
        if (data!= -1) {
            temp = new Node(data);
            p->left = temp;
            q.push(temp);
        }

       cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> data;
        if (data != -1){
            temp = new Node(data);
            p->right = temp;
            q.emplace(temp);
        }
        
    }
    return root;
}

// traverse PreOrder 
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void iterativePreOrder(Node *root)
{
    stack<Node *> stk;
    while (root != nullptr || !stk.empty())
    {
        if (root != nullptr)
        {
            cout << root->data << ", " << flush;
            stk.emplace(root);
            root = root->left;
        }
        else
        {
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }
    cout << endl;
}

// traverse InOrder
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void iterativeInOrder(Node *root){
    stack<Node*>stk;
    while (root != nullptr ||!stk.empty()){
        if (root != nullptr){
            stk.emplace(root);
            root = root->left;
        }
        else{
            root = stk.top();
            stk.pop();
            cout << root->data << ", " << flush;
            root = root->right;
        }
    }
}

// traverse PostOrder
void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}


int main(){

// create a root node of binary tree
    Node* root = new Node(1);

/* following is the tree after above statement
    1
    / \
    NULL NULL
    */
   root->left = new Node(2);
   root->right = new Node(3);

    /* 2 and 3 become left and right children of 1
       1
      / \
     2   3
    / \ / \
    NULL NULL NULL NULL
    */

   root->left->left = new Node(4);
   root->left->right = new Node(5);

   /* 4 and 5 become left and right children of 2
         1
       /   \
      2     3
     / \    / \
    4   5   NULL NULL
    /   \
    NULL NULL
   */

  root->right->left = new Node(6);
  root->right->right = new Node(7);

  /* 6 and 7 become left and right children of 3
         1
       /   \
      2      3
     / \      / \
    4   5     6  7
    /   \      /   \
    NULL NULL  NULL  NULL
  */
   
    printf("Preorder traversal of binary tree is \n");
    //preOrder(root);
    iterativePreOrder(root);
    printf("\n");

    printf("Inorder traversal ofbinary tree is \n");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal of binary tree is \n");
    postOrder(root);
    printf("\n");

   // Node *rootnew = createTreeUsingQueue();//createTree();
   // printf("Preorder traversal of binary tree is \n");
   // preOrder(rootnew);
   // printf("\n");

   //Generate Tree from preorder and inorder traversal
    int pre[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int in[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    return 0;
}
