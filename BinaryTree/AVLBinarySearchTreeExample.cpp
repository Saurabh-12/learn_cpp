# include <iostream>

using namespace std;

/*
AVL tree is a self-balancing binary search tree in which each node maintains extra information called a balance factor 
whose value is either -1, 0 or +1.

Balance Factor = (Height of Left Subtree - Height of Right Subtree) 
                  or 
                 (Height of Right Subtree - Height of Left Subtree)

An example of a balanced avl tree is:     1
                                           (33)
                                         /      \
                                      -1(20)     -1(40)
                                       /   \        \
                                     0(11)   1(27)   0(61)
                                              /
                                            0(50)
*/ 

/*
Insertion operation

Step 1 − Create a node
Step 2 − Check if the tree is empty
Step 3 − If the tree is empty, the new node created will become the 
         root node of the AVL Tree.
Step 4 − If the tree is not empty, we perform the Binary Search Tree 
         insertion operation and check the balancing factor of the node 
         in the tree.
Step 5 − Suppose the balancing factor exceeds ±1, we apply suitable 
         rotations on the said node and resume the insertion from Step 4.

*/

// AVL tree node
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int data) {
        this -> data = data;
        left = right = nullptr;
        height = 1;
    }
};

// A utility function to get the height of the tree
int height(AVLNode* node) {
    if (node == nullptr)
       return 0;
    return node -> height;
}

// A utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a: b;
}


int getBalance(AVLNode* node) {
    if (node == nullptr) 
         return 0;
    return height(node -> left) - height(node -> right);
}

// RR rotation 
AVLNode* RotateRight(AVLNode* node) {
    AVLNode* temp = node -> left;
    AVLNode* temp2 = temp -> right;

    // perform rotation 
    temp -> right = node;
    node -> left = temp2;

    // Update heights
    node -> height = max(height(node -> left), height(node -> right)) + 1;
    temp -> height = max(height(temp -> left), height(temp -> right)) + 1;

    return temp;
}

// LL rotation
AVLNode *RotateLeft(AVLNode *node)
{
    AVLNode *temp = node->right;
    AVLNode *temp2 = temp->left;

    // perform rotation
    temp -> left = node;
    node -> right = temp2;

    //Update heights
    node -> height = max(height(node -> left), height(node -> right)) + 1;
    temp -> height = max(height(temp -> left), height(temp -> right)) + 1;

    return temp;
}

// recursive function to insert a new node in the tree
AVLNode* insert(AVLNode* node, int data) {

    if (node == nullptr) {
        return new AVLNode(data);
    }
    else {
        if (data < node -> data) {
            node -> left = insert(node -> left, data);
        }
        else if (data > node -> data) {
            node -> right = insert(node -> right, data);
        }
        else { // Equal keys are not allowed in BST  
            return node;
        }
    }

// Update the height of this ancestor node
    node -> height = 1 + max(height(node -> left), height(node -> right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return RotateRight(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return RotateLeft(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = RotateLeft(node->left);
        return RotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = RotateRight(node->right);
        return RotateLeft(node);
    }

    return node;
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    // Loop down to find the leftmost leaf
    while (current->left != nullptr)
        current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, int key) {
    // STEP 1: Perform standard BST delete
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            AVLNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == nullptr)
        return root;

    // STEP 2: Update height of the current node
    root->height = 1 + std::max(height(root->left), height(root->right));

    // STEP 3: Get the balance factor of this node
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return RotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return RotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = RotateRight(root->right);
        return RotateRight(root);
    }

    return root;
}

// print inorder traversal of the tree
void inorder(AVLNode* node) {
    if (node!= nullptr) {
        inorder(node -> left);
        cout << node -> data << " ";
        inorder(node -> right);
    }
}

// print preorder traversal of the tree
void preorder(AVLNode* node) {
    if (node!= nullptr) {
        cout << node -> data << " ";
        preorder(node -> left);
        preorder(node -> right);
    }
}

int main() {

    AVLNode *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25); 

    cout << "Inorder traversal of the given tree \n";
    inorder(root);
    printf("\n");

    cout << "Preorder traversal of the given tree \n";
    preorder(root);
    printf("\n");

    // delete 25
    cout<<"Delete 25\n";
    root = deleteNode(root, 25);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout << "\n";
      

    return 0;
}