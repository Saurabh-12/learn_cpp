#include <iostream>
#include <stack>

using namespace std;

/*
   What is Binary Search Tree?
   A binary search tree (BST) is a node-based binary tree data structure which has the following properties:
     - The value of left node must be smaller than the parent node
     - The value of right node must be greater than the parent node
     - This rule is applied recursively to the left and right subtrees of the root node.
    Example
                        (50)
                     /     \
                   (30)     (70)
                 /    \     /  \
               (20)   (40) (60) (80)
    - if left subtree right node is greater than the root node,
    - then the left subtree is not a BST and as whole tree is not a BST.

    example:
                         (40)
                         /  \
                     (30)     (50)
                     /  \      /  \
                   (25)  (55) (45) (60)

*/

// Advantages of Binary Search Tree :
// - It is efficient in searching, insertion and deletion.

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// recusrive search in Binary Search Tree
TreeNode *recursiveSearch(TreeNode *root, int val)
{
  if (root == nullptr || root->data == val)
  {
    return root;
  }
  else if (val < (root->data))
  {
    return recursiveSearch(root->left, val);
  }
  else
  {
    return recursiveSearch(root->right, val);
  }
}

// iterative search in Binary search Tree(BST)
TreeNode *iterativeSearch(TreeNode *root, int key)
{
  TreeNode *current = root;
  while (current != nullptr)
  {
    if (current->data == key)
    {
      return current;
    }
    else if (key < current->data)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  return current;
}

// recursive insertion in Binary Search Tree
TreeNode *insertNode(TreeNode *root, int val)
{
  if (root == nullptr)
  {
    return new TreeNode(val);
  }
  if (val < root->data)
  {
    root->left = insertNode(root->left, val);
  }
  else
  {
    root->right = insertNode(root->right, val);
  }
  return root;
}
// iterative insertion in Binary Search Tree
TreeNode *insertNodeIterative(TreeNode *root, int val)
{
  TreeNode *current = root;
  TreeNode *parent = nullptr;
  while (current != nullptr)
  {
    parent = current;
    if (val < current->data)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }

  TreeNode *newNode = new TreeNode(val);
  if (val < parent->data)
  {
    parent->left = newNode;
  }
  else
  {
    parent->right = newNode;
  }
  return root;
}

// inoder traversal of BST
void inorderTraversal(TreeNode *root)
{
  if (root)
  {
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
  }
}

// Delete a node in BST
/*
  In a binary search tree, we must delete a node from the tree by keeping in mind that the property of BST is not violated.
  To delete a node from BST, there are three possible situations occur -
     - The node to be deleted is the leaf node, or,
     - The node to be deleted has only one child, and,
     - The node to be deleted has two children
*/
TreeNode *findInorderSuccessor(TreeNode *cur) /*To find the inorder successor*/
{
  while (cur->left != NULL)
  {
    cur = cur->left;
  }
  return cur;
}
void searchTree(TreeNode *&cur, int key, TreeNode *&parent)
{
  while (cur != nullptr && cur->data != key)
  {
    parent = cur;
    if (key < cur->data)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

TreeNode *deleteNode(TreeNode *root, int key)
{
  TreeNode *parent = nullptr;
  TreeNode *cur = root;
  searchTree(cur, key, parent);

  if (cur == nullptr)
  { // if key not found
    return root;
  }

  // key found in tree and has no childerent i.e. leaf nodes
  if (cur->left == nullptr && cur->right == nullptr)
  {
    if (cur != root)
    {
      if (parent->left == cur)
        parent->left = NULL;
      else
        parent->right = NULL;
    }
    else
      root = NULL;
    delete (cur);
  }
  // Key found in tree and has two children
  else if (cur->left && cur->right)
  {
    TreeNode *succ = findInorderSuccessor(cur->right);
    int val = succ->data;
    deleteNode(root, succ->data);
    cur->data = val;
  }
  else
  { // key found and has one child
    TreeNode *child = (cur->left) ? cur->left : cur->right;
    if (cur != root)
    {
      if (cur == parent->left)
        parent->left = child;
      else
        parent->right = child;
    }
    else
      root = child;
    delete (cur);
  }
  return root;
}

// create a BST using preorder traversal
TreeNode* createBSTFromPreOrder(int *arr, int size){
   // create root node
   int i = 0;
   TreeNode* root = new TreeNode(arr[i++]);

   //iterative step
   TreeNode* temp;
   TreeNode* head = root;
   stack<TreeNode*>stk;

   while(i <size) {
    // Left child case
    if (arr[i] < head -> data){
       temp = new TreeNode(arr[i++]);
       head -> left = temp;
       stk.push(head);
       head = temp;
    } else {
      // Right child case
       if (arr[i] > head->data && arr[i] < stk.empty() ? 32767 : stk.top()->data){
         temp = new TreeNode(arr[i++]);
         head -> right = temp;
         head = temp;
       } else { // 
         head = stk.top();
         stk.pop();
       }
    }
   }
   return root;
}

int main()
{

  TreeNode *root = new TreeNode(50);
  root = insertNodeIterative(root, 30);
  root = insertNodeIterative(root, 20);
  root = insertNodeIterative(root, 40);
  root = insertNode(root, 60);
  root = insertNode(root, 55);
  root = insertNode(root, 45);

  inorderTraversal(root);
  printf("\n");

  int key = 75;
  TreeNode *searchTree = iterativeSearch(root, key);
  if (searchTree)
  {
    cout << "Key " << searchTree->data << " found \n";
  }
  else
  {
    printf("Key %d not found\n", key);
  }

  // delete node 55
  root = deleteNode(root, 55);
  inorderTraversal(root);
  printf("\n");

  // BST from Preorder traversal
  cout << "BST from Preorder: " << flush;
  int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
  int n = sizeof(pre) / sizeof(pre[0]);
  for( auto k : pre)
    cout<<k<<" ";
  printf("\n");
  TreeNode* tree = createBSTFromPreOrder(pre,n);
  // print tree inorder
  cout<<"Printing tree inOrder after creating it from PreOder"<<endl;
  inorderTraversal(tree);
  printf("\n");

  return 0;
}