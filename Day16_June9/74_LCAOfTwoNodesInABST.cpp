/*
LCA OF TWO NODES IN A BST: https://www.naukri.com/code360/problems/lca-in-a-bst_981280

You are given a binary search tree of integers with N nodes. You are also given references to two nodes 'P' and 'Q' from this BST.



Your task is to find the lowest common ancestor(LCA) of these two given nodes.



The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants (where we allow a node to be a descendant of itself)



A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.


For example:
'P' = 1, 'Q' = 3
tree = 2 1 4 -1 -1 3 -1 -1 -1,

The BST corresponding will be- 

Here, we can clearly see that LCA of node 1 and node 3 is 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 5
2 1 3 -1 -1 -1 5 -1 -1
Sample Output 1:
3
Explanation for Sample 1:
The BST corresponding will be-

Here, we can clearly see that LCA of node 3 and node 5 is 3.
Sample Input 2 :
1 2
3 2 -1 1 -1 -1 -1
Sample Output 2:
2
Constraints:
1 <= 'N' <= 10^5
1 <= Data <= 10^6

Time Limit: 1sec                                     */






/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

************************************************************/

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root == NULL) return NULL;
    // Write your code here.
    if(root -> data > P -> data && root -> data > Q -> data) { // Here you should not mention, ">=", but only ">".
        return LCAinaBST(root -> left, P, Q);
    } else if(root -> data < P -> data && root -> data < Q -> data) {
        return LCAinaBST(root -> right, P, Q);
    } else {// i.e., one is in left of root and another one is in right of root
        return root;
    }
    // HERE, time - O(n), space - O(h) (h is height of the tree) as recurssion internally uses stack.


    // OR you, can either do the above by even, iterative method. Where time - O(n), space - O(1).
}