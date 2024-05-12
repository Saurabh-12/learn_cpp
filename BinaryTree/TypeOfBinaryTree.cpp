# include <iostream>


using namespace std;


/*
Binary Tree  have children {0,1,2}
The maximum number of nodes on any level i is 2^i where i >= 0

The minimum number of nodes possible at height h is n =  h+1

The maximum number of nodes podsible at height h is n =  2^h+1 - 1

The minimum height of a binary trree having n nodes is h = log2(n+1) - 1
The maximum height of a binary trree having n nodes is h = n-1

If the number of nodes is minimum, then the height of the tree would be maximum. 
Conversely, if the number of nodes is maximum, then the height of the tree would be minimum.


Complete Binary Tree
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled.
   #Properties
       - The maximum number of nodes in complete binary tree is 2h+1 - 1.
       - The minimum number of nodes in complete binary tree is 2h.
       - The minimum height of a complete binary tree is log2(n+1) - 1.
       - The maximum height of a complete binary tree is h = (n+1)/2



Full/Proper/Strict Binary Tree
The full binary tree is also known as a strict binary tree. 
A full binary tree is a binary tree in which all nodes have either zero or two children.
    #Properties 
      - The number of leaf nodes is equal to the number of internal nodes plus 1
      - The maximum number of nodes is the same as the number of nodes in the binary tree, i.e., n = 2^h+1 -1
      - The minimum number of nodes is  n = 2h+1
      - The minimum heght of a Strict binary tree is h = log2(n+1) - 1
      - The maximum height of a Strict binary tree is h = n-1/2
      - log2(n+1)-1 < h < (n-1)/2
      - (2h+1) < n < 2^h+1 -1

Perfect binary tree
A perfect binary tree is a full binary tree in which all internal nodes have two children and all leaves are at the same level.

Common Terminologies
Root :-  Root nodes is the topmost nodes of a tree
Leaf :-  Leaf nodes is the nodes which does not have any child nodes.
Parent Node :-  Parent node is the node which is connected to a child node.
Child Node :-  Child node is the node which is connected to a parent node.
Internal Node :-  Internal node is the node which is not the root node and not the leaf node.
Depth of a node :-  Depth of a node is the number of edges from that node to the root node.
Height of a node :- Height of a node is the number of edges between the nodes and its leaf nodes. 
Height of root node is the height of tree

Height of Tree :- Height of a tree is the height of its root node.
Level of tree :- Level of a tree is the number of edges from the root node to the node.

*/