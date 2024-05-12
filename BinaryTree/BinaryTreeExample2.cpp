# include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


// create tree using queue
TreeNode* createTree(){
    queue<TreeNode*>q;
    TreeNode* p;
    TreeNode* temp;
    TreeNode* root;
    int data;

    cout << "Enter root node Data: " << flush;
    cin>>data;
    root = new TreeNode(data);
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child of  " << p -> data <<" :  " << flush;
        cin>>data;
        if(data != -1) {
            temp = new TreeNode(data);
            p -> left = temp;
            q.push(temp);
        }
        cout << "Enter right child of  " << p -> data <<" : "<<flush;
        cin >> data;
        if ( data != -1) {
            temp = new TreeNode(data);
            p -> right = temp;
            q.push(temp);
        }
    }

    return root;
}

TreeNode* createTreeWithoutUserInput() {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    root -> left -> left -> left = new TreeNode(8);
    root -> right -> left -> left = new TreeNode(9);
    return root;
}

// count the Node in tree
int countNode(TreeNode* root) {
    if (root) {
        return 1 + countNode(root -> left) + countNode(root -> right);
    } else {
        return 0;
    }
}

// count leaf node of a tree
int countLeafNode(TreeNode* root) {
    if (root) {
       if (root -> left == nullptr && root -> right == nullptr) {
            return 1;
       } else {
           return countLeafNode(root -> left) + countLeafNode(root -> right);
       }
    }
    return 0;
}

// count degree 1 node count 
int countDeg1Node(TreeNode* root) {
    int x;
    int y;
    if (root!= nullptr){
        x = countDeg1Node(root->left);
        y = countDeg1Node(root->right);

        if (root->left != nullptr ^ root->right != nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

// Degree 2 node count
int deg2NodeCount(TreeNode *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg2NodeCount(p->left);
        y = deg2NodeCount(p->right);
        if (p->left && p->right){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
// count degree 1 and degree 2 node count
int countDeg1AndDeg2Node(TreeNode* root) {
    int x;
    int y;
    if (root != nullptr){
        x = countDeg1AndDeg2Node(root ->left);
        y = countDeg1AndDeg2Node(root ->right);
        if (root ->left != nullptr || root ->right != nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

//Sum of all nodes elements
int sumOfAllNode(TreeNode* root) {
    if (root != nullptr) {
        return root -> data + sumOfAllNode(root -> left) + sumOfAllNode(root -> right);
    } else {
        return 0;
    }
}

// Height or depth of a tree
int heightOrDepthOfTree(TreeNode* root) {
    int leftTreeHeight = 0;
    int rightTreeHeight = 0;
    if (root) {
        leftTreeHeight = heightOrDepthOfTree(root -> left);
        rightTreeHeight = heightOrDepthOfTree(root -> right);
        return leftTreeHeight > rightTreeHeight? leftTreeHeight + 1 : rightTreeHeight + 1;
    }
    return 0;
}

// print Tree using preoder traversal
 void preOrder(TreeNode* root) {
    if (root) {
        cout << root -> data << "  ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
 }


 int main() {

    TreeNode* root = createTreeWithoutUserInput();//createTree();
    preOrder(root);
    printf("\n");

    cout<< " Total Nodes in given Tree is : " << countNode(root) <<endl;

    cout<< " Total Leaf Nodes in given Tree is : " << countLeafNode(root) <<endl;

    cout<< " Total Degree 2 Nodes in given Tree is : " << deg2NodeCount(root) <<endl;

    cout<< " Total Degree 1 Nodes in given Tree is : " << countDeg1Node(root) <<endl;

    cout<< " Total Degree 1 and 2 Nodes in given Tree is : " << countDeg1AndDeg2Node(root) <<endl;

    cout<< " Sum of All node for given tree is : " << sumOfAllNode(root) <<endl;

    cout<< " Height of given tree is : " << heightOrDepthOfTree(root) <<endl;

    return 0;
 }