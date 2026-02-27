/*
CONSTRUCT BINARY SEARCH TREE FROM PREORDER TRAVERSAL: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

 

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.                      */





class Solution {
public:
    int index;

    TreeNode* helper(vector<int> & preorder, int min_val, int max_val) {

        if(index >= preorder.size()) return NULL;

        int val = preorder[index];

        if(val <= min_val || val >= max_val) return NULL;

        TreeNode* node = new TreeNode(val);
        index++;

        node -> left = helper(preorder, min_val, val);
        node -> right = helper(preorder, val, max_val);

        return node;

        
    }

    // PREORDER TRAVERSAL: root -> left -> right
    // So, in the above helper function, we are first creating the node with the value at current index, then we are calling the left subtree with the range of (min_val, val) and right subtree with the range of (val, max_val). This is because in a BST, all values in the left subtree should be less than the node's value and all values in the right subtree should be greater than the node's value.
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MIN, INT_MAX);
    }
};