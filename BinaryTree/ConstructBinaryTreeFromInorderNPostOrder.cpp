# include<iostream>
#include <unordered_map>
# include<vector>

using namespace std;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, 
                        int post_start, int post_end, unordered_map<int, int>& inorder_map) {

    if (in_start > in_end || post_start > post_end) {
        return nullptr;
    }

    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);

    int root_index = inorder_map[root_val];
    int left_subtree_size = root_index - in_start;

    root->left = buildTreeHelper(inorder, postorder, in_start, root_index - 1, post_start, post_start + left_subtree_size - 1, inorder_map);
    root->right = buildTreeHelper(inorder, postorder, root_index + 1, in_end, post_start + left_subtree_size, post_end - 1, inorder_map);

    return root;
}

TreeNode* buildTree(vector<int>&inorder, vector<int>&postorder) {
    unordered_map<int, int> inorder_map;
    for (int i = 0; i < inorder.size(); ++i) {
        inorder_map[inorder[i]] = i;
    }
  return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inorder_map);
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}



int main () {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    TreeNode* root = buildTree(inorder, postorder);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}